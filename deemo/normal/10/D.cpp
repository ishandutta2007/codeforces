#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>

using namespace std;

const int max_n = 500 + 10;

int n, m;
int a[max_n], b[max_n];
int d[max_n][max_n];
pair<int, int>	par[max_n][max_n];

void show(int r, int c, int z){
	if (z == 0)	return;
	show(par[r][c].first, par[r][c].second, z - 1);
	printf("%d ", a[r]);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)	scanf("%d", &b[i]);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			int t = j;
			while (t >= 0 && b[t] != a[i])	t--;
			if (t <= 0){
				d[i][j] = t + 1;
				continue;
			}
			t--;
			
			d[i][j] = 1;
			int z = i - 1;
			for (; z >= 0; z--){
				if (a[z] >= a[i])	continue;
				if (d[z][t] + 1 > d[i][j]){
					d[i][j] = d[z][t] + 1;
					par[i][j] = {z, t};
				}
			}
		}

	int ans = 0, r, c;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ans <= d[i][j]){
				ans = d[i][j];
				r = i, c = j;
			}
	printf("%d\n", ans);
	if (ans){
		show(r, c, ans);
		printf("\n");
	}
	return 0;
}