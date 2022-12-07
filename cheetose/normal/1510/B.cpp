#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#define tout cerr
#else
#define TEST(n) ((void)0)
#define tout cin
#endif

using namespace std;

struct MCMF
{
	struct Edge
	{
		int to, cap, cost, rev;
		Edge(int to, int cap, int cost) : to(to), cap(cap), cost(cost) {}
	};
	vector<Edge> G[3333];
	int N, src, sink, work[3333], dist[3333];
	bool chk[3333];
	MCMF(int N, int src, int sink) : N(N), src(src), sink(sink) {}
	void add_edge(int f, int t, int cap, int cost) {
		G[f].emplace_back(t,cap,cost);
		G[t].emplace_back(f,0,-cost);
		G[f].back().rev=G[t].size()-1;
		G[t].back().rev=G[f].size()-1;
	}
	void add_edge_from_source(int t, int cap, int cost) {add_edge(src,t,cap,cost);}
	void add_edge_to_sink(int f, int cap, int cost) {add_edge(f,sink,cap,cost);}
	void init() {
		int temp;
		queue<int> Q;
		priority_queue<pair<int,int>> PQ;
		memset(dist,0x7f,sizeof(dist));
		memset(chk,0,sizeof(chk));
		dist[src]=0; Q.push(src);
		while(!Q.empty()) {
			int c=Q.front();
			Q.pop();
			chk[c]=false;
			for(auto &e: G[c]) if(e.cap>0 && dist[e.to]>dist[c]+e.cost) {
				dist[e.to]=dist[c]+e.cost;
				if(!chk[e.to]) {
					chk[e.to]=true;
					Q.push(e.to);
				}
			}
		}
		temp=dist[sink]-dist[src];
		for(int i=0;i<N;i++) for(auto &e: G[i]) e.cost+=dist[i]-dist[e.to];
		memset(dist,0x7f,sizeof(dist));
		dist[src]=temp; PQ.emplace(0,src);
		while(!PQ.empty()) {
			auto[t,c]=PQ.top();
			PQ.pop();
			for(auto &e: G[c]) if(e.cap>0 && dist[e.to]>dist[c]+e.cost) {
				dist[e.to]=dist[c]+e.cost;
				PQ.emplace(-dist[e.to],e.to);
			}
		}
	}
	int dfs(int c, int MF=0x7fffffff)
	{
		int flow;
		chk[c]=true;
		if(c==sink) return MF;
		for(int &i=work[c];i<G[c].size();i++) {
			auto &e=G[c][i];
			if(!chk[e.to] && e.cap>0 && dist[e.to]==dist[c]+e.cost && (flow=dfs(e.to,min(e.cap,MF)))) {
				e.cap-=flow;
				G[e.to][e.rev].cap+=flow;
				return flow;
			}
		}
		return 0;
	}
	int flow() {
		int ret=0; init();
		for(;;) {
			int M=0x7fffffff;
			memset(chk,0,sizeof(chk));
			memset(work,0,sizeof(work));
			while(int temp=dfs(src)) {
				ret+=dist[sink]*temp;
				memset(chk,0,sizeof(chk));
			}
			for(int i=0;i<N;i++) if(chk[i]) for(auto &e: G[i]) if(e.cap>0 && ! chk[e.to]) M=min(M,dist[i]+e.cost-dist[e.to]);
			if(M==0x7fffffff) break;
			for(int i=0;i<N;i++) if(!chk[i]) dist[i]+=M;
		}
		return ret;
	}
};

vector<int> V, ans;
int R[1024], cnt[1024];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt","r",stdin));
	TEST(freopen("output.txt","w",stdout));
	TEST(freopen("debug.txt","w",stderr));
	int D, N, res;
	queue<int> Q;
	string s;
	cin>>D>>N;
	MCMF mf(2*N+2,2*N,2*N+1);
	memset(R,-1,sizeof(R));
	memset(cnt,-1,sizeof(cnt));
	for(int i=0;i<N;i++) {
		int v=0;
		cin>>s; reverse(s.begin(),s.end());
		for(auto c: s) v=2*v+c-'0';
		V.push_back(v); cnt[v]=0;
	}
	sort(V.begin(),V.end());
	for(int i=0;i<N;i++) {
		mf.add_edge_from_source(i,1,0);
		mf.add_edge_to_sink(i,1,0);
		mf.add_edge(i,i+N,1,-1000000);
		mf.add_edge_to_sink(i+N,1,__builtin_popcount(V[i])+1);
		for(int j=i+1;j<N;j++) if((V[i]&V[j])==V[i]) mf.add_edge(i+N,j,1,0);
	}
	res=(1000000+mf.flow()%1000000)%1000000-1;
	for(int i=0;i<N;i++) {
		for(auto &e: mf.G[i+N]) if(e.cap==0 && e.to<N && e.to!=i) {
			R[V[i]]=V[e.to];
			cnt[V[e.to]]++;
		}
	}
	for(int i=(1<<D);--i;) if(cnt[i]==0) Q.push(i);
	while(!Q.empty()) {
		int c=Q.front();
		Q.pop();
		for(int i=0;i<D;i++) if(c&(1<<i)) ans.push_back(i);
		while(R[c]!=-1) {
			for(int i=0;i<D;i++) if((c^R[c])&(1<<i)) ans.push_back(i);
			c=R[c];
		}
		if(Q.size()) ans.push_back(-1);
	}
	assert(ans.size()==res);
	cout<<ans.size()<<'\n';
	for(auto a: ans) {
		if(a==-1) cout<<"R ";
		else cout<<a<<' ';
	}
	return 0;
}