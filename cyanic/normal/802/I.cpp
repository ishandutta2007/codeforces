#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
const int maxn = 1000009;
int rk[maxn], SA[maxn], h[maxn], tax[maxn], tmp[maxn];
int stk[maxn], top, n, m, K, l, r, mid;
long long ans; char s[maxn];
 
bool cmp(int s[], int x, int y, int w) {
	return s[x] == s[y] && s[x+w] == s[y+w];
}
 
void Sort() {
	for (int i=0; i<=m; i++) tax[i] = 0;
	for (int i=1; i<=n; i++) tax[rk[i]]++;
	for (int i=1; i<=m; i++) tax[i] += tax[i-1];
	for (int i=n; i>=1; i--) SA[tax[rk[tmp[i]]]--] = tmp[i];
}
 
void SuffixArray(char s[], int n) {
	for (int i=1; i<=n; i++) {
		rk[i] = s[i]; tmp[i] = i;
	}
	m = 127; Sort();
	for (int w=1,p,i; p<n; w+=w,m=p) {
		for (p=0,i=n-w+1; i<=n; i++) tmp[++p] = i;
		for (i=1; i<=n; i++) if (SA[i] > w) tmp[++p] = SA[i] - w;
		Sort(); swap(rk, tmp); rk[SA[1]] = p = 1;
		for (i=2; i<=n; i++) rk[SA[i]] = cmp(tmp, SA[i], SA[i-1], w) ? p : ++p;
	}
	for (int i=1,j,k=0; i<=n; h[rk[i++]]=k)
		for (k=k?k-1:k,j=SA[rk[i]-1]; s[i+k]==s[j+k]; k++);
}
 
int main() {
	int T, flag = 0; scanf("%d", &T);
	while (T--) {
		scanf("%s", s+1); n = strlen(s+1);
		SuffixArray(s, n); h[0] = h[n+1] = 0;
		stk[++top] = 0; ans = 0;
		for (int i=1; i<=n; i++)
			ans += n - SA[i] + 1 - max(h[i], h[i+1]);
		if (flag) puts(""); flag = 1;
		for (int i=1; i<=n+1; i++) {
			if (h[i] > h[stk[top]]) {
				stk[++top] = i; continue;
			}
			if (h[i] == h[stk[top]]) continue;
			while (top && h[i] <= h[stk[top-1]]) {
				ans += 1LL * (i - stk[top] + 1) * (i - stk[top] + 1) * (h[stk[top]] - h[stk[top-1]]);
				top--;
			}
			ans += 1LL * (i - stk[top] + 1) * (i - stk[top] + 1) * (h[stk[top]] - h[i]);
			h[stk[top]] = h[i];
		}
		printf("%I64d", ans);
	}
	return 0;
}