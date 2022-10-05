#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
 
const int maxn = 1200005;
struct SAM { int p[27], pa, val; } t[maxn];
int tax[maxn], cur[maxn], l[12], r[12], n, m, u, flag;
int cnt[maxn][12], last = 1, root = 1, size = 1, ans;
char s[maxn];
 
void extend(int c, int pos) {
	int p = last, np = ++size, q, nq;
	t[np].val = t[p].val + 1; cnt[np][pos] = 1;
	for (; p&&!t[p].p[c]; p=t[p].pa) t[p].p[c] = np;
	if (!p) t[np].pa = root;
	else {
		q = t[p].p[c];
		if (t[q].val == t[p].val + 1) t[np].pa = q;
		else {
			nq = ++size; t[nq] = t[q];
			t[nq].val = t[p].val + 1;
			t[q].pa = t[np].pa = nq;
			for (; p&&t[p].p[c]==q; p=t[p].pa) t[p].p[c] = nq;
		}
	}
	last = np;
}
 
int main() {
	scanf("%s%d", &s, &n);
	for (int i=0; s[i]; i++) extend(s[i] - 'a', 0);
	extend(26, n+1); 
	rep (j, 1, n) {
		scanf("%s%d%d", &s, &l[j], &r[j]);
		for (int i=0; s[i]; i++) extend(s[i] - 'a', j);
		extend(26, n+1);
	}
	rep (i, 1, size) tax[t[i].val]++;
	rep (i, 1, size) tax[i] += tax[i-1];
	per (i, size, 1) cur[tax[t[i].val]--] = i;
	per (i, size, 1) {
		u = cur[i]; 
		rep (j, 0, n) cnt[t[u].pa][j] += cnt[u][j];
		if (!cnt[u][0]) continue; flag = 1;
		rep (j, 1, n) flag &= (l[j] <= cnt[u][j] && cnt[u][j] <= r[j]);
		if (flag) ans += t[u].val - t[t[u].pa].val;
	}
	printf("%d\n", ans);
	return 0;
}