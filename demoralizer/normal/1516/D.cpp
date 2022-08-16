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

const int N=1e5+5;

#define SIEVE
int primes[N];
vector<int> pr;
vector<int> fac[N];
void sieve(){
	for(int i=2;i<N;i++){
		if(primes[i]==0){
			pr.pb(i);
			for(int j=i;j<N;j+=i){
				primes[j]=1;
				fac[j].pb(i);
			}
		}
		primes[i]^=1;
	}
}

int last[N];

int v[N];

const int H = 18;
int par[N][H];

void solve(){
	int n,q;
	cin >> n >> q;
	vector<int> a(n+1);
	vector<vector<int>> p(n+1);
	rep(i,1,n+1){
		cin >> a[i];
		p[i] = fac[a[i]];
	}
	
	rep(i,1,n+1){
		int pos = v[i - 1];
		for(int x:p[i]){
			amax(pos,last[x]);
			last[x] = i;
		}
		v[i] = pos;
		// cout << pos << " ";
		par[i][0] = pos;
		rep(j,1,H){
			par[i][j] = par[par[i][j-1]][j-1];
		}
	}
	// cout << "\n";
	
	while(q--){
		int l,r;
		cin >> l >> r;
		if(par[r][0] < l){
			cout << 1 << "\n";
			continue;
		}
		int ans = 0;
		for(int i = H-1; i >= 0; i--){
			if(par[r][i] >= l){
				ans += (1 << i);
				r = par[r][i];
			}
		}
		ans++;
		cout << ans << "\n";
	}
	
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