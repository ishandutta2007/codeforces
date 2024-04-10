#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
#define MAXC	5005
char g[MAXN], s[MAXN], x[MAXN];
bool good[MAXC];
int main() {
	scanf("%s", g + 1);
	int lg = strlen(g + 1);
	for (int i = 1; i <= lg; i++)
		good[g[i]] = true;
	scanf("\n%s", s + 1);
	int ls = strlen(s + 1);
	int pos = 0;
	for (int i = 1; i <= ls; i++)
		if (s[i] == '*') {
			pos = i;
			break;
		}
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("\n%s", x + 1);
		int lx = strlen(x + 1);
		bool flg = true;
		if (pos == 0) {
			if (lx == ls) {
				for (int j = 1; j <= lx; j++) {
					if (x[j] == s[j]) continue;
					if (s[j] == '?' && good[x[j]]) continue;
					flg = false;
					break;
				}
			}
			else flg = false;
		} else {
			if (lx >= ls - 1) {
				for (int j = 1; j < pos; j++) {
					if (x[j] == s[j]) continue;
					if (s[j] == '?' && good[x[j]]) continue;
					flg = false;
					break;
				}
				for (int j = pos; j <= lx - ls + pos; j++)
					if (good[x[j]]) {
						flg = false;
						break;
					}
				for (int j = pos + 1; j <= ls; j++) {
					if (x[lx + j - ls] == s[j]) continue;
					if (s[j] == '?' && good[x[lx + j - ls]]) continue;
					flg = false;
					break;
				}
			} else flg = false;
		}
		if (flg) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}