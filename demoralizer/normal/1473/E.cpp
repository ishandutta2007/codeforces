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

struct cmp
{
	bool operator() (pair<int, pii> a, pair<int, pii> b){
		return a.fr > b.fr;
	}
};

vector<pii> v[N];
// f1 = skip, f2 = repick
int vis[N][4]; // vertex, 2*f1 + f2
int dist[N][4]; // vertex, 2*f1 + f2

void solve(){
	int n,m;
	cin >> n >> m;
	
	rep(i,0,m){
		int x,y,w;
		cin >> x >> y >> w;
		v[x].pb({y,w});
		v[y].pb({x,w});
	}
	
	// set<pair<int, pii>> s; // {dist,{vertex,2*f1+f2}}
	
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, cmp> q;
	
	// s.insert({0,{1,0}});
	q.push({0,{1,0}});
	
	while(!q.empty()){
		auto tmp = q.top();
		q.pop();
		pii cur = tmp.sc;
		int d = tmp.fr;
		
		if(vis[cur.fr][cur.sc]){
			continue;
		}
		vis[cur.fr][cur.sc] = 1;
		dist[cur.fr][cur.sc] = d;
		
		int f1 = cur.sc / 2, f2 = cur.sc % 2;
		
		rep(f,0,4){
			if(f / 2 < f1 || f % 2 < f2){
				continue;
			}
			for(pii x:v[cur.fr]){
				// {x.fr,f}
				q.push({d + x.sc * (1 + (f % 2 > f2) - (f / 2 > f1)),{x.fr,f}});
			}
		}
		
	}
	
	for(int i = 2; i <= n; i++){
		cout << dist[i][3] << " ";
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