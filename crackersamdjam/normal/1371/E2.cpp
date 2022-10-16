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
const int MM = 1e5+5;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

int n, p, a[MM];
vector<int> v;

int main(){
	scan(n, p);
	for(int i = 0; i < n; i++)
		scan(a[i]);
	sort(a, a+n);
	//what minimum req is
	int low = 1;
	for(int i = 0; i < n; i++)
		low = max(low, a[i]-i);

	int hi = 1e9;
	for(int i = p-1; i < n; i++){
		//how many needed until can *= p
		// int add = min(i+x-a[i]+1, i+1);
		// p = i+x-a[i]+1;
		// p-i+a[i]-1 = x;
		int x = p-i+a[i]-1;
		// print(i, x, x+i, a[i], add);
		hi = min(hi, x);
	}
	for(int i = low; i < hi; i++)
		v.emplace_back(i);

	print(v.size());
	for(int i: v)
		printf("%d ", i);

	// print(low, hi);
}