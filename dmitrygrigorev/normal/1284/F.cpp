#include <bits/stdc++.h>
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct FastLCA{

	static const int N = 524288, LG = 21; //N >= 2*n + 7 and N = 2^k

	vector<vector<int> > data;
	vector<int> euler, where, depth, logs;
	int table[N][LG];

	void dfs(int vertex, int last, int d){
	    where[vertex] = euler.size();
	    euler.push_back(vertex);
	    depth[vertex] = d;
	    for (int i=0; i < (int) data[vertex].size(); i++){
	        int to = data[vertex][i];
	        if (to==last) continue;
	        dfs(to, vertex, d + 1);
	        euler.push_back(vertex);
	    }
	}

	void init(vector<pair<int, int> > edges) { //edges are given in 0-indexation
		int n = edges.size() + 1;
		data.assign(n, {}), where.assign(n, -1), depth.assign(n, -1);
		for (int i = 0; i < edges.size(); ++i) {
			int u = edges[i].first, v = edges[i].second;
			data[u].push_back(v), data[v].push_back(u);
		}
		dfs(0, -1, 0);


		int sz = euler.size();
	    for (int i=0; i < sz; i++){
	        table[i][0] = euler[i];
	    }
		int counter = 1;
	    int start_log = 1;
	    logs.push_back(0);
	    for (int i=2; i <= N; i*=2){
	        for (int j=0; j + i <= sz; j++){
	            int fv = table[j][counter - 1];
	            int sv = table[j + i/2][counter-1];
	            if (depth[fv] <= depth[sv]) table[j][counter] = fv;
	            else table[j][counter] = sv;
	        }
	        for (int j=start_log; j <= i; j++){
	            logs.push_back(counter - 1);
	        }
	        start_log = i + 1;
	        counter += 1;
	    }
	}

	int get(int q1, int q2) { //queries are given in 0-indexation
		int first = where[q1];
        int second = where[q2];
        if (first > second) swap(first, second);
        int dist = second - first + 1;
        int first_cand = table[first][logs[dist]];
        int second_cand = table[second + 1 - (1 << logs[dist])][logs[dist]];
        int ans;
        if (depth[first_cand] < depth[second_cand]) ans = first_cand;
        else ans = second_cand;
        return ans;
	}

};

struct Dinic{
    struct edge{
        int to, flow, cap;
    };

    const static int N = 500007; //count of vertices

    vector<edge> e;
    vector<int> g[N + 7];
    int dp[N + 7];
    int ptr[N + 7];

    void clear(){
        for (int i = 0; i < N + 7; i++) g[i].clear();
        e.clear();
    }

    void addEdge(int a, int b, int cap){
        g[a].pb(e.size());
        e.pb({b, 0, cap});
        g[b].pb(e.size());
        e.pb({a, 0, 0});
    }

    int minFlow, start, finish;

    bool bfs(){
        for (int i = 0; i < N; i++) dp[i] = -1;
        dp[start] = 0;
        vector<int> st;
        int uk = 0;
        st.pb(start);
        while(uk < st.size()){
            int v = st[uk++];
            for (int to : g[v]){
                auto ed = e[to];
                if (ed.cap - ed.flow >= minFlow && dp[ed.to] == -1){
                    dp[ed.to] = dp[v] + 1;
                    st.pb(ed.to);
                }
            }
        }
        return dp[finish] != -1;
    }

    int dfs(int v, int flow){
        if (v == finish) return flow;
        for (; ptr[v] < g[v].size(); ptr[v]++){
            int to = g[v][ptr[v]];
            edge ed = e[to];
            if (ed.cap - ed.flow >= minFlow && dp[ed.to] == dp[v] + 1){
                int add = dfs(ed.to, min(flow, ed.cap - ed.flow));
                if (add){
                    e[to].flow += add;
                    e[to ^ 1].flow -= add;
                    return add;
                }
            }
        }
        return 0;
    }

    int dinic(int start, int finish){
        Dinic::start = start;
        Dinic::finish = finish;
        int flow = 0;
        for (minFlow = 1; minFlow; minFlow >>= 1){
            while(bfs()){
                for (int i = 0; i < N; i++) ptr[i] = 0;
                while(int now = dfs(start, (int)2e9 + 7)) flow += now;
            }
        }
        return flow;
    }
} dinic;

FastLCA fas;

vector<vector<pair<int, int> > > data;
vector<int> father, efather;

void dfs(int vertex, int last) {
	father[vertex] = last;
	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i].first, ed = data[vertex][i].second;
		if (to==last) continue;
		efather[to] = ed;
		dfs(to, vertex);
	}
}

const int N = 250007, LG = 20; //set it here
// init from list of tree edges 
// get(x, y) returns y-th ancestor of x by O(1)

struct LA{
    int dv[LG][N];
    int n, m, u;
    int szlad = 0;
    vector<int> ladders[N], data[N];
    int what_ladder[N], what_number[N], logs[2*N], lengths[N];
    int fathers[N], d[N];

    void first_dfs(int vertex){
        int l = 1;
        for (int i=0; i < (int) data[vertex].size(); i++){
            int to = data[vertex][i];
            first_dfs(to);
            l = max(l, lengths[to] + 1);
        }
        lengths[vertex] = l;
    }

    void up(int vertex, int ost){
        if (vertex == 0 || ost == 0){
            ladders[szlad-1].push_back(vertex);
            return;
        }
        up(fathers[vertex], ost - 1);
        ladders[szlad-1].push_back(vertex);
    }

    void binup_dfs(int vertex, int last){
        if (last != -1){
            dv[0][vertex] = last;
            int nv = last;
            int now_level = 1;
            while (dv[now_level-1][nv] != -1){
                dv[now_level][vertex] = dv[now_level-1][nv];
                nv = dv[now_level-1][nv];
                now_level++;
            }
        }
        for (int i=0; i < (int) data[vertex].size(); i++){
            binup_dfs(data[vertex][i], vertex);
        }
    }

    void dfs(int vertex, int ladder, int depth){
        d[vertex] = depth;
        if (szlad == ladder){
            szlad++;
            up(vertex, lengths[vertex]);
            what_ladder[vertex] = szlad - 1;
            what_number[vertex] = ladders[szlad - 1].size() - 1;
        }
        else{
            ladders[ladder].push_back(vertex);
            what_ladder[vertex] = ladder;
            what_number[vertex] = ladders[ladder].size() - 1;
        }
        bool go = false;
        for (int i=0; i < (int) data[vertex].size(); i++){
            int to = data[vertex][i];
            if (go || lengths[to] + 1 != lengths[vertex]){
                dfs(to, szlad, depth + 1);
            }
            else{
                dfs(to, ladder, depth + 1);
                go = true;
            }
        }
    }

    int get(int vertex, int when){
        if (d[vertex] <= when) return 0;
        if (when == 0) return vertex;
        vertex = dv[logs[when]][vertex];
        when -= (1LL << logs[when]);
        return ladders[what_ladder[vertex]][what_number[vertex] - when];
    }
     
    void pre_dfs(int vertex, int last){
        if (last != -1) fathers[vertex] = last;
     
        int I = -1;
     
        for (int i=0; i < data[vertex].size(); ++i){
            int to = data[vertex][i];
            if (to==last){
                I=i;
                continue;
            }
            pre_dfs(to, vertex);
        }
     
        if (I!=-1){
            swap(data[vertex][I], data[vertex].back());
            data[vertex].pop_back();
        }
    }

    void init(vector<pair<int, int> > edges) {
        for (int i=0; i < edges.size(); ++i) {
            data[edges[i].first].push_back(edges[i].second);
            data[edges[i].second].push_back(edges[i].first);
        }

        pre_dfs(0, -1);
        first_dfs(0);
        int start = 0;
        for (int i=0; i < LG; i++){
            for (int j=0; j < N; j++){
                dv[i][j] = -1;
            }
        }
        for (int i=2; i <= 2*N; i*=2){
            for (int j=i/2; j < i; j++){
                logs[j] = start;
            }
            start++;
        }
        dfs(0, 0, 0);
        binup_dfs(0, -1);

    }

};

template<typename cap_t, typename excess_t, bool global_relabeling = true, bool min_cut_only = false, bool shuffle_edges = false>
class Push_Relabel{
public:
    struct Edge{
        int from, to, rev;
        cap_t f; cap_t cap; // cap-f is supposed to be used as information about flow number through an edge
    };

    Push_Relabel(int n_):n(n_), m(0){}

    void add_edge(int u, int v, cap_t c, cap_t c_rev = 0){
        edge_pool.emplace_back(u, v, c, c_rev);
        ++m;
    }
    excess_t max_flow(int s_, int t_){
        s = s_; t = t_;
        run_pr();
        return excess[t]-1;
    }

    vector<Edge> g;

private:
    void compile_g(){
        g_pos.resize(n+1);
        if(shuffle_edges) random_shuffle(edge_pool.begin(), edge_pool.end());
        for(auto &e:edge_pool){
            ++g_pos[get<0>(e)];
            ++g_pos[get<1>(e)];
        }
        for(int i=0;i<n;++i){
            g_pos[i+1]+=g_pos[i];
        }
        g.resize(g_pos.back());
        for(auto &e:edge_pool){
            int u, v; cap_t c, c_rev;
            tie(u, v, c, c_rev) = e;
            const int i = --g_pos[u], j = --g_pos[v];
            //cout << "===== " << u << " " << v << endl;
            g[i] = Edge{u, v, j, c, c};
            g[j] = Edge{v, u, i, c_rev, c_rev};
        }
    }
    void global_relabel(){
        q.reserve(n);
        fill(h.begin(), h.end(), n);
        fill(h_cnt.begin(), h_cnt.end(), 0);
        h_cnt[n] = 1;
        q.push_back(t);
        h[t] = 0;
        for(auto &e:buck) e.clear();
        for(auto &e:buck_all) e.clear();
        for(auto it = q.begin();it<q.end();++it){
            const int u = *it;
            if(u != t && excess[u]){
                hi = h[u];
                buck[h[u]].push_back(u);
            }
            if(u != t) buck_all[h[u]].push_back(u);
            ++h_cnt[h[u]];
            for(int i = g_pos[u],i_end = g_pos[u+1];i < i_end;++i){
                Edge const&e = g[i];
                if(g[e.rev].f && h[e.to] == n){
                    h[e.to] = h[u]+1;
                    q.push_back(e.to);
                }
            }
        }
        hi_all = h[q.back()];
        assert(h[s] == n);
        q.clear();
    }
    void push(int u, Edge &e, excess_t f){
        if(!excess[e.to]){
            buck[h[e.to]].push_back(e.to);
        }
        Edge&back = g[e.rev];
        e.f-=f;
        back.f+=f;
        excess[e.to]+=f;
        excess[u]-=f;
    }
    void init_pr(){
        compile_g();
        cur.assign(n, 0);
        copy(g_pos.begin(), prev(g_pos.end()), cur.begin());
        h.resize(n);
        excess.assign(n, 0);
        buck.resize(2*n);
        buck_all.resize(n+1);
        h_cnt.assign(2*n, 0);
        h[s] = n;
        h_cnt[n] = 1;
        h_cnt[0] = n-1;
        excess[t] = 1;
    }
    void run_pr(){
        init_pr();
        for(int i = g_pos[s],i_end = g_pos[s+1];i < i_end;++i){
            push(s, g[i], g[i].f);
        }
        hi = hi_all = 0;
        if(global_relabeling) global_relabel();
        if(!buck[hi].empty())
        for(;hi>=0;){
            int u = buck[hi].back(); buck[hi].pop_back();
            int u_cur = cur[u];
            //discharge
            if(!min_cut_only || h[u] < n)
            while(excess[u] > 0){
                if(__builtin_expect(u_cur == g_pos[u+1], false)){
                    int new_h = 1e9;
                    for(int i = g_pos[u],i_end = g_pos[u+1];i < i_end;++i){
                        auto const&e = g[i];
                        if(e.f && new_h > h[e.to]+1){
                            new_h = h[e.to]+1;
                            u_cur = i;
                        }
                    }
                    ++h_cnt[new_h];
                    h[u] = new_h;
                    if(__builtin_expect(!--h_cnt[hi] && hi < n, false)){
                        // gap relabel
                        for(int j = hi;j <= hi_all;++j){
                            for(auto &f:buck_all[j]) if(!min_cut_only || h[f] < n){
                                --h_cnt[h[f]];
                                h[f] = n+1;
                            }
                            buck_all[j].clear();
                        }
                    }
                    hi = h[u];
                } else {
                    Edge &e_cur = g[u_cur];
                    if(e_cur.f && h[u] == h[e_cur.to]+1){
                        push(u, e_cur, min<excess_t>(excess[u], e_cur.f));
                    } else ++u_cur;
                }
            }
            if(h[u] < n) {
                hi_all = max(hi_all, h[u]);
                buck_all[h[u]].push_back(u);
            }
            cur[u] = u_cur;
            while(hi>=0 && buck[hi].empty()) --hi;
        }
    }

    int n, m, s, t, hi, hi_all;
    vector<tuple<int, int, cap_t, cap_t> > edge_pool;
    vector<int> g_pos;
    vector<int> q, cur, h, h_cnt;
    vector<excess_t> excess;
    vector<vector<int> > buck, buck_all;
};

LA la;

main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int> > edges, sedges;
	data.assign(n, {});
	father.assign(n, -1), efather.assign(n, -1);

	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges.push_back({u, v});
		data[u].push_back({v, i}), data[v].push_back({u, i});
	}

	fas.init(edges);
	la.init(edges);
	Push_Relabel<int, int> kek(2*n);

	dfs(0, -1);

	for (int i = 0; i < n-1; ++i) {
		kek.add_edge(0, i+1, 1);
		kek.add_edge(n+i, 2*n-1, 1);
	}

	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		sedges.push_back({u, v});

		int t = u;

		for (int j = 0; j < 8; ++j) {
			if (t==v) break;
			if (fas.get(t, v) == t) {
				//cout << t << " ? " << v << " " << fas.depth[v] << " " << fas.depth[t] << " " << fas.get(t, v) << endl;
				int delta = fas.depth[v] - fas.depth[t];
				int to = la.get(v, delta-1);
				int E = efather[to];
				kek.add_edge(E+1, n+i, 1);
				t = to;
				continue;
			}
			int E = efather[t];
			kek.add_edge(E+1, n+i, 1);
			t = father[t];
		}

		t = v;
		for (int j = 0; j < 8; ++j) {
			if (t==u) break;
			if (fas.get(t, u) == t) {
				//cout << t << " " << u << " " << fas.depth[u] << " " << fas.depth[t] << endl;
				int delta = fas.depth[u] - fas.depth[t];
				int to = la.get(u, delta-1);
				int E = efather[to];
				kek.add_edge(E+1, n+i, 1);
				t = to;
				continue;
			}
			int E = efather[t];
			kek.add_edge(E+1, n+i, 1);
			t = father[t];
		}
	}



	kek.max_flow(0, 2*n-1);


	cout << n-1 << endl;

	map<pair<int, int>, int> ed;

	for (int i = 0; i < kek.g.size(); i ++) {
		int from = kek.g[i].from, to = kek.g[i].to;
		//cout << from << " " << to << " " << kek.g[i].f << endl;
		if (kek.g[i].cap - kek.g[i].f <= 0 || from <= 0 || from >= n || to < n || to >= 2*n-1) continue;
		from--, to -= n;
		cout << edges[from].first+1 << " " << edges[from].second+1 << " " << sedges[to].first+1 << " " << sedges[to].second+1 << "\n";

		//cout << "==== " << from << " " << to << " " << kek.g[i].f << endl;
		//cout << edges[from].first+1 << " " << edges[from].second+1 << " " << sedges[to].first+1 << " " << sedges[to].second+1 << "\n";
	}




}