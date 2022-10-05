#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;

const int maxn = 100005;
int g[maxn], f[maxn], r[maxn], pre[maxn], cur[maxn];
int n, now, ans, K, tmp, L[5], R[5];
char s[maxn], t[maxn];

void EXKMP(char s[], char t[], int n, int m) {
	int mx = 0; f[0] = n;
	rep (i, 1, n-1) {
		f[i] = max(0, min(f[i-mx], mx + f[mx] - i));
		while (i + f[i] <= n && t[i+f[i]] == t[f[i]]) f[i]++;
		if (!mx || i + f[i] > mx + f[mx]) mx = i;
	}
	mx = 0;
	rep (i, 0, n-1) {
		g[i] = max(0, min(f[i-mx], mx + g[mx] - i));
		while (i + g[i] <= n && s[i+g[i]] == t[g[i]]) g[i]++;
		if (!mx || i + g[i] > mx + g[mx]) mx = i;
		if (pre[i+g[i]] <= g[i]) {
			pre[i+g[i]] = g[i];
			cur[i+g[i]] = i + 1;
		}
	}
	rep (i, 1, n) 
		if (pre[i-1] >= pre[i]) {
			pre[i] = pre[i-1];
			cur[i] = cur[i-1];
		}
}

void manachar(char s[], int n) {
	int mx = 0, p = 0;
	s[0] = '@'; s[n+1] = '$';
	for (int i=1; i<=n; i++) {
		r[i] = max(1, min(r[2*p-i], mx - i));
		while (s[i-r[i]] == s[i+r[i]]) r[i]++;
		if (i + r[i] > mx) {
			mx = i + r[i]; p = i;
		}
	}
}

int main() {
	scanf("%s", s + 1); 
	n = strlen(s + 1);
	rep (i, 1, n) t[i] = s[n-i+1];
	EXKMP(s + 1, t + 1, n, n);
	manachar(s, n);
	rep (i, 1, n) {
		now = 2 * r[i] - 1 + 2 * (tmp = min(pre[i-r[i]], n - (i+r[i]-1)));
		if (now > ans) {
			ans = now; K = 0;
			if (!tmp) {
				L[++K] = i - r[i] + 1; R[K] = i + r[i] - 1;
			}
			else {
				L[++K] = cur[i-r[i]]; R[K] = cur[i-r[i]] + tmp - 1;
				L[++K] = i - r[i] + 1; R[K] = i + r[i] - 1;
				// if (R[K-1] + 1 == L[K]) R[K-1] = R[K--];
				L[++K] = n - tmp + 1; R[K] = n;
				// if (R[K-1] + 1 == L[K]) R[K-1] = R[K--];
			}
		}
	}
	printf("%d\n", K);
	rep (i, 1, K) printf("%d %d\n", L[i], R[i] - L[i] + 1);
	return 0;
}