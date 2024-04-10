#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>
#include<cstring>

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXM = 2e5 + 10;

int n, m, q, from[MAXM], to[MAXM];
int tl[MAXM], tr[MAXM], s[MAXM], t[MAXM];
int d[MAXN][MAXN], sec[MAXM];
bool ans[MAXM];

bool cmp(int u, int v){return tl[u] < tl[v];}

int main(){
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &from[i], &to[i]), from[i]--, to[i]--;
	for (int i = 0; i < q; i++)
		scanf("%d %d %d %d", &tl[i], &tr[i], &s[i], &t[i]), tl[i]--, t[i]--, s[i]--;
	iota(sec, sec + q, 0);
	sort(sec, sec + q, cmp);
	
	memset(d, 63, sizeof(d));
	for (int i = 0; i < n; i++)	d[i][i] = 0;

	int cur = q-1;
	for (int i = m - 1; ~i; i--){	
		int u = from[i], v = to[i];
		d[u][v] = min(d[u][v], i);
		d[v][u] = min(d[v][u], i);
		for (int j = 0; j < n; j++)
			if (j^u && j ^ v)
				d[u][j] = min(d[u][j], d[v][j]), d[v][j] = min(d[v][j], d[u][j]);

		while (~cur && tl[sec[cur]] == i){
			ans[sec[cur]] = (d[s[sec[cur]]][t[sec[cur]]] < tr[sec[cur]]);
			cur--;
		}
	}	

	for (int i = 0; i < q; i++)
		if (ans[i])
			printf("Yes\n");
		else
			printf("No\n");
	return 0;
}