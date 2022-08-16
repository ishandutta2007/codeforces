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

int a[N];
int p[N];

int par[N][32];
vector<vector<int>> v, ids;

void solve(){
	int n;
	cin >> n;
	v.resize(n+1);
	ids.resize(n+1);
	rep(i,1,n+1){
		cin >> p[i];
		v[p[i]].pb(i);
		par[i][0] = p[i];
	}
	
	rep(j,1,32){
		rep(i,1,n+1){
			par[i][j] = par[par[i][j-1]][j-1];
		}
	}
	
	int cnt = 0;
	rep(i,1,n+1){
		cnt += max(0LL,sz(v[i]) - 1);
	}
	
	int mx = 0;
	rep(i,1,n+1){
		cin >> a[i];
		amax(mx,a[i]);
	}
	
	int moves = (mx - n) / cnt;
	
	rep(i,1,n+1){
		int dest = i;
		rep(j,0,32){
			if(moves >> j & 1){
				dest = par[dest][j];
			}
		}
		ids[a[dest]].pb(i);
	}
	
	set<int> avail;
	rep(i,1,n+1){
		if(sz(ids[i])){
			int choice = INF;
			for(int id:ids[i]){
				avail.insert(id);
				amin(choice, id);
			}
			a[choice] = i;
			avail.erase(choice);
		}
		else{
			int x = *avail.begin();
			avail.erase(x);
			a[x] = i;
		}
	}
	
	rep(i,1,n+1){
		cout << a[i] << " ";
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