#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
bool vis[MAXN];
char s[MAXN];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int l = 1, r = n, k = 0;
	while (l <= r) {
		if (s[l] == ')') l++;
		else if (s[r] == '(') r--;
		else {
			vis[l] = vis[r] = true;
			k++, l++, r--;
		}
	}
	if (k) {
		printf("%d\n%d\n", 1, 2 * k);
		for (int i = 1; i <= n; i++)
			if (vis[i]) printf("%d ", i);
		printf("\n");
	} else printf("%d\n", 0);
	return 0;
}