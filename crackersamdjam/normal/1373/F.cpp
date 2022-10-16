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
const int MM = 1e6+5;

int t, n;
ll a[MM], b[MM], ta[MM], tb[MM];

bool go(int k, int f){
	for(int i = 0; i < n; i++){
		ta[i] = a[i];
		tb[i] = b[i];
	}
	ta[0] -= k;
	tb[n-1] -= k;
	if(k < 0 or ta[0] < 0 or tb[n-1] < 0)
		return 0;
	
	for(int i = 0; i < n-1; i++){
		tb[i] -= ta[i];
		ta[i] = 0;
		if(tb[i] < 0)
			return 0;
		ta[i+1] = max(ta[i+1]-tb[i], 0LL);
	}
	if(!f)
		return 1;
	return tb[n-1] >= ta[n-1];
}

int main(){
	scan(t);
	while(t--){
		scan(n);
		for(int i = 0; i < n; i++)
			scan(a[i]);
		for(int j = 0; j < n; j++)
			scan(b[j]);

		int l = 0, m, r = min(a[0], b[n-1]);
		while(l <= r){
			m = (l+r)/2;
			if(go(m, 0)) //works
				r = m-1;
			else
				l = m+1;
		}
		if(go(l, 1))
			puts("YES");
		else
			puts("NO");
	}
}