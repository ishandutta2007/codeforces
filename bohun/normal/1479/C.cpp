#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

int l, r;
vector<tuple<int, int, int>> ans;

int main() {
	scanf("%d%d", &l, &r);
	r = r - l + 1;
	rep(i, 0, 19) 
		rep(j, 2, 22 - i - 1)
			ans.pb({j, 22 - i, 1 << max(0, i - 1)});
	r--;
	ans.pb({1, 22, 1});
	int add = 0;
	per(i, 0, 19)
		if (r >> i & 1) {
			ans.pb({1, 22 - i - 1, add + 1});
			add += (1 << i);
		}
	int n = 22;
	if (l > 1) ans.pb({n, n + 1, l - 1}), n++;
	printf("YES\n%d %d\n", n, sz(ans));
	for (auto [u, v, w] : ans)
		printf("%d %d %d\n", u, v, w);
	return 0;
}