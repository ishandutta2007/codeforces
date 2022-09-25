#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define printvec(a) rep(a.size()) print0(a[i])

using namespace std;

const ll Mod=1000000007,Mod2=998244353;
const ll MOD=Mod;

ll Pow(ll a, ll b){
	if(!b) return 1;
	ll z=Pow(a*a%MOD,b>>1);
	return (b&1?z*a%MOD:z);
}
vector<ll> prime_factors(ll n){
	ll m=n;
	vector<ll> ret;
	rep2(i,2,n){
		while(m%i==0){
			if(ret.empty()) ret.pb(i);
			else if(ret.back()!=i) ret.pb(i);
			m/=i;
		}
		if(m==1||1ll*i*i>n) break;
	}
	if(m>1) ret.pb(m);
	return ret;
}
ll euler(ll n){
	vector<ll> vec=prime_factors(n);
	ll ret=n;
	rep(vec.size()) ret=ret/vec[i]*(vec[i]-1);
	return ret;
}
ll inverse(ll n){return Pow(n,MOD-2);}
ll fact(ll n){return (n?fact(n-1)*n%MOD:1);}
ll C(ll n, ll m){
	if(n<m) return 0;
	if(m==0) return 1;
	return C(n,m-1)*(n-m+1)%MOD*inverse(m)%MOD;
}
ll dgts2(ll n){return (n?dgts2(n>>1)+1:0);}
ll v2(ll n){return ((n&1)?0:v2(n>>1)+1);}

//i_am_noob
int n,m,e[5005][2],x[5005],y[5005],z[5005],father[5005],root,tmp,tmp2;
vector<pii> adj[5005];
string str;
bool visited[5005],ok;

void dfs(int u){
	visited[u]=true;
	if(u==root) father[u]=-1;
	rep(adj[u].size()){
		tmp=adj[u][i].first;
		if(!visited[tmp]) dfs(tmp);
		else father[u]=tmp;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n-1){
		cin >> e[i][0] >> e[i][1];
		e[i][0]--,e[i][1]--;
		adj[e[i][0]].pb(mp(e[i][1],1));
		adj[e[i][1]].pb(mp(e[i][0],1));
	}
	cin >> m;
	rep(m){
		cin >> x[i] >> y[i] >> z[i];
		x[i]--,y[i]--;
		rep1(j,n) visited[j]=false;
		root=x[i];
		dfs(x[i]);
		tmp=y[i];
		//print2("Round",i);
		while(tmp!=x[i]){
			rep1(j,adj[tmp].size()){
				tmp2=adj[tmp][j].first;
				if(tmp2==father[tmp]){
					adj[tmp][j].second=max(adj[tmp][j].second,z[i]);
					//print4("Assign",tmp,father[tmp],adj[tmp][j].second);
					break;
				}
			}
			rep1(j,adj[father[tmp]].size()){
				tmp2=adj[father[tmp]][j].first;
				if(tmp2==tmp){
					adj[father[tmp]][j].second=max(adj[father[tmp]][j].second,z[i]);
					break;
				}
			}
			tmp=father[tmp];
		}
	}
	rep(m){
		rep1(j,n) visited[j]=false;
		root=x[i];
		dfs(x[i]);
		tmp=y[i];
		ok=false;
		while(tmp!=x[i]){
			rep1(j,adj[tmp].size()){
				tmp2=adj[tmp][j].first;
				if(tmp2==father[tmp]){
					if(adj[tmp][j].second==z[i]) ok=true;
					break;
				}
			}
			rep1(j,adj[father[tmp]].size()){
				tmp2=adj[father[tmp]][j].first;
				if(tmp2==tmp){
					if(adj[father[tmp]][j].second==z[i]) ok=true;
					break;
				}
			}
			tmp=father[tmp];
		}
		if(!ok){
			print1(-1);
			return 0;
		}
	}
	rep(n-1){
		rep1(j,adj[e[i][0]].size()){
			if(adj[e[i][0]][j].first==e[i][1]){
				print0(adj[e[i][0]][j].second);
				break;
			}
		}
	}
	cout << '\n';
	return 0;
}