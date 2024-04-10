#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

const int N = 200008;
int n, m;
vector<int> graph[N];

bool visited[N];
bool flags[N];
int flagCount[2];

void dfs(int v, bool flag) {
	if (visited[v]) return;
	visited[v] = true;
	flags[v] = flag;
	flagCount[flag]++;
	for (int w : graph[v]) {
		dfs(w, !flag);
	}
}

void tc() {
	flagCount[0] = 0;
	flagCount[1] = 0;

	cin >> n >> m;
	fori (i, 0, m) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, false);
	assert(flagCount[0] + flagCount[1] == n);
	bool targetFlag = flagCount[1] <= n / 2;
	cout << flagCount[targetFlag] << "\n";
	bool started = false;
	fori (i, 1, n+1) {
		if (flags[i] == targetFlag) {
			if (started) cout << " ";
			started = true;
			cout << i;
		}
	}
	cout << "\n";

	fori (i, 1, n+1) graph[i].clear();
	fori (i, 1, n+1) visited[i] = false;
}

int main() {
	int tcn;
	cin >> tcn;
	fori (i, 0, tcn) tc();
}