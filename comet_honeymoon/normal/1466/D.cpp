#include<bits/stdc++.h>
#define ll long long
using namespace std;

int T, n;
int w[100005], deg[100005];
ll ans[100005];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &w[i]), deg[i] = 0;
		for(int i = 1; i < n; i++) {
			int u, v; scanf("%d%d", &u, &v);
			deg[u]++, deg[v]++;
		}
		ans[1] = 0; for(int i = 1; i <= n; i++) ans[1] += w[i];
		vector<int> pos;
		for(int i = 1; i <= n; i++)
		for(int j = 1; j < deg[i]; j++) pos.push_back(w[i]);
  		sort(pos.begin(), pos.end(), greater<int>());
  		for(int i = 0; i < pos.size() && i < n - 2; i++)
  			ans[i + 2] = ans[i + 1] + pos[i];
  		for(int i = 1; i < n; i++) printf("%lld ", ans[i]); printf("\n");
	}
}