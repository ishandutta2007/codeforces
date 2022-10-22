#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;		
 
const int N = 1e5 + 5;

int n, q, typ, x; 
multiset<int> gaps;
set <int> setik;

void remove(int a) {
	auto it = setik.lower_bound(a);
	if (it != setik.begin())
		gaps.erase(gaps.find(a - *prev(it)));
	if (next(it) != setik.end())
		gaps.erase(gaps.find(*next(it) - a));
	if (it != setik.begin() && next(it) != setik.end())
		gaps.insert(*next(it) - *prev(it));
	setik.erase(a);
}

void add(int a) {
	setik.insert(a);
	auto it = setik.lower_bound(a);
	if (it != setik.begin() && next(it) != setik.end())
		gaps.erase(gaps.find(*next(it) - *prev(it)));
	if (it != setik.begin())
		gaps.insert(a - *prev(it));
	if (next(it) != setik.end())
		gaps.insert(*next(it) - a);
}
 
int main() {
	scanf ("%d%d", &n, &q);
	rep(i, 1, n) {
		scanf ("%d", &x);
		add(x);
	}
	rep(i, 0, q) {
		if (i) {
			scanf ("%d%d", &typ, &x);
			if (!typ) remove(x);
			else add(x);
		}
		int ans = 0;
		if (!gaps.empty())
			ans = *prev(setik.end()) - *setik.begin() - *prev(gaps.end());
		printf ("%d\n", ans);
	}
	
	return 0;
}