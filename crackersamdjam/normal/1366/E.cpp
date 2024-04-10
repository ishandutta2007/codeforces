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
using ll = long long;
const ll mod = 998244353;
const int MM = 2e5+5;

void addmod(ll &a, ll b){
	a += b;
	if(a >= mod)
		a -= mod;
}

int n, m, a[MM], b[MM], suf[MM];;
ll ans = 1;
map<int, int> at;

int main(){
	scan(n, m);
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		at[a[i]] = i;
	}
	suf[n] = a[n];
	for(int i = n-1; i; i--){
		suf[i] = min(a[i], suf[i+1]);
	}
 	for(int i = 1; i <= m; i++){
		scan(b[i]);
	}

	int last = n;
	int l = n;
	for(int i = m; i; i--){
		while(l and suf[l] >= b[i])
			l--;
		//(l, r]
		int r = at[b[i]];
		if(!at[b[i]] or l >= r)
			ans = 0;

		// print(i, l, r, last);
		if(i != 1)
			ans = ans*(r-l)%mod;
		last = l;
	}
	if(suf[1] < b[1])
		ans = 0;

	print(ans);
}