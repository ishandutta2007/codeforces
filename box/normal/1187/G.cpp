// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
using ll=long long;
using pii=pair<int,int>;
const int MOD = 998244353;


namespace MCMF {
	const int maxEdge = 2000005;
	const int maxNode = 10003;
	const int inf     = 0x3f3f3f3f;//3f3f3f3fll;
	struct { int v, fl, co, x; } li[2*maxEdge];
	int st[maxNode], mincos[maxNode], prev[maxNode], ec; 
	void init() { ec = 0; memset(st, -1, sizeof st); }
	void ae(int u, int v, int fl, int co) {
		li[ec].v = v; li[ec].fl = fl; li[ec].co = co; li[ec].x = st[u];
		st[u] = ec; ec++;
		li[ec].v = u; li[ec].fl = 0; li[ec].co = -co; li[ec].x = st[v];
		st[v] = ec; ec++;
		// the reverse edge of edge e is e^1
	}
	int S, T;
	queue<int> bq; bool inq[maxNode];
	bool spfa() {
		memset(inq, 0, sizeof inq);
		memset(prev, -1, sizeof prev);
		memset(mincos, 0x3f, sizeof mincos);
		mincos[S] = 0; inq[S] = true; bq.push(S);
		while(!bq.empty()) {
			int u = bq.front(); bq.pop();
			inq[u] = false;
			for(int e = st[u]; e != -1; e = li[e].x) {
				if(!li[e].fl) continue;
				int v = li[e].v;
				if(mincos[u] + li[e].co < mincos[v]) {
					mincos[v] = mincos[u] + li[e].co;
					prev[v] = e;
					if(!inq[v]) { bq.push(v); inq[v] = true; }
				}
			}
		}
		return (prev[T] != -1);
	}
	pii run(int s, int t) {
		S = s; T = t;
		int flow = 0, cost = 0;
		while(spfa()) {
			int cfl = inf;
			for(int i = t; i != s; i = li[prev[i]^1].v)
				cfl = min(cfl, li[prev[i]].fl);
			for(int i = t; i != s; i = li[prev[i]^1].v) {
				li[prev[i]].fl -= cfl;
				li[prev[i]^1].fl += cfl;
				cost += li[prev[i]].co * cfl;
			}
			flow += cfl;
		}
		return {flow, cost};
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int src=0,snk=1;
    int n,m,k,c,d;cin>>n>>m>>k>>c>>d;
    auto get=[&](int node,int time){
    	if(node==1)return 1;
    	return time*n+node;
    };
    MCMF::init();
    rep(i,k){
    	int x;cin>>x;
    	MCMF::ae(src,get(x,0),1,0);
    }
    int mxt=n+k;
    iter(i,2,n+1)rep(t,mxt)MCMF::ae(get(i,t),get(i,t+1),1000000000,0);
    rep(i,m){
    	int x,y;cin>>x>>y;
    	if(x==1)swap(x,y);
    	if(y==1)rep(t,mxt)rep1(z,k)MCMF::ae(get(x,t),get(1,t+1),1,c*(t+1)+d*(z*z-(z-1)*(z-1)));
    	else rep(t,mxt)rep1(z,k){
    		MCMF::ae(get(x,t),get(y,t+1),1,d*(z*z-(z-1)*(z-1)));
    		MCMF::ae(get(y,t),get(x,t+1),1,d*(z*z-(z-1)*(z-1)));
    	}
    }
    cout<<MCMF::run(src,snk).second<<endl;
}