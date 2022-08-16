#include <bits/stdc++.h>
using namespace std;

// Push relabel in O(V^2 E^0.5) with gap heuristic
// Is quite fast
// Uses lowest label for matching problems
template<typename flow_t = long long>
struct PushRelabel {
    struct Edge {
        int to, rev;
        flow_t f, c;
    };
    vector<vector<Edge> > g;
    vector<flow_t> ec;
    vector<Edge*> cur;
    vector<vector<int> > hs;
    vector<int> H;
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}
    int add_edge(int s, int t, flow_t cap, flow_t rcap=0) {
        if (s == t) return -1;
        Edge a = {t, (int)g[t].size(), 0, cap};
        Edge b = {s, (int)g[s].size(), 0, rcap};
        g[s].push_back(a);
        g[t].push_back(b);
        return b.rev;
    }
    void add_flow(Edge& e, flow_t f) {
        Edge &back = g[e.to][e.rev];
        if (!ec[e.to] && f)
            hs[H[e.to]].push_back(e.to);
        e.f += f; e.c -= f;
        ec[e.to] += f;
        back.f -= f; back.c += f;
        ec[back.to] -= f;
    }
    flow_t max_flow(int s, int t) {
        int v = g.size();
        H[s] = v;
        ec[t] = 1;
        vector<int> co(2*v);
        co[0] = v-1;
        for(int i=0;i<v;++i) cur[i] = g[i].data();
        for(auto &e:g[s]) add_flow(e, e.c);
        if(hs[0].size())
        for (int hi = 0;hi<2*v;) {
            int u = hs[hi].back();
            hs[hi].pop_back();
            while (ec[u] > 0) // discharge u
                if (cur[u] == g[u].data() + g[u].size()) {
                    int hii = H[u];
                    H[u] = 1e9;
                    for(auto &e:g[u])
                        if (e.c && H[u] > H[e.to]+1)
                            H[u] = H[e.to]+1, cur[u] = &e;
                    if (++co[H[u]], !--co[hii] && hii < v)
                        for(int i=0;i<v;++i)
                            if (hii < H[i] && H[i] < v){
                                --co[H[i]];
                                H[i] = v + 1;
                            }
                    //hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->to]+1)
                    add_flow(*cur[u], min(ec[u], cur[u]->c));
                else ++cur[u];
            if(hi) --hi;
            while (hi<2*v && hs[hi].empty()) ++hi;
        }
        return -ec[s];
    }
};
signed matching(){
    int N, M, E;
	scanf("%d%d%d", &N, &M, &E);
	PushRelabel<int> fl(N+M+3);
	int S=N+M+1, T=N+M+2;
	int u, v;
	for (int i = 0; i < E; ++i) {
		scanf("%d%d", &u, &v);
		fl.add_edge(u, v+N, 1);
	}
	for(int i=0;i<N;++i) fl.add_edge(S, i+1, 1);
	for(int i=0;i<M;++i) fl.add_edge(N+i+1, T, 1);
	int ans = fl.max_flow(S, T);
    printf("%d\n",ans);
	return 0;
}
signed flow(){
    int N, M;
	scanf("%d%d", &N, &M);
	PushRelabel<> fl(N+1);
	int u, v, w;
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		fl.add_edge(u, v, w, w);
	}
	long long ans = fl.max_flow(1, N);
    printf("%lld\n",ans);
	return 0;
}
signed flow2(){
    int N, M;
	scanf("%d%d", &N, &M);
	PushRelabel<int> fl(N+1);
	int u, v, w;
	vector<pair<int, int> > ed(M);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		ed[i] = make_pair(u, fl.add_edge(u, v, w, w));
	}
	fl.max_flow(1, N);
	for(int i=0;i<M;++i){
        auto const&e = fl.g[ed[i].first][ed[i].second];
        printf("%d\n",e.f<0);
	}
	return 0;
}
//
signed main() {
    return flow2();
}