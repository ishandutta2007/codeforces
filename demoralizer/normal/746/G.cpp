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

const int N=2e5+5;

int a[N];

int mx[N],mn[N];
vector<int> v[N] , ver[N];

void solve(){
	int n,t,k;
	cin>>n>>t>>k;
	rep(i,1,t+1){
		cin>>a[i];
	}
	
	int cnt = 1;
	rep(i,1,t+1){
		rep(j,0,a[i]){
			ver[i].pb(++cnt);
		}
	}
	
	mx[t] = mn[t] = a[t];
	
	for(int i = t - 1; i > 0; i--){
		mx[i] = mx[i+1] + a[i] - 1;
		
		rep(j,0,min(a[i],a[i+1])){
			v[ver[i][j]].pb(ver[i+1][j]);
		}
		rep(j,a[i],a[i+1]){
			v[ver[i][0]].pb(ver[i+1][j]);
		}
		
		mn[i] = mn[i+1];
		if(a[i] > a[i+1]) mn[i] += a[i] - a[i+1];
	}
	
	for(int x:ver[1]){
		v[1].pb(x);
	}
	
	if(mn[1] > k || mx[1] < k){
		cout<<-1;
		return;
	}
	int ans = mn[1];
	cout<<n<<"\n";
	if(ans < k){
		rep(i,1,t){
			rep(j,1,sz(ver[i])){
				if(v[ver[i][j]].empty())break;
				v[ver[i][0]].pb(v[ver[i][j]].back());
				assert(sz(v[ver[i][j]]));
				v[ver[i][j]].ppb();
				ans++;
				if(ans == k) break;
			}
			if(ans == k) break;
		}
	}
	
	rep(i,1,n+1){
		for(int x:v[i]){
			cout<<i<<" "<<x<<"\n";
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