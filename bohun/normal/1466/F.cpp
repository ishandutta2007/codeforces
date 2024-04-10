#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	
	
const int N = 1 << 20;
const int P = 1e9 + 7;

int n, m, p[N], ans = 1, cnt[N];
vector<int> v;

int find(int x) {
	return p[x] = (x == p[x] ? x : find(p[x]));
}

void merge(int a, int b) {
	a = find(a); b = find(b);
	cnt[a] += cnt[b];
	p[b] = a;
}
	
int main() {
	scanf("%d%d", &n, &m);
	iota(p + 1, p + m + 1, 1);
	for (int i = 0; i < n; ++i) {
		int k, a, b;
		scanf("%d", &k);
		if (k == 1) {
			scanf("%d", &a);
			if (cnt[find(a)] == 0) {
				cnt[find(a)]++;
				ans = 2LL * ans % P;
				v.push_back(i + 1);
			}
		}
		else {
			scanf("%d%d", &a, &b);
			if (find(a) != find(b) && !(cnt[find(a)] && cnt[find(b)])) {
				merge(a, b);
				ans = 2LL * ans % P;
				v.push_back(i + 1);
			}
		}
	}
	printf("%d %d\n", ans, (int)v.size());
	for (auto x : v)
		printf("%d ", x);
		
	return 0;
}