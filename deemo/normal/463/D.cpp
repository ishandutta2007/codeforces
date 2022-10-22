#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXK = 6;

int n, k;
int p[MAXK][MAXN], pos[MAXK][MAXN];
int d[MAXN], mark[MAXN][MAXN];

int get(int v){
	if (d[v])	return	d[v];
	int mini = n;

	for (int i = 0; i < k; i++){
		int ind = pos[i][v];
		for (int j = 0; j < ind; j++)
			mark[v][p[i][j]]++;
	}

	d[v] = 1;
	for (int j = 1; j <= n; j++)
		if (mark[v][j] == k)
			d[v] = max(d[v], 1 + get(j));
	return	d[v];
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++){
			scanf("%d", &p[i][j]);
			pos[i][p[i][j]] = j;
		}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, get(i));
	printf("%d\n", ans);
	return	0;	
}