#include <bits/stdc++.h>

using namespace std;


map<long long, int> id;
const int MAXN = 2e5+5;
long long n, m, a, d, t[MAXN], ans;
int c, T;
vector<long long> V[MAXN], ID;
int main() {
	
	//freopen("in.txt", "r", stdin);
	scanf("%lld%lld%lld%lld", &n, &m, &a, &d);
	for (int i = 1; i <= m; i++) {
		long long x;scanf("%lld", &x);
		t[++c] = x;
	}
	
	sort (t + 1, t + c + 1);
	
	long long prv = -1;
	for (int i = 1; i <= c; i++) {
		
		long long cur = min(n, t[i] / a);
		if (cur != prv) {
			prv = cur;//min(n, t[i] / a);
			ID.push_back(prv);
			id[prv] = ++T;
		}
		V[id[prv]].push_back(t[i]);
	}
	
	
	long long cur = 0;
	
	while (1) {
		long long pro = min(n, cur / a);
		if (pro == n) {
			int p = id[n];
			if (!p) break;
			while (1) {
				int pos = upper_bound(V[p].begin(), V[p].end(), cur) - V[p].begin();
				if (pos == V[p].size()) break;
				ans++;
				cur = V[p][pos] + d;
			}
			break;
		}
		
		int p = id[pro];
		if (p) {
			V[p].push_back(a * (pro + 1));
			while (1) {
				int pos = upper_bound(V[p].begin(), V[p].end(), cur) - V[p].begin();
				if (pos == V[p].size()) break;
				ans++;
				cur = V[p][pos] + d;
			}
			continue;
		}
		
		int pos = upper_bound(ID.begin(), ID.end(), pro) - ID.begin();
		
		long long lo = pro + 1, hi = (pos == ID.size() ? n : ID[pos]);
		long long step = d / a + 1;
		long long eat = (hi - lo) / step + 1;
		ans += eat;
		long long st = lo + (eat - 1) * step;
		cur = a * st + d;
	}
	printf("%lld\n", ans);
	return 0;
}