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

const int max_N = 2e5 + 10;
int p[max_N];

int main()
{
	cin_desync();
	int c;
	cin >> c;

	while(c--) {
		int n, m; ll t;
		cin >> n >> m >> t;

		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
		}

		int low = 1, high = min(ll(max_N), t), bc = 0, best = 1;
		while(low <= high) {
			int d = (low + high) / 2;

			ll tot = 0, slb = 0;
		   	int nj = 0, njb = 0;
			bool fin_time = false;
			for (int i = 1; i <= n; ++i) {
				if (p[i] > d) {
					continue;
				}
				if (p[i] + tot > t) {
					fin_time = true;
					break;
				}
				tot += p[i]; slb += p[i];
				nj++; njb++;

				if (njb == m) {
					tot += slb;
					njb = 0;
					slb = 0;
				}
			}

			if (nj > bc) {
				bc = nj, best = d;
			}

			if (fin_time) {
				high = d - 1;
			} else {
				low = d + 1;
			}
		}

		cout << bc << ' ' << best << '\n';
	}
}