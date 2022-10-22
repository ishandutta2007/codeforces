#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

template <typename Weight, int MAX_N, Weight INF> class MaxFlow{
public:
	struct E{
		int to, rev;
		Weight lim;
		E(int x, Weight y, int z){
			to = x;
			lim = y;
			rev = z;
		}
	};

	vector<E> edge[MAX_N];
	int lev[MAX_N];
	int iter[MAX_N];


	Weight dfs(int s, int g, Weight f){
		if(s == g)return f;
		for(int &i = iter[s];i < edge[s].size();i++){
			E &e = edge[s][i];
				if(lev[e.to] <= lev[s] || e.lim <= 0)continue;
			Weight tmp = dfs(e.to, g, min(f, e.lim));
			if(tmp<1e-9)continue;
			e.lim -= tmp;
			edge[e.to][e.rev].lim += tmp;
			return tmp;
		}
		return 0;
	}

	void bfs(int x){
		queue<int> q;
		q.push(x);
		int p = 0;
			while(!q.empty()){
			for(int i = q.size();i--;){
				int tmp = q.front();q.pop();
				if(lev[tmp] != INF)continue;
				lev[tmp] = p;
				for(int j = 0;j < edge[tmp].size();j++){
					if(edge[tmp][j].lim > 0 && lev[edge[tmp][j].to] == INF)q.push(edge[tmp][j].to);
				}
			}
			p++;
		}
	}

	void make_edge(int a, int b, Weight l){
		edge[a].push_back(E(b, l, edge[b].size()));
		edge[b].push_back(E(a, 0, edge[a].size() - 1));
	}

	Weight max_flow(int s, int g){
		Weight res = 0;
		bool fin = false;
		while(!fin){
			fill(lev, lev + MAX_N, INF);
			fill(iter, iter + MAX_N, 0);
			bfs(s);
			fin = true;
			while(true){
				Weight p = dfs(s, g, INF);
				if(p < 1e-9)break;
				fin = false;
				res += p;
			}
		}	
		return res;
	}
};

#define INF (1 << 30)
bool prime[108000];
vector<int> ans[108000];
bool come[108000];
vector<int> neib[108000];
void init(){
	for(int i = 2;i < 21600;i++)prime[i] = true;
	for(int i = 2;i < 21600;i++){
		if(!prime[i])continue;
		for(int j = i * i;j < 21600; j+=i){
			prime[j] = false;
		}
	}
}

void dfs(int x, int p, int last = -1){
	if(come[x])return;
	come[x] = true;
	ans[p].push_back(x);
	dfs(neib[x][0], p, x);
	dfs(neib[x][1], p, x);
}

int main(){
	init();
	MaxFlow<int, 500, INF> mf; 
	int n;
	int a[108000];
	cin >> n;
	int start = n * 2;
	int goal = start + 1;
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(i == j)continue;
			if(a[i] % 2 == 0)continue;
			if(prime[a[i]+a[j]])mf.make_edge(i, j + n, 1);
		}
		mf.make_edge(start, i, 2);
		mf.make_edge(n + i, goal, 2);
	}
	int tmp = mf.max_flow(start, goal);
	if(tmp != n){
		cout << "Impossible" << endl;
		return 0;
	}
	for(int i = 0;i < n;i++){
		if(a[i] % 2 == 0)continue;
		for(int j = 0;j < mf.edge[i].size();j++){
			if(mf.edge[i][j].lim == 0){
				int to = mf.edge[i][j].to - n;
				neib[i].push_back(to);
				neib[to].push_back(i);
			}
		}
	}

	
	int p = 0;
	for(int i = 0;i < n;i++){
		if(come[i])continue;
		dfs(i, p++);
	}
	cout << p << endl;
	for(int i = 0;i < p;i++){
		cout << ans[i].size();
		for(int j = 0;j < ans[i].size();j++){
			cout << " " << ans[i][j] + 1;
		}
		cout << endl;
	}
	return 0;
	
}