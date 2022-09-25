#include <bits/stdc++.h>
 
#define ll long long
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

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t,k,x;
	cin >> t;
	queue<int> q;
	while(t--){
		cin >> k;
		int e[2*k-1][3];
		rep(2*k-1) rep1(j,3) cin >> e[i][j];
		rep(2*k-1) e[i][0]--,e[i][1]--;
		vector<int> adj[2*k];
		rep(2*k) adj[i].clear();
		rep(2*k-1){
			adj[e[i][0]].pb(e[i][1]);
			adj[e[i][1]].pb(e[i][0]);
		}
		int depth[2*k],pre[2*k];
		bool visited[2*k];
		rep(2*k) visited[i]=false;
		q.push(0);
		depth[0]=0;
		pre[0]=-1;
		visited[0]=true;
		while(!q.empty()){
			x=q.front();
			rep(adj[x].size()){
				if(visited[adj[x][i]]) continue;
				q.push(adj[x][i]);
				depth[adj[x][i]]=depth[x]+1;
				pre[adj[x][i]]=x;
				visited[adj[x][i]]=true;
			}
			q.pop();
		}
		rep(2*k-1) if(depth[e[i][0]]>depth[e[i][1]]) swap(e[i][0],e[i][1]);
		int child[2*k];
		ll num[2*k];
		rep(2*k) child[i]=0;
		rep2(i,1,2*k) child[pre[i]]++;
		rep(2*k) num[i]=0;
		rep(2*k) if(!child[i]) q.push(i);
		while(!q.empty()){
			x=q.front();
			if(x>0) child[pre[x]]--;
			num[x]++;
			if(x>0) num[pre[x]]+=num[x];
			if(x>0) if(!child[pre[x]]) q.push(pre[x]);
			q.pop();
		}
		ll ans1=0,ans2=0;
		rep(2*k-1){
			ans1+=(num[e[i][1]]%2)*e[i][2];
			ans2+=min(num[e[i][1]],2*k-num[e[i][1]])*e[i][2];
		}
		cout << ans1 << ' ' << ans2 << "\n";
	}
	return 0;
}