#include "bits/stdc++.h"
using namespace std;
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

const int N=2e5+5;

int a[N];
vector<int> v[N];
int vis[N];
vector<int> d[N];

vector <int> prime;
bool is_composite[N];
int m[N];

#define SIEVE
void sieve(){
	int n = N;
	fill (is_composite, is_composite + n, false);
	m[1] = 1;
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back (i);
			m[i] = -1;					//i is prime
		}
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				m[i * prime[j]] = 0;	//prime[j] divides i
				break;
			} else {
				m[i * prime[j]] = m[i] * m[prime[j]];	//prime[j] does not divide i
			}
		}
	}
	
}

int dfs(int z,int p,int val){
	int ans = 1;
	vis[z] = 1;
	for(int x:v[z]){
		if(x == p || a[x] % val) continue;
		ans += dfs(x,z,val);
	}
	return ans;
}

long long cnt[N];

void solve(){
	int n;
	cin >> n;
	rep(i,1,n+1){
		cin >> a[i];
	}
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	rep(i,1,n+1){
		int tmp = a[i];
		for(int j = 1; j * j <= tmp; j++){
			if(tmp % j == 0){
				int k = j;
				d[k].pb(i);
				k = tmp / j;
				if(k != j){
					d[k].pb(i);
				}
			}
		}
	}
	
	rep(val,1,N){
		for(int i:d[val]){
			if(vis[i]){
				continue;
			}
			int tmp = dfs(i,0,val);
			cnt[val] += tmp * 1ll * (tmp + 1) / 2;
		}
		for(int i:d[val]){
			vis[i] = 0;
		}
	}
	
	rep(i,1,N){
		// cout << i << " " << cnt[i] << "\n";
		long long ans = 0;
		for(int j = 1; i * j < N; j++){
			ans += cnt[i * j] * m[j];
		}
		if(ans){
			cout << i << " " << ans << "\n";
		}
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