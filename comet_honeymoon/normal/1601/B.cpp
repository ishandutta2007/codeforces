#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 300005;
int n;
int a[maxn];
int b[maxn];

int fa[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int dis[maxn], fa1[maxn], fa2[maxn];
bool vis[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n + 1; i++) fa[i] = i;
	memset(dis, 0x3f, sizeof(dis));
	dis[n] = 0;
	queue<int> Q; Q.push(n);
	int ans = 0x3f3f3f3f;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int i = u - 1; i >= u - a[u] && i >= 0; i = find(i - 1))  {
			if (!vis[i]) {
				vis[i] = 1; if (i != 0) fa[i] = find(i - 1);
				if (i == 0 && dis[u] + 1 < ans) {
					ans = dis[u] + 1;
					fa1[0] = u;
				}
				if (dis[u] + 1 < dis[i + b[i]]) 
					dis[i + b[i]] = dis[u] + 1,
					fa1[i + b[i]] = u,
					fa2[i + b[i]] = i,
					Q.push(i + b[i]);
			}
				if (i == 0) break;
		}
	}
	if (ans != 0x3f3f3f3f) {
		printf("%d\n", ans);
		int u = fa1[0];
		vector<int> lis; lis.push_back(0);
		while (u != n) lis.push_back(fa2[u]), u = fa1[u];
		for (int i = lis.size() - 1; i >= 0; i--) printf("%d ", lis[i]);
		printf("\n");
	}
	else printf("-1\n");
}