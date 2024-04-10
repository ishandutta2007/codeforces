#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<functional>

using namespace std;

const int MAXN = 3e5 + 30;
const int MAX = 1e7;

int n, m;
vector<int>	adj[MAXN];
bool col[MAXN];
int c[MAXN];
int q[MAX];

int main(){
	scanf("%d%d", &n, &m);
	while (m--){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int h = 0, t = 0;
	for (int i = 0; i < n; i++){
		c[i] = adj[i].size();
		if (c[i] > 1)
			q[t++] = i;
	}

	while (h < t){
		int v = q[h++];
		if (c[v] < 2)	continue;
		c[v] = adj[v].size() - c[v];
		col[v] = !col[v];

		for (int u:adj[v]){
			if (col[u] == col[v])	c[u]++;
			else	c[u]--;
			if (c[u] > 1)	q[t++] = u;
		}
	}

	for (int i = 0; i < n; i++)
		if (col[i] == 0)
			printf("0");
		else
			printf("1");
	printf("\n");
	return 0;
}