#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

int col[MAX];
vector <int> V[MAX];
vector <int> R[2];

void Nope()
{
	printf("-1\n");
	exit(0);
}

void Dfs(int node)
{
	R[col[node]].push_back(node);
	for (auto it : V[node]) {
		if (col[it] == -1) {
			col[it] = 1 ^ col[node];
			Dfs(it);
		}
		else if (col[it] == col[node])
			Nope();
	}
}

int main()
{
	int n, m;

	scanf("%d%d", &n, &m);

	for (int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	memset(col, -1, sizeof col);
	for (int i=0; i<n; i++)
		if (col[i] == -1) {
			col[i] = 0;
			Dfs(i);
		}

	for (int i=0; i<2; i++) {
		printf("%d\n", (int) R[i].size());
		for (auto it : R[i])
			printf("%d ", it + 1);
		printf("\n");
	}

	return 0;
}