#include<bits/stdc++.h>
using namespace std;

namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
	std::vector<T> payload;
	int pos = 0;
	void reserve(int n) { payload.reserve(n); }
	int size() const { return int(payload.size()) - pos; }
	bool empty() const { return pos == int(payload.size()); }
	void push(const T& t) { payload.push_back(t); }
	T& front() { return payload[pos]; }
	void clear() {
		payload.clear();
		pos = 0;
	}
	void pop() { pos++; }
};

}  // namespace internal
template <class Cap> struct mf_graph {
  public:
	mf_graph() : _n(0) {}
	mf_graph(int n) : _n(n), g(n) {}

	int add_edge(int from, int to, Cap cap) {
		assert(0 <= from && from < _n);
		assert(0 <= to && to < _n);
		assert(0 <= cap);
		int m = int(pos.size());
		pos.push_back({from, int(g[from].size())});
		int from_id = int(g[from].size());
		int to_id = int(g[to].size());
		if (from == to) to_id++;
		g[from].push_back(_edge{to, to_id, cap});
		g[to].push_back(_edge{from, from_id, 0});
		return m;
	}

	struct edge {
		int from, to;
		Cap cap, flow;
	};

	edge get_edge(int i) {
		int m = int(pos.size());
		assert(0 <= i && i < m);
		auto _e = g[pos[i].first][pos[i].second];
		auto _re = g[_e.to][_e.rev];
		return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
	}
	std::vector<edge> edges() {
		int m = int(pos.size());
		std::vector<edge> result;
		for (int i = 0; i < m; i++) {
			result.push_back(get_edge(i));
		}
		return result;
	}
	void change_edge(int i, Cap new_cap, Cap new_flow) {
		int m = int(pos.size());
		assert(0 <= i && i < m);
		assert(0 <= new_flow && new_flow <= new_cap);
		auto& _e = g[pos[i].first][pos[i].second];
		auto& _re = g[_e.to][_e.rev];
		_e.cap = new_cap - new_flow;
		_re.cap = new_flow;
	}

	Cap flow(int s, int t) {
		return flow(s, t, std::numeric_limits<Cap>::max());
	}
	Cap flow(int s, int t, Cap flow_limit) {
		assert(0 <= s && s < _n);
		assert(0 <= t && t < _n);
		assert(s != t);

		std::vector<int> level(_n), iter(_n);
		internal::simple_queue<int> que;

		auto bfs = [&]() {
			std::fill(level.begin(), level.end(), -1);
			level[s] = 0;
			que.clear();
			que.push(s);
			while (!que.empty()) {
				int v = que.front();
				que.pop();
				for (auto e : g[v]) {
					if (e.cap == 0 || level[e.to] >= 0) continue;
					level[e.to] = level[v] + 1;
					if (e.to == t) return;
					que.push(e.to);
				}
			}
		};
		auto dfs = [&](auto self, int v, Cap up) {
			if (v == s) return up;
			Cap res = 0;
			int level_v = level[v];
			for (int& i = iter[v]; i < int(g[v].size()); i++) {
				_edge& e = g[v][i];
				if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
				Cap d =
					self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
				if (d <= 0) continue;
				g[v][i].cap += d;
				g[e.to][e.rev].cap -= d;
				res += d;
				if (res == up) break;
			}
			return res;
		};

		Cap flow = 0;
		while (flow < flow_limit) {
			bfs();
			if (level[t] == -1) break;
			std::fill(iter.begin(), iter.end(), 0);
			while (flow < flow_limit) {
				Cap f = dfs(dfs, t, flow_limit - flow);
				if (!f) break;
				flow += f;
			}
		}
		return flow;
	}

	std::vector<bool> min_cut(int s) {
		std::vector<bool> visited(_n);
		internal::simple_queue<int> que;
		que.push(s);
		while (!que.empty()) {
			int p = que.front();
			que.pop();
			visited[p] = true;
			for (auto e : g[p]) {
				if (e.cap && !visited[e.to]) {
					visited[e.to] = true;
					que.push(e.to);
				}
			}
		}
		return visited;
	}

  private:
	int _n;
	struct _edge {
		int to, rev;
		Cap cap;
	};
	std::vector<std::pair<int, int>> pos;
	std::vector<std::vector<_edge>> g;
};

} 
atcoder::mf_graph<int>g(400003);
int n1,n2,m,q,val[400003];
long long ans;
set<int>e;
map<pair<int,int>,int>mp;
int main(){
	cin>>n1>>n2>>m>>q;
	for(int i=0;i<n1;i++)
		g.add_edge(n1+n2,i,1);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;x--;y--;
		g.add_edge(x,y+n1,1);
		mp[{x,y+n1}]=i+1;
	}
	for(int i=0;i<n2;i++)
		g.add_edge(i+n1,n1+n2+1,1);
	g.flow(n1+n2,n1+n2+1);
	auto V=g.edges();
	vector<bool>vv=g.min_cut(n1+n2); 
	vector<int>v;
	for(int i=0;i<V.size();i++)
		if(V[i].from!=n1+n2&&V[i].to!=n1+n2+1)
			if(V[i].flow)
				e.insert(mp[{V[i].from,V[i].to}]),ans+=mp[{V[i].from,V[i].to}],
				val[V[i].from]=mp[{V[i].from,V[i].to}],val[V[i].to]=mp[{V[i].from,V[i].to}];
			else;
		else
			if(vv[V[i].from]!=vv[V[i].to])
				v.push_back(min(V[i].from,V[i].to));
	while(q--){
		int tp;
		cin>>tp;
		if(tp==1){
			e.erase(val[v.back()]);
			ans-=val[v.back()];
			cout<<1<<endl;
			if(v.back()<n1)
				cout<<v.back()+1<<endl;
			else
				cout<<n1-v.back()-1<<endl;
			v.pop_back();
			cout<<ans;
		}else{
			cout<<e.size()<<endl;
			for(auto it=e.begin();it!=e.end();it++)
				cout<<(*it)<<' ';
		}
		cout<<endl;fflush(stdout);
	}
}