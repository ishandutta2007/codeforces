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

int a[10];

int main() {
	int t; cin >> t;
	while (t--) {
		ll k; cin >> k;
		int ctr = 0;
		for (int i = 0; i < 7; ++i) {
			cin >> a[i];
			ctr += a[i];
		}
		ll best = 7 * k;
		for (int s = 0; s < 7; ++s) {
			ll rem = k, ans = 0;
			for (int j = s; j < 7 and rem; ++j) {
				rem -= a[j];
				++ans;
			}
			ll temp = max(0ll, (rem - 1) / ctr);
			ans += 7 * temp;
			rem -= temp * ctr;			
			for (int j = 0; j < 7 and rem; ++j) {
				rem -= a[j];
				++ans;
			}
			best = min(best, ans);
		}
		cout << best << '\n';
	}	
}