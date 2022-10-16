#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<long long, long long> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long a, b, h, w, n;
vector<int> m(n);

map<pii, int> memo[50];

int f(long long x, long long y, int pos) {
	if (x >= a && y >= b) return 0;
	if (pos == n) return n + 1;
	x = min(x, a);
	y = min(y, b);
	if (memo[pos].count(pii(x, y)))
		return memo[pos][pii(x, y)];

	int res = n + 1;
	if (x < a) res = min(res, f(x * m[pos], y, pos + 1) + 1);
	if (y < b) res = min(res, f(x, y * m[pos], pos + 1) + 1);

	return memo[pos][pii(x, y)] = res;
}

bool solve() {
	cin >> a >> b >> h >> w >> n;
	m.resize(n);
	for (int i = 0; i < n; ++i) cin >> m[i];
	sort(m.begin(), m.end());
	reverse(m.begin(), m.end());
	
	int res = n + 1;

	res = min(res, f(h, w, 0));
	res = min(res, f(w, h, 0));

	if (res > n) res = -1;
	cout << res << endl;

	return false;
}

int main() {
	
    while (solve());
    
    return 0;
}