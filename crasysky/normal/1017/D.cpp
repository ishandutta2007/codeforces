#include <iostream>
#include <cstdio>
#define maxn 5003
using namespace std;
int w[maxn], cnt[maxn], logg[maxn], ans[maxn][maxn];
int main(){
	int n, q, m;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++ i)
		cin >> w[i];
	for (int i = 1; i <= m; ++ i){
		char s[20];
		scanf("%s", s);
		int x = 0;
		for (int j = 1; j <= n; ++ j)
			x += (s[j - 1] == '1') << j - 1;
		cnt[x] ++;
	//	cout << x << endl;
	}
	for (int i = 2; i < 1 << n; ++ i)
		logg[i] = logg[i >> 1] + 1;
	int t = 0;
	for (int i = 0; i < 1 << n; ++ i){
		for (int j = 0; j < 1 << n; ++ j)
			if (cnt[j]){
				int s = 0;
				for (int k = 1; k <= n; ++ k){
					int x = (i & (1 << k - 1)) + (bool)(j & (1 << k - 1));
					if ((i & (1 << k - 1)) && (j & (1 << k - 1)) || (i & (1 << k - 1)) == 0 && (j & (1 << k - 1)) == 0)
						s += w[k];
				}
				ans[i][s] += cnt[j];
			}
		for (int j = 1; j <= 1200; ++ j)
			ans[i][j] += ans[i][j - 1];
	}
	while (q --){
		char s[20];
		scanf("%s", s);
		int x = 0;
		for (int i = 1; i <= n; ++ i)
			x += (s[i - 1] == '1') << i - 1;
		int k;
		scanf("%d", &k);
		printf("%d\n", ans[x][k]);
	}
}