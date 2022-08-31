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
const int K=2e5+10;

string p[N],s[N];
map<string, int> mp;

vector<int> v[K];

int mx[N],mt[N];
int vis[N];

vector<int> order;
void dfs(int z){
	vis[z] = 1;
	for(int x:v[z]){
		if(vis[x] == 1){
			cout << "NO";
			exit(0);
		}
		if(vis[x] == 2){
			continue;
		}
		dfs(x);
	}
	order.pb(z);
	vis[z] = 2;
}


void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	
	rep(i,1,n+1){
		cin >> p[i];
		mp[p[i]] = i;
	}
	
	rep(i,1,m+1){
		bool found = 0;
		cin >> s[i] >> mt[i];
		rep(j,0,(1<<k)){
			string tmp;
			rep(z,0,k){
				if(j >> z & 1){
					tmp.pb(s[i][z]);
				}
				else{
					tmp.pb('_');
				}
			}
			if(mp.count(tmp)){
				// connect mp[tmp] and i
				int x = mp[tmp];
				if(x == mt[i]){
					found = 1;
					continue;
				}
				v[mt[i]].pb(x);
			}
		}
		if(found == 0){
			cout << "NO";
			return;
		}
	}
	
	rep(i,1,n+1){
		if(!vis[i]) dfs(i);
	}
	
	cout << "YES\n";
	reverse(all(order));
	for(int x:order){
		cout << x << " ";
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