#include<bits/stdc++.h>
#define int long long
const int N=1000005,inf=1e9+7;
using namespace std;

struct mf_graph{
	static const int inf=2e9;
	struct edge{
		int to,nx,w;
	};vector<edge> e;
	#define fore(k) for(int i=hd[k];i;i=e[i].nx)
	#define fory(k) for(int&i=hy[k];i;i=e[i].nx)
	#define _to e[i].to
	vector<int> hd,dep,hy;int S,n;
	mf_graph(int sz){
		S=1,n=sz+1;
		hd.resize(n);dep.resize(n);
		e.push_back({0,0,0});
		e.push_back({0,0,0});
	}
	void add_edge(int fr,int to,int w){
		e.push_back({to,hd[fr],w}),hd[fr]=++S;
		e.push_back({fr,hd[to],0}),hd[to]=++S;
	}
	bool bfs(int s,int t){
		fill(dep.begin(),dep.end(),-1);
		dep[s]=0;hy=hd;
		queue<int> q;q.push(s);
		while(q.size()){
			int nw=q.front();q.pop();
			fore(nw)if(e[i].w&&!~dep[_to]){
				dep[_to]=dep[nw]+1;
				q.push(_to);
			}
		}
		return ~dep[t];
	}
	int dfs(int k,int fl,int t){
		if(k==t)return fl;
		int rst=fl,f=0;
		fory(k)if(dep[_to]==dep[k]+1&&e[i].w){
			int nw=dfs(_to,min(e[i].w,rst),t);
			if(!nw)dep[_to]=0;
			rst-=nw,f+=nw,e[i].w-=nw,e[i^1].w+=nw;
			if(!rst)break ;
		}
		return f;
	}
	int flow(int s,int t){
		int ans=0;
		while(bfs(s,t))
			ans+=dfs(s,inf,t);
		return ans;
	}
};

int n,m,g;
int a[N],v[N],w[N];
int ans;

void solve(){
	cin>>n>>m>>g;
	int s=0,t=n+m+1;
	mf_graph e(n+m+2);
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
		if(v[i])e.add_edge(s,i,w[i]);
		else e.add_edge(i,t,w[i]);
	for(int i=1;i<=m;i++){
		int w,k,x;cin>>k>>w>>x;
		for(int j=1;j<=x;j++){
			int y;cin>>y;
			if(k)e.add_edge(n+i,y,inf);
			else e.add_edge(y,n+i,inf);
		}
		int p;cin>>p;w+=g*p;ans-=g*p;ans+=w;
		if(!k)e.add_edge(i+n,t,w);
		else e.add_edge(s,i+n,w);
	}
	cout<<ans-e.flow(s,t);
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}