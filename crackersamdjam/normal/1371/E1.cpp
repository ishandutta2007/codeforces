#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2005;

int n, p, a[MM];
vector<int> v;

int main(){
	scan(n, p);
	for(int i = 0; i < n; i++)
		scan(a[i]);
	sort(a, a+n);
	for(int x = 1; x <= 2000; x++){
		bool b = 1;
		for(int i = 0; i < n; i++)
			if(a[i] > i+x)
				b = 0;
		if(!b) continue;

		int l = 0;
		while(l < n and a[l] == l+x)
			l++;

		int r = n-1;
		while(r >= 0 and a[r] == r+x)
			r--;

		//all in between are fixed
		int in = r-(l-1);

		if(in <= 0){
			//exactly one way
			v.emplace_back(x);
			continue;
		}

		ll cnt = 1;
		for(int i = r; i >= l; i--){
			//how many places
			int add = min(i+x-a[i]+1, i+1);
			// print(i, a[i], add);
			cnt *= add;
			cnt %= p;
		}

		if(cnt){
			v.emplace_back(x);
		}

		// print(x, cnt, l, r);
	}
	if(v.size())
		assert((int)v.size() == v.back()-v.front()+1);

	print(v.size());
	for(int i: v)
		printf("%d ", i);
}