#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using T = int;
const int MM = 3e5+5;

int n, q, a[MM], b[MM], bit[MM], ans[MM];
vector<pair<int, int>> v[MM];

void add(int i){
	for(i = n+3-i; i < MM; i += i&-i)
		bit[i]++;
}

int qu(int i){
	int ret = 0;
	for(i = n+3-i; i; i -= i&-i)
		ret += bit[i];
	return ret;
}

int main(){
	scan(n, q);
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		a[i] = i-a[i];
	}
	for(int i = 0; i < q; i++){
		int l, r;
		scan(l, r);
		l++, r = n-r;
		v[r].emplace_back(l, i);
	}
	for(int i = 1; i <= n; i++){
		if(a[i] >= 0){
			int l = 0, m, r = i;
			while(l <= r){
				m = (l+r)/2;
				if(qu(m) >= a[i])
					l = m+1;
				else
					r = m-1;
			}
			add(r);
			b[i] = r;
		}
		for(auto j: v[i])
			ans[j.second] = qu(j.first);
	}
	for(int i = 0; i < q; i++)
		print(ans[i]);
}