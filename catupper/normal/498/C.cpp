#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;


#define LINF (1LL << 60)
#define INF (1 << 30)
#define MAX_N 1050  
#define div ___div
typedef long long  Int;
typedef pair<Int, Int> P;
map<P, int> div;
int pp = 2;
int n, m, x, y, a[108];

struct E{
	int to, rev;
	Int lim;
	E(int x, Int y, int z){
		to = x;
		lim = y;
		rev = z;
	}
};
 
vector<E> edge[MAX_N];
int lev[MAX_N];
int iter[MAX_N];
 
void make_edge(int a, int b, Int l){
	edge[a].push_back(E(b, l, edge[b].size()));
	edge[b].push_back(E(a, 0, edge[a].size() - 1));
}
 
Int dfs(int s, int g, Int f){
	if(s == g)return f;
	for(int &i = iter[s];i < edge[s].size();i++){
		E &e = edge[s][i];
		if(lev[e.to] <= lev[s] || e.lim <= 0)continue;
		Int tmp = dfs(e.to, g, min(f, e.lim));
		if(!tmp)continue;
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
 
Int max_flow(int s, int g){
	Int res = 0;
	bool fin = false;
	while(!fin){
		fill(lev, lev + MAX_N, INF);
		fill(iter, iter + MAX_N, 0);
		bfs(s);
		fin = true;
		while(true){
			int p = dfs(s, g, INF);
			if(p == 0)break;
			fin = false;
			res += p;
		}
	}	
	return res;
}

Int gcd(Int a, Int b){
	if(a == 0)return b;
	return gcd(b % a, a);
}
	
int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		int t = a[i];
		for(int j = 2;j * j <= t;j++){
			int cnt = 0;
			while(t % j == 0){
				t /= j;
				cnt++;
			}
			if(cnt){
				div[P(i, j)] = ++pp;
				if(i%2==0)make_edge(0, pp, cnt);
				else make_edge(pp, 1, cnt);
			}
		}
		if(t != 1){
			div[P(i, t)] = ++pp;
			if(i%2==0)make_edge(0, pp, 1);
			else make_edge(pp, 1, 1);
		}
	}
	for(int i = 0;i < m;i++){
		cin >> x >> y;
		x--,y--;
		if(x % 2 == 1)swap(x, y);
		int t = gcd(a[x], a[y]);
		for(int j = 2;j * j <= t;j++){
			int cnt = 0;
			while(t % j == 0){
				t /= j;
				cnt++;
			}
			if(cnt){
				int from = div[P(x, j)];
				int to = div[P(y, j)];
				make_edge(from, to, cnt);
			}
		}	
		if(t != 1){
			int from = div[P(x, t)];
			int to = div[P(y, t)];
			make_edge(from, to, 1);
		}
	}
	cout << max_flow(0, 1) << endl;
	return 0;
}