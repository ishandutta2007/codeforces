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

const int N=3005;

int vis[N];
int dis[N][N];

vector<int> v[N];

void bfs(int x){
	queue<int> q;
	q.push(x);
	mem0(vis);
	vis[x] = 1;
	
	while(sz(q)){
		int z = q.front();
		q.pop();
		for(int y:v[z]){
			if(!vis[y]){
				vis[y] = 1;
				dis[x][y] = dis[x][z] + 1;
				q.push(y);
			}
		}
	}
	
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	rep(i,1,n+1){
		bfs(i);
	}
	int s1,t1,l1,s2,t2,l2;
	cin>>s1>>t1>>l1>>s2>>t2>>l2;
	
	if(dis[s1][t1] > l1 || dis[s2][t2] > l2){
		cout<<-1;
		return;
	}
	
	int ans = dis[s1][t1] + dis[s2][t2];
	
	rep(i,1,n+1){
		rep(j,1,n+1){
			int d1 = dis[s1][i] + dis[i][j] + dis[j][t1];
			int d2 = dis[s2][i] + dis[i][j] + dis[j][t2];
			int d = dis[s1][i] + dis[s2][i] + dis[i][j] + dis[j][t1] + dis[j][t2];
			if(d1 <= l1 && d2 <= l2){
				amin(ans,d);
			}
		}
	}
	
	swap(s2,t2);
	
	rep(i,1,n+1){
		rep(j,1,n+1){
			int d1 = dis[s1][i] + dis[i][j] + dis[j][t1];
			int d2 = dis[s2][i] + dis[i][j] + dis[j][t2];
			int d = dis[s1][i] + dis[s2][i] + dis[i][j] + dis[j][t1] + dis[j][t2];
			if(d1 <= l1 && d2 <= l2){
				amin(ans,d);
			}
		}
	}
	
	cout << m - ans;
	
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