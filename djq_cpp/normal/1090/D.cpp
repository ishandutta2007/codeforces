#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

int n, m, u, v;
vector<int> G[100005];

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, m) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep1(i, n) {
		G[i].push_back(0);
		G[i].push_back(n + 1);
		G[i].push_back(i);
		sort(G[i].begin(), G[i].end());
	}
	u = -1;
	rep1(i, n) if(G[i].size() <= n + 1) {
		u = i;
		rep(j, G[i].size() - 1) if(G[i][j] + 1 < G[i][j + 1]) v = G[i][j] + 1;
		break;
	}
	if(u == -1) printf("NO\n");
	else {
		printf("YES\n");
		int tot = 3;
		rep1(i, n) if(i == u) printf("1 ");
		else if(i == v) printf("2 ");
		else printf("%d ", tot ++);
		printf("\n");
		tot = 3;
		rep1(i, n) if(i == u || i == v) printf("1 ");
		else printf("%d ", tot ++);
		printf("\n");
	}
	return 0;
}