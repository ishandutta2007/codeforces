#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define cin_desync()                      \
	do {                                  \
		ios_base::sync_with_stdio(false); \
		cin.tie(0);                       \
	} while (0)                           \

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}

#else
#define trace(...)
#endif // ifndef ONLINE_JUDGE

const int max_N = 1e5 + 10;
int a[max_N], b[max_N];
map<int, vector<int>> ava;

int main() {
	cin_desync();
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}

	for (int i = 1; i <= n; ++i) {
		ava[a[i]].push_back(b[i]);
	}

	vector<int> rem;
	for (auto &p : ava) {
		sort(begin(p.second), end(p.second));

		if (!p.second.empty()) {
			rem.insert(rem.end(), begin(p.second), end(p.second) - 1);
		}
	}
	sort(rem.begin(), rem.end());

	int ndone = 0;
	for (int i = 1; i <= k; ++i) {
		ndone += ava[i].empty();
	}

	ll ans = 0;
	for (int i = 0; i < ndone; ++i) {
		ans += rem[i];
	}

	cout << ans << endl;
}