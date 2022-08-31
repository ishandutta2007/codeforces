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

const int N = 110;

pii hero[N];
int bak_a[N], a[N];
bool done[N];

void solve(int p, int n, int m);

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int s, h;
		cin >> s >> h;
		hero[i] = {s, h};
	}
	for (int i = 1; i <= n; ++i) {
		cin >> bak_a[i];
	}
	for (int i = 1; i <= n; ++i) {
		solve(i, n, m);
	}
	cout << -1 << endl;
}

void solve(int p, int n, int m) {
	memset(done, 0, sizeof(done));
	for (int i = 1; i <= n; ++i) {
		a[i] = bak_a[i];
	}
	vector<int> ans;
	for (int i = 0; i < m; ++i) {
		bool ok = false;
		for (int j = 1; j <= m; ++j) {
			if (!done[j]) {
				ok = true;
				int h = hero[j].second, s = hero[j].first;
				while (true) {
					if (s < p) {
						++s;
					} else if (s > p) {
						--s;
					}
					if (a[s] < 0) {
						int m = -a[s];
						if (m > h) {
							ok = false;
							break;
						} else {
							h -= m;
						}
					} else if (a[s] > 0) {
						h += a[s];
					}

					if (s == p) {
						break;
					}
				}
				if (ok) {
					int s = hero[j].first;
					while (true) {
						if (s < p) {
							++s;
						} else if (s > p) {
							--s;
						}
						a[s] = 0;

						if (s == p) {
							break;
						}
					}
					ans.push_back(j);
					done[j] = true;
					break;
				}
			}
		}
		if (!ok) {
			return;
		}
	}
	cout << p << endl;
	for (auto &i : ans) {
		cout << i << ' ';
	}
	cout << endl;
	exit(0);
}