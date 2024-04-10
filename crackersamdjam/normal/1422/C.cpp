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
const int MM = 1e5+5;
using ll = long long;
const ll mod = 1e9+7;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

char s[MM];
int n;
ll ans, a[MM], b[MM];

int main(){
	scanf("%s", s);
	n = strlen(s);

	for(int i = 0; i < n; i++){
		if(i) a[i] = a[i-1];
		a[i] += fpow(10, i, mod)*(i+1)%mod;
		a[i] %= mod;
	}
	for(int i = 1; i < n; i++){
		b[i] = (b[i-1]+i)%mod;
	}

	ll sum = 0, val = 0;
	for(int i = n-1; i >= 0; i--){
		int k = n-1-i;
		sum = (sum*10+val)%mod;
		val = (val*10+1)%mod;
		// print(i, k, s[i]-'0', fpow(10, k, mod)*b[i], sum);
		ans += (s[i]-'0')*fpow(10, k, mod)*(b[i])%mod;
		ans += (s[i]-'0')*sum%mod;
		ans %= mod;
	}
	ans %= mod;
	if(ans < 0)
		ans += mod;
	print(ans);
}