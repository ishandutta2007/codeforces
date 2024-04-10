#include<bits/stdc++.h>
using namespace std;
namespace atcoder {

template <class Cap, class Cost> struct mcf_graph {
  public:
    mcf_graph() {}
    mcf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap, cost});
        g[to].push_back(_edge{from, from_id, 0, -cost});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{
            pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
        };
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result(m);
        for (int i = 0; i < m; i++) {
            result[i] = get_edge(i);
        }
        return result;
    }

    std::pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, std::numeric_limits<Cap>::max());
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);
        // variants (C = maxcost):
        // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
        // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge
        std::vector<Cost> dual(_n, 0), dist(_n);
        std::vector<int> pv(_n), pe(_n);
        std::vector<bool> vis(_n);
        auto dual_ref = [&]() {
            std::fill(dist.begin(), dist.end(),
                      std::numeric_limits<Cost>::max());
            std::fill(pv.begin(), pv.end(), -1);
            std::fill(pe.begin(), pe.end(), -1);
            std::fill(vis.begin(), vis.end(), false);
            struct Q {
                Cost key;
                int to;
                bool operator<(Q r) const { return key > r.key; }
            };
            std::priority_queue<Q> que;
            dist[s] = 0;
            que.push(Q{0, s});
            while (!que.empty()) {
                int v = que.top().to;
                que.pop();
                if (vis[v]) continue;
                vis[v] = true;
                if (v == t) break;
                // dist[v] = shortest(s, v) + dual[s] - dual[v]
                // dist[v] >= 0 (all reduced cost are positive)
                // dist[v] <= (n-1)C
                for (int i = 0; i < int(g[v].size()); i++) {
                    auto e = g[v][i];
                    if (vis[e.to] || !e.cap) continue;
                    // |-dual[e.to] + dual[v]| <= (n-1)C
                    // cost <= C - -(n-1)C + 0 = nC
                    Cost cost = e.cost - dual[e.to] + dual[v];
                    if (dist[e.to] - dist[v] > cost) {
                        dist[e.to] = dist[v] + cost;
                        pv[e.to] = v;
                        pe[e.to] = i;
                        que.push(Q{dist[e.to], e.to});
                    }
                }
            }
            if (!vis[t]) {
                return false;
            }

            for (int v = 0; v < _n; v++) {
                if (!vis[v]) continue;
                // dual[v] = dual[v] - dist[t] + dist[v]
                //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) + (shortest(s, v) + dual[s] - dual[v])
                //         = - shortest(s, t) + dual[t] + shortest(s, v)
                //         = shortest(s, v) - shortest(s, t) >= 0 - (n-1)C
                dual[v] -= dist[t] - dist[v];
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        std::vector<std::pair<Cap, Cost>> result;
        result.push_back({flow, cost});
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = pv[v]) {
                c = std::min(c, g[pv[v]][pe[v]].cap);
            }
            for (int v = t; v != s; v = pv[v]) {
                auto& e = g[pv[v]][pe[v]];
                e.cap -= c;
                g[v][e.rev].cap += c;
            }
            Cost d = -dual[s];
            flow += c;
            cost += c * d;
            if (prev_cost_per_flow == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return result;
    }

  private:
    int _n;

    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder


atcoder::mcf_graph<int,int>g(9000);

const int inf=998244353;
int n,a[4403],b[4403],idx[4403],S=8800,T=8801;
bool cmp(int x,int y){return b[x]<b[y];}
vector<long long>vs,vt;
bool check(int t,int tp){
	map<int,long long>mp;
	long long maxn=0;
	for(int i=0;i<n+n;i++) {
		maxn=max(maxn,1ll*a[idx[i]]*t+b[idx[i]]);
		mp[b[idx[i]]]=maxn;
	}vs.clear();vt.clear();
	for(int i=0;i<n;i++){
		vs.push_back(mp[b[i]]);
		vt.push_back(1ll*a[i+n]*t+b[i+n]);
	}
	if(tp==1)return 0;
	sort(vs.begin(),vs.end());
	sort(vt.begin(),vt.end());
	for(int i=0;i<n;i++)
		if(vs[i]<vt[i])
			return 0;
	return 1;
}
bool cmp1(int x,int y){
	return b[x+n]<b[y+n];
}
bool cmp2(int x,int y){
	return vt[x]<vt[y];
}
int main(){
	cin>>n;
	for(int i=0;i<n+n;i++)
		cin>>a[i]>>b[i],idx[i]=i;
	sort(idx,idx+n+n,cmp);
	int l=0,r=1000000001,mid;
	while(l!=r){
		mid=(l+r>>1);
		if(check(mid,0))
			r=mid;
		else
			l=mid+1;
	}
	if(l==1000000001){cout<<-1;return 0;}
	cout<<l<<' ';
	check(l,1);
	for(int i=0;i<n;i++)
		idx[i]=i;
	sort(idx,idx+n,cmp2);
	for(int i=n-1;i>0;i--)
		g.add_edge(idx[i]+n,idx[i-1]+n,inf,0);
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=0;j--)
			if(1ll*a[i]*l+b[i]>=vt[idx[j]]){
				g.add_edge(i,idx[j]+n,1,0);
				break;
			}
		for(int j=n-1;j>=0;j--)
			if(vs[i]>=vt[idx[j]]){
				g.add_edge(i,idx[j]+n,1,1);
				break;
			}
	}
	sort(idx,idx+n,cmp1);
	for(int i=n-1;i>0;i--)
		g.add_edge(idx[i]+n+n,idx[i-1]+n+n,inf,0);
	for(int i=0;i<n;i++)
		for(int j=n-1;j>=0;j--)
			if(b[i]>=b[idx[j]+n]){
				g.add_edge(i,idx[j]+n+n,1,0);
				break;
			}
	for(int i=0;i<n;i++){
		g.add_edge(S,i,1,0);
		g.add_edge(i+n,i+n+n+n,1,0);
		g.add_edge(i+n+n,i+n+n+n,1,0);
		g.add_edge(i+n+n+n,T,1,0);
	}cout<<n+g.flow(S,T).second;
}