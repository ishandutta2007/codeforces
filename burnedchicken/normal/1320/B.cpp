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
#define debug(a) print2(#a,a)

using namespace std;

const ll Mod=1000000007,Mod2=998244353;
const ll MOD=Mod;

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
int n,m,u,v,k,p[maxn],dist[maxn],ans1=0,ans2=0;
vector<int> adj[maxn],adj1[maxn];
queue<int> q;
bool visited[maxn]={false},ok;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	rep(m){
		cin >> u >> v;
		u--,v--;
		adj[v].pb(u);
		adj1[u].pb(v);
	}
	cin >> k;
	rep(k) cin >> p[i];
	rep(k) p[i]--;
	dist[p[k-1]]=0;
	q.push(p[k-1]);
	visited[p[k-1]]=true;
	while(!q.empty()){
		u=q.front();
		rep(sz(adj[u])){
			v=adj[u][i];
			if(visited[v]) continue;
			dist[v]=dist[u]+1;
			q.push(v);
			visited[v]=true;
		}
		q.pop();
	}
	rep(k-1){
		if(dist[p[i]]<dist[p[i+1]]+1) ans1++;
		ok=true;
		rep1(j,sz(adj1[p[i]])){
			if(adj1[p[i]][j]!=p[i+1]&&dist[p[i]]==dist[adj1[p[i]][j]]+1){
				ok=false;
				break;
			}
		}
		if(!ok) ans2++;
	}
	print2(ans1,ans2);
	return 0;
}