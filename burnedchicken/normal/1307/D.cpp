#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=(int(a)); i--)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define printvec(a) rep(a.size()) print0(a[i])
#define debug(a) print2(#a,a)
 
using namespace std;

const ll Mod=1000000007,Mod2=998244353;
const ll MOD=Mod2;
 
inline ll add(ll a, ll b){return (a+b>=MOD?a+b-MOD:a+b);}
inline ll sub(ll a, ll b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
ll Pow(ll a, ll b){
	if(!b) return 1;
	ll tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline ll inverse(ll n){return Pow(n,MOD-2);}
ll dgts2(ll n){return (n?dgts2(n>>1)+1:0);}
ll dgts(ll n, ll k){return (n?dgts(n/k,k)+1:0);}
inline ll v2(ll n){return __builtin_ctzll(n);}
 
const int maxn=200005;
//i_am_noob
int n,m,k,a[maxn],u,v,father[maxn],dist[2][maxn],ans=0;
vector<int> adj[maxn];
queue<int> q;
bool visited[maxn];
vector<pii> vec;
set<int> st;

bool comp(pii p1, pii p2){
	return p1.first-p1.second>p2.first-p2.second;
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m >> k;
	rep(k) cin >> a[i];
	rep(k) a[i]--;
	rep(m){
		cin >> u >> v;
		u--,v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep1(l,2){
	
	rep(n) visited[i]=false;
	u=l?n-1:0;
	q.push(u);
	visited[u]=true;
	dist[l][u]=0;
	while(!q.empty()){
		u=q.front();
		rep(adj[u].size()){
			v=adj[u][i];
			if(visited[v]) continue;
			q.push(v);
			visited[v]=true;
			dist[l][v]=dist[l][u]+1;
		}
		q.pop();
	}
	
	}
	rep(k) vec.pb(mp(dist[0][a[i]],dist[1][a[i]]));
	sort(all(vec),comp);
	rep(k){
		if(!st.empty()) ans=max(ans,vec[i].first+*(--st.end())+1);
		st.insert(vec[i].second);
	}
	ans=min(ans,dist[0][n-1]);
	print1(ans);
	return 0;
}