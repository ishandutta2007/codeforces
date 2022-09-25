#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
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
 
using namespace std;
 
const ll Mod=1000000007,Mod2=998244353;
int t,n,m,a,b,_a,_b,x,y,cnt,connect[200005][2];
pii p[200005];
ll ans[3];
vector<int> adj[2][200005],vec[3];
bool visited[200005];
queue<int> q;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m >> a >> b;
		a--,b--;
		rep(2) rep1(j,n) adj[i][j].clear();
		rep(m){
			cin >> x >> y;
			x--,y--;
			if(x!=a&&y!=a){
				adj[0][x].pb(y);
				adj[0][y].pb(x);
			}
			if(x!=b&&y!=b){
				adj[1][x].pb(y);
				adj[1][y].pb(x);
			}
		}	
		rep1(l,2){
			_a=(l==0?a:b);
			_b=(l==0?b:a);
			rep(n) visited[i]=false;
			vec[l].clear();
			rep(n){
				if(visited[i]||i==_a) continue;
				visited[i]=true;
				q.push(i);
				connect[i][l]=i;
				cnt=(i!=_b);
				while(!q.empty()){
					x=q.front();
					rep1(j,adj[l][x].size()){
						y=adj[l][x][j];
						if(visited[y]) continue;
						visited[y]=true;
						q.push(y);
						connect[y][l]=i;
						cnt+=(y!=_b);
					}
					q.pop();
				}
				vec[l].pb(cnt);
			}
		}
		connect[a][0]=connect[a][1]=-1;
		connect[b][0]=connect[b][1]=-1;
		rep(n) p[i]=mp(connect[i][0],connect[i][1]);
		sort(p,p+n);
		cnt=0;
		vec[2].clear();
		rep2(i,2,n){
			cnt++;
			if(i==n-1){
				vec[2].pb(cnt);
			}
			else if(p[i]!=p[i+1]){
				vec[2].pb(cnt);
				cnt=0;
			}
		}
		rep(3){
			ans[i]=0;
			rep1(j,vec[i].size()) ans[i]+=1ll*vec[i][j]*vec[i][j];
		}
		cout << (1ll*(n-2)*(n-2)-ans[0]+ans[2]-ans[1])/2 << '\n';
	}
	return 0;
}