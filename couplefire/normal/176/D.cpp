#include <cstdio>
#include <cstring>
 
const int maxn = 2012, maxlen = 1000010;
int n, m, p[maxn], st[maxn], dp[maxn][2], nextc[maxlen][26], nexts[maxn][26], len[maxn];
char s[maxlen], t[maxn];
 
inline void trans(int x, int a, int b){
	if (dp[x][0] > a || (dp[x][0] == a && dp[x][1] > b)) dp[x][0] = a, dp[x][1] = b;
}
 
int main(){
	scanf("%d", &n);
	for (int i = 1, now = 1; i <= n; i++){
		scanf("%s", s + now);
		st[i] = now;
		now += len[i] = strlen(s + now);
		for (int k = now - 2; k >= now - len[i]; k--){
			for (int c = 0; c < 26; c++) nextc[k][c] = nextc[k + 1][c];
			nextc[k][s[k + 1] - 'a'] = k + 1;
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d", p + i);
	for (int i = m - 1; i >= 0; i--)
		for (int c = 0; c < 26; c++)
			if (s[st[p[i + 1]]] - 'a' == c || nextc[st[p[i + 1]]][c]) nexts[i][c] = i + 1;
			else nexts[i][c] = nexts[i + 1][c];
 
	scanf("%s", t);
	int L = strlen(t);
	memset(dp, 0x37, sizeof(dp));
	dp[0][0] = 0; dp[0][1] = 1;
	for (int i = 0; i < L; i++)
		for (int j = L - 1; j >= 0; j--){
			if (dp[j][0] > m) continue;
			if (nextc[st[p[dp[j][0]]] + dp[j][1] - 1][t[i] - 'a'])
				trans(j + 1, dp[j][0],
					nextc[st[p[dp[j][0]]] + dp[j][1] - 1][t[i] - 'a'] - st[p[dp[j][0]]] + 1);
			else if (nexts[dp[j][0]][t[i] - 'a'])
				trans(j + 1, nexts[dp[j][0]][t[i] - 'a'],
						s[st[p[nexts[dp[j][0]][t[i] - 'a']]]] == t[i] ? 1 : nextc[st[p[nexts[dp[j][0]][t[i] - 'a']]]][t[i] - 'a'] - st[p[nexts[dp[j][0]][t[i] - 'a']]] + 1);
		}
	while (dp[L][0] > m) L--;
	printf("%d\n", L);
}