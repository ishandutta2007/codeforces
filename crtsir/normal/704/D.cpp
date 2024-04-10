#include<bits/stdc++.h>
using namespace std;
int tmp[2000003][4],sz; 
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
	void edges() {
		int m = int(pos.size());
		std::vector<edge> result;
		for (int i = 0; i < m; i++) {
			edge Tmp=get_edge(i);
			tmp[i][0]=Tmp.from;
			tmp[i][1]=Tmp.to;
			tmp[i][2]=Tmp.cap;
			tmp[i][3]=Tmp.flow;
		}sz=m;
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

}  // namespace atcoder


atcoder::mf_graph<int>g(300005),h(300005);

int n,m,r,b,x[100003],y[100003],t[100003],l[100003],d[100003];
vector<int>vx,vy;
map<int,int>mpx,mpy,cntx,cnty,dx,dy;
int cnt[300007];
void add(int fr,int to,int lb,int rb){
	lb=max(lb,0);
	cnt[fr]-=lb;
	cnt[to]+=lb;
	g.add_edge(fr,to,rb-lb);
}
map<pair<int,int>,int>Ans;
bool ok=1;
int main(){
	cin>>n>>m>>r>>b;
	if(r>b)swap(r,b),ok=0;
	for(int i=0;i<n;i++){
		scanf("%d%d",x+i,y+i);
		vx.push_back(x[i]);cntx[x[i]]++;
		vy.push_back(y[i]);cnty[y[i]]++; 
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",t+i,l+i,d+i);
		if(t[i]==1){
			vx.push_back(l[i]);
			if(dx.find(l[i])==dx.end()||dx[l[i]]>d[i])
				dx[l[i]]=d[i];
		}else{
			vy.push_back(l[i]);
			if(dy.find(l[i])==dy.end()||dy[l[i]]>d[i])
				dy[l[i]]=d[i];
		}
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(vy.begin(),vy.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	int S=vx.size()+vy.size(),T=S+1,S_=T+1,T_=S_+1;
	for(int i=0;i<vx.size();i++){
		mpx[vx[i]]=i;
		if(dx.find(vx[i])==dx.end()){
			g.add_edge(S,i,cntx[vx[i]]);
			continue;
		}
		if((cntx[vx[i]]&1)&&dx[vx[i]]==0){
			cout<<-1;
			return 0;
		}
		add(S,i,(cntx[vx[i]]-dx[vx[i]]+1)/2,(cntx[vx[i]]+dx[vx[i]])/2);
	}
	for(int i=0;i<vy.size();i++){
		mpy[vy[i]]=i;
		if(dy.find(vy[i])==dy.end()){
			g.add_edge(i+vx.size(),T,cnty[vy[i]]);
			continue;
		}
		if((cnty[vy[i]]&1)&&dy[vy[i]]==0){
			cout<<-1;
			return 0;
		}
		add(i+vx.size(),T,(cnty[vy[i]]-dy[vy[i]]+1)/2,(cnty[vy[i]]+dy[vy[i]])/2);
	}
	int sum=0;
	for(int i=0;i<=T;i++){
		if(cnt[i]>0)
			g.add_edge(S_,i,cnt[i]),sum+=cnt[i];
		if(cnt[i]<0)
			g.add_edge(i,T_,-cnt[i]);
	}
	for(int i=0;i<n;i++)
		g.add_edge(mpx[x[i]],mpy[y[i]]+vx.size(),1);
	g.add_edge(T,S,998244353);
	if(g.flow(S_,T_)!=sum){
		cout<<-1;
		return 0;
	}
	int ans=0;
	g.edges();
	for(int i=0;i<sz;i++)
		if(tmp[i][0]!=S_&&tmp[i][1]!=T_&&(tmp[i][0]!=T||tmp[i][1]!=S)){
			h.add_edge(tmp[i][0],tmp[i][1],tmp[i][2]-tmp[i][3]);
			h.add_edge(tmp[i][1],tmp[i][0],tmp[i][3]);
			if(tmp[i][0]!=S&&tmp[i][1]!=T)
				Ans[make_pair(tmp[i][0],tmp[i][1]-vx.size())]+=tmp[i][3];
		}else
			if(tmp[i][0]==T&&tmp[i][1]==S)
				ans+=tmp[i][3];
	ans+=h.flow(S,T);
	cout<<1ll*b*n-1ll*ans*(b-r)<<endl;
	h.edges();
	for(int i=0;i<sz;i++)
		if(tmp[i][0]!=S&&tmp[i][1]!=S&&tmp[i][0]!=T&&tmp[i][1]!=T){
			if(tmp[i][0]<vx.size())
				Ans[make_pair(tmp[i][0],tmp[i][1]-vx.size())]+=tmp[i][3];
			if(tmp[i][1]<vx.size())
				Ans[make_pair(tmp[i][1],tmp[i][0]-vx.size())]-=tmp[i][3];
		}
	for(int i=0;i<n;i++){
		if(bool(Ans[make_pair(mpx[x[i]],mpy[y[i]])])^ok)
			cout<<'b';
		else
			cout<<'r';
		if(Ans[make_pair(mpx[x[i]],mpy[y[i]])])
			Ans[make_pair(mpx[x[i]],mpy[y[i]])]--;
	}
}