#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int n, a[MAXN][MAXN];
int p[MAXN], b[MAXN], ans[MAXN];
bool mark[MAXN];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		printf("? %d %d\n", 0, i);
		cin >> a[0][i];
	}
	for (int i = 1; i < n; i++) {
		printf("? %d %d\n", i, 0);
		cin >> a[i][0];
	}
	printf("!\n");
	int cnt = 0;
	for (int j = 0; j < n; j++) {
		p[0] = j; b[0] = a[0][0] ^ p[0];
		for (int i = 1; i < n; i++) {
			p[i] = a[i][0] ^ b[0];
			b[i] = a[0][i] ^ p[0];
		}
		bool flg = true;
		memset(mark, false, sizeof(mark));
		for (int i = 0; i < n; i++)
			if (p[i] >= 0 && p[i] < n && !mark[p[i]]) mark[p[i]] = true;
			else {
				flg = false;
				break;
			}
		if (!flg) continue;
		memset(mark, false, sizeof(mark));
		for (int i = 0; i < n; i++)
			if (b[i] >= 0 && b[i] < n && !mark[b[i]]) mark[b[i]] = true;
			else {
				flg = false;
				break;
			}
		if (!flg) continue;
		for (int i = 0; i < n; i++)
			if (p[b[i]] != i) {
				flg = false;
				break;
			}
		if (!flg) continue;
		cnt++;
		if (cnt == 1) {
			for (int i = 0; i < n; i++)
				ans[i] = p[i];
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}