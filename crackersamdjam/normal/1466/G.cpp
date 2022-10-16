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
using ll = long long;
constexpr int MM = 2e6+5, NN = 1e5+5, MS = 5e6+5;
constexpr ll mod = 1e9+7;

ll mmod(ll a){
	while(a >= mod)
		a -= mod;
	while(a < 0)
		a += mod;
	return a;
}

int pi[MS];

// pi[i] = length of longest proper prefix equal to suffix of s ending at i ( s.substr(0, i+1) )
// count # of time s is in t
int kmp(string s, string t){
	int ret = 0, len = (int)size(s);
	s = s+"#"+t;
	pi[0] = 0;
	for(int i = 1, j = 0; i < (int)size(s); i++){
		while(j and s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;

		if(pi[i] == len)
			ret++;
	}
	return ret;
}

int n, q;
string s[30], t;
ll sum[NN][30];
ll f[NN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>q;
	cin>>s[0]>>t;
	for(int i = 1; i < 30; i++){
		s[i] = s[i-1]+t[i-1]+s[i-1];
		if(size(s[i]) > MM) break;
	}
	f[0] = 1;
	for(int i = 1; i <= n; i++){
		f[i] = f[i-1]*2%mod;
		for(int j = 0; j <= 26; j++)
			sum[i][j] = mmod(sum[i-1][j]*2);
		
		sum[i][t[i-1]-'a'] = mmod(sum[i][t[i-1]-'a'] + 1);
	}

	int k; string w;
	while(q--){
		cin>>k>>w;

		int i = 0;
		while(size(s[i]) < size(w))
			i++;

		if(i > k){
			cout<<"0\n";
			continue;
		}

		//find # of matches
		ll st = kmp(w, s[i]);
		ll ans = st*f[k-i]%mod;

		//calculate number of matches each time I increase
		for(char c = 'a'; c <= 'z'; c++){
			ll val = mmod(kmp(w, s[i]+c+s[i]) - 2*st);
			ll cnt = mmod(sum[k][c-'a'] - sum[i][c-'a']*f[k-i]%mod);
			//subtract taken ones
			ans = mmod(ans + val*cnt%mod);
		}

		cout<<ans<<'\n';
	}
}