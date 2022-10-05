#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = 3005;
int stk[maxn], used[maxn], b[maxn], s[maxn];
int cnt, n, m, mx, a, tmp, base, now, top;
ll cost, ans = 1e18;
vector<int> c[maxn];

bool cmp(int x, int y) {
	return b[x] < b[y];
}

int main() {
	scanf("%d%d", &n, &m);
	if (m == 1) { return puts("0"), 0; }
	rep (i, 1, n) {
		scanf("%d%d", &a, &b[i]);
		c[a].push_back(i);
		if (a != 1) s[++cnt] = i;
		else base++;
	}
	rep (i, 2, m) {
		sort(c[i].begin(), c[i].end(), cmp);
		mx = max(mx, (int)c[i].size());
	}
	sort(s + 1, s + cnt + 1, cmp);
	rep (i, 0, mx) {
		cost = 0; now = base;
		rep (j, 2, m)
			if (c[j].size() > i) {
				tmp = c[j].size() - i;
				rep (k, 0, tmp - 1) {
					cost += b[c[j][k]];
					used[c[j][k]] = 1;
					stk[++top] = c[j][k];
					now++;
				}
			}
		int cur = 1;
		while (now <= i) {
			while (used[s[cur]]) cur++;
			cost += b[s[cur]];
			used[s[cur]] = 1;
			stk[++top] = s[cur];
			now++; cur++;
		}
		ans = min(ans, cost);
		while (top) used[stk[top--]] = 0;
	}
	cout << ans << endl;
	return 0;
}