#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 1e5 + 10;

int n, k, sec[MAXN], x[MAXN], r[MAXN], f[MAXN];
ordered_set st[MAXN];

bool cmp(int u, int v){return r[u] > r[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> x[i] >> r[i] >> f[i];
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	ll ans = 0;
	for (int i = 0; i < n; i++){
		int v = sec[i];
		for (int j = max(0, f[v]-k); j <= f[v] + k; j++)
			ans += st[j].order_of_key(x[v]+r[v] + 1) - st[j].order_of_key(x[v] - r[v]);
		st[f[v]].insert(x[v]);
	}
	cout << ans << "\n";
	return 0;
}