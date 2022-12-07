#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N(1e5 + 11);
int inf(1e9 + 11);
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<pair<pair<int, int>, int> > edges;
	for(int i(0); i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edges.push_back(make_pair(make_pair(x, y), z));
	}
	static bool f[N];
	for(int i(0); i < k; i++) {
		int x;
		scanf("%d", &x);
		f[x] = true;
	}
	int ans(inf);
	for(int i(0); i < m; i++) {
		if(f[edges[i].first.first] != f[edges[i].first.second]) {
			ans = min(ans, edges[i].second);
		}
	}
	if(ans == inf) {
		ans = -1;
	}
	printf("%d\n", ans);
}