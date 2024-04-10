#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_int(x) ({ int _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

const int LOG = 20;
const int max_n = 1e5 + 20;

int n, m, q;
vector<int>	adj[max_n], vec[max_n];
vector<int>	save[max_n][LOG + 5];
int depth[max_n], par[max_n][LOG + 5];

void dfs(int v, int p, int d){
	par[v][0] = p;
	depth[v] = d;
	for (int u:adj[v]){
		if (u == p)	continue;
		dfs(u, v, d + 1); 
	}
}

void init(){
	for (int j = 1; j < LOG; j++)
		for (int i = 0; i < n; i++)
			if (par[i][j - 1] == -1)
				par[i][j] = -1;
			else
				par[i][j] = par[par[i][j - 1]][j - 1];
	
	for (int j = 0; j < LOG; j++)
		for (int i = 0; i < n; i++){
			if (j == 0){
				if (par[i][j - 1] == -1)
					save[i][j].assign(vec[i].begin(), vec[i].end());
				else{
					save[i][j].resize(vec[i].size() + vec[par[i][0]].size());
					merge(vec[i].begin(), vec[i].end(), vec[par[i][0]].begin(), vec[par[i][0]].end(), save[i][j].begin());
					save[i][j].resize(unique(save[i][j].begin(), save[i][j].end()) - save[i][j].begin());
				}
			}
			else{
				if (par[i][j - 1] == -1)
					save[i][j].assign(save[i][j - 1].begin(), save[i][j - 1].end());
				else{
					save[i][j].resize(save[i][j - 1].size() + save[par[i][j - 1]][j - 1].size());
					merge(save[i][j - 1].begin(), save[i][j - 1].end(), save[par[i][j - 1]][j - 1].begin(), save[par[i][j - 1]][j - 1].end(), save[i][j].begin());
					save[i][j].resize(unique(save[i][j].begin(), save[i][j].end()) - save[i][j].begin());
				}
			}
			if (save[i][j].size() > 10)
				save[i][j].resize(10);
		}
}

int lca(int u, int v){
	if (depth[u] < depth[v])	swap(u, v);
	for (int i = LOG - 1; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[v])	u = par[u][i];
	if (u == v)	return	u;

	for (int i = LOG - 1; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];

	return	par[u][0];	
}

vector<int>	sec, gec;

void get(int r, int v, int x){
	for (int i = LOG - 1; i >= 0; i--)
		if (depth[v] - (1 << i) >= depth[r]){
			gec.resize(save[v][i].size() + sec.size());
			merge(save[v][i].begin(), save[v][i].end(), sec.begin(), sec.end(), gec.begin());//XXX dangerous 
			gec.resize(unique(gec.begin(), gec.end()) - gec.begin());
			sec.assign(gec.begin(), gec.end());
			v = par[v][i];
			if (sec.size() > x)	
				sec.resize(x);
		}
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, -1, 0);
	for (int i = 0; i < m; i++){
		int a;	scanf("%d", &a);	a--;
		vec[a].pb(i + 1);
	}
	for (int i = 0; i < n; i++){
		sort(vec[i].begin(), vec[i].end());
		if (vec[i].size() > 10)
			vec[i].resize(10);
	}
	init();
	while (q--){
		int u, v, a;	scanf("%d%d%d", &u, &v, &a); u--, v--;
		if (u == v){
			printf("%d ", min((int)vec[v].size(), a));
			for (int i = 0; i < vec[v].size() && i < a; i++)
				printf("%d ", vec[v][i]);
			printf("\n");
			continue;
		}	
		int p = lca(u, v);
		sec.clear();
		get(p, u, a);
		get(p, v, a);
		printf("%d ", min((int)sec.size(), a));
		for (int i = 0; i < sec.size() && i < a; i++)
			printf("%d ", sec[i]);
		printf("\n");
	}
	return 0;
}