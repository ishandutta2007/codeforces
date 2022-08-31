#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e6+5;

int m[N];
int lp[N];

void sieve(){
	m[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!lp[i]) for (int j = i; j < N; j += i)
            if (!lp[j]) lp[j] = i;
        m[i] = [](int x) {
            int cnt = 0;
            while (x > 1) {
                int k = 0, d = lp[x];
                while (x % d == 0) {
                    x /= d;
                    ++k;
                    if (k > 1) return 0;
                }
                ++cnt;
            }
            if (cnt & 1) return -1;
            return 1;
        }(i);
    }
}

int pw(int a,int p=M-2,int MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = 1ll * a * result % MOD;
		a = 1ll * a * a % MOD;
		p >>= 1;
	}
	return result;
}

int a[N];
int f[N];

int ans[N];

void solve(){
	sieve();
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> a[i];
		int x = a[i];
		for(int i = 1; i * i <= x; i++){
			if(x % i == 0){
				f[i]++;
				if(i * i != x){
					f[x / i]++;
				}
			}
		}
	}
	
	mem1(m);
	// cout << m[6] << "\n";
	
	int pr = 0;
	
	for(int i = N - 3; i >= 2; i--){
		if(!f[i]) continue;
		ans[i] += 1ll * f[i] * pw(2,f[i] - 1) % M;
		
		for(int j = 2 * i; j < N; j += i){
			ans[i] = (ans[i] + 1ll * M + 1ll * (m[j / i]) * ans[j] % M) % M;
		}
		
		pr += 1ll * i * ans[i] % M;
		pr %= M;
	}
	
	cout << pr;
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}