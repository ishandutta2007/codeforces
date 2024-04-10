#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back


using namespace std;

int n, m;
int a[105][105];

int best = 105;
vector <int> res, out;
multiset <pair<int, int>> secik;
int sum[105];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
			sum[j] += a[i][j];
		}

	for(int i = 1; i < n; ++i) {
		secik.clear();
		res.clear();
		for(int j = 1; j <= m; ++j)
			secik.insert({a[j][i] - a[j][n], j});
		int ja = sum[n] - sum[i];
		while(ja > 0) {
			auto it = secik.begin();
			ja += it->fi;
			res.pb(it->se);
			secik.erase(it);
		}
		if(res.size() < best) {
			best = res.size();
			out = res;
		}
	}

	printf("%d\n", best);
	for(auto it : out)
		printf("%d ", it);










	return 0;
}