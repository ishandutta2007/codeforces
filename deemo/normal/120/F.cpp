#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 10;

int n;
vector<int>	adj[MAXN], vec;
int depth[MAXN];
bool mark[MAXN];

int dfs(int v, int de = 0){
	mark[v] = 1;
	depth[v] = de;
	vec.push_back(v);
	int ret = de;
	for (int u:adj[v])
		if (!mark[u])
			ret = max(ret, dfs(u, de + 1));
	return	ret;
}

int get(int r){
	vec.clear();
	dfs(r);
	int maxi = -1, ind = -1;
	for (int u:vec){
		if (depth[u] > maxi){
			maxi = depth[u];
			ind = u;
		}
		mark[u] = 0;
	}
	return	dfs(ind);
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int t;	cin >> t;
	int sum = 0;
	while (t--){
		for (int i = 0; i < MAXN; i++)	adj[i].clear();
		fill(mark, mark + n, 0);
		cin >> n;
		for (int i = 0; i < n - 1; i++){
			int a, b;	cin >> a >> b;	a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		sum += get(0);
	}
	cout << sum << endl;
	return 0;
}