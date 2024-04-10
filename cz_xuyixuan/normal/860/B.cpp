#include<bits/stdc++.h>
using namespace std;
#define MAXN	70005
#define MAXP	4000005
int root, size;
int child[MAXP][10], cnt[MAXP];
char s[MAXN][12];
void insert(char *s) {
	int len = strlen(s);
	int now = root;
	for (int i = 0; i < len; i++) {
		if (child[now][s[i] - '0'] == 0) child[now][s[i] - '0'] = ++size;
		now = child[now][s[i] - '0'];
	}
	cnt[now]++;
}
void dfs(int pos) {
	for (int i = 0; i <= 9; i++)
		if (child[pos][i]) {
			dfs(child[pos][i]);
			cnt[pos] += cnt[child[pos][i]];
		}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= 9; j++)
			insert(s[i] + j);
	}
	dfs(root);
	static int f[10][10];
	static long long num[10][10];
	for (int i = 1; i <= n; i++) {
		bool solved = false;
		memset(f, 0, sizeof(f));
		memset(num, 0, sizeof(num));
		for (int j = 1; j <= 9; j++)
		for (int k = j; k <= 9; k++)
			num[j][k] = num[j][k - 1] * 10 + s[i][k] - '0';
		for (int l = 1; l <= 9; l++)
		for (int j = 1, k = l; k <= 9; j++, k++)
		for (int tj = 1, tk = l; tk <= 9; tj++, tk++)
			if (num[j][k] == num[tj][tk]) f[j][k]++;
		for (int l = 1; l <= 9; l++)
		for (int j = 1, k = l; k <= 9; j++, k++) {
			if (solved) break;
			int now = root;
			for (int ti = j; ti <= k; ti++)
				now = child[now][s[i][ti] - '0'];
			if (cnt[now] == f[j][k]) {
				for (int ti = j; ti <= k; ti++)
					printf("%c", s[i][ti]);
				printf("\n");
				solved = true;
			}
		}
	}
	return 0;
}