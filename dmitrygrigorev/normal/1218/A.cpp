#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;

vector<bool> used;

vector<int> cycle;

void dfs(int vertex, int last, vector<int> &path){
	used[vertex] = true;
	path.push_back(vertex);
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (to==last) continue;
		if (used[to]){
			if (!cycle.size()){
				int index = path.size() - 1;
				while (path[index] != to){
					cycle.push_back(path[index--]);
				}
				cycle.push_back(path[index]);
			}
			continue;
		}
		dfs(to, vertex, path);
	}
	path.pop_back();
}

vector<bool> if_cycle;

vector<int> sz, tree_ans, ans, szs;

int dfs2(int vertex, int last, int number){
	sz[number]++;
	szs[vertex] = 1;
	int tut = 1;
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (if_cycle[to] || to==last) continue;
		tut += dfs2(to, vertex, number);
		szs[vertex] += szs[to];
	}
	tree_ans[number] += tut;
	//cout << vertex << " " << szs[vertex] << endl;
	return tut;
}
int n;
void dfs3(int vertex, int last, int number, int cur){
	ans[number] = max(ans[number], cur);
	//cout << vertex << " " << cur << " " << szs[vertex] << endl;
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (if_cycle[to] || to==last) continue;
		dfs3(to, vertex, number, cur+n-2*szs[to]);
	}
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	data.assign(n, {});
	for (int i=0;i<n;++i){
		int u, v;
		cin >> u >> v;
		data[u].push_back(v), data[v].push_back(u);
	}
	used.assign(n, false);

	vector<int> p;
	dfs(0, -1, p);

	if_cycle.assign(n, false);
	for (int i=0; i < cycle.size(); ++i){
		//cout << cycle[i] << " ";
		if_cycle[cycle[i]] = true;
	}

	//cout << endl;

	int S = cycle.size();
	sz.assign(S, 0);
	tree_ans.assign(S, 0);
	szs.assign(n, 0);
	for (int i=0; i < cycle.size(); ++i){
		tree_ans[i] -= dfs2(cycle[i], -1, i);
	}

	ans.assign(S, 0);
	for (int i=0; i < cycle.size(); ++i){
		dfs3(cycle[i], -1, i, tree_ans[i] + n);
	}

	int dp[S], dp2[S], sums[S];
	for (int i=0;i<S;++i) dp[i] = ans[i];
	for (int len=2; len <= S; len++){
		sums[0] = 0;
		for (int i=0; i < len-1;++i) sums[0] += sz[i];
		int B = len-1;
		for (int i=1; i < S; ++i){
			sums[i] = sums[i-1] - sz[i-1] + sz[B++];
			if (B==S) B = 0;
		}
		int A = len-1;
		for (int i=0; i < S-1; ++i){
			dp2[i] = max(dp[i] + tree_ans[A++] + n - sums[i], tree_ans[i] + dp[i+1] + n - sums[i+1]);
			if (A==S) A=0;
		}
		dp2[S-1] = max(dp[S-1]+tree_ans[A], tree_ans[S-1] + dp[0] + n - sums[0]);
		for (int i=0;i<S;++i){
			dp[i] = dp2[i];
			//cout << dp[i] << " ";
		}
		//cout << endl;
	}
	int A = 0;
	for (int i=0;i<S;++i) A = max(A, dp[i]);
	cout << A;
}