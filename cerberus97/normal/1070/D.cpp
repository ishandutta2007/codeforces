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

const int N = 2e5 + 100;
int n, k;
ll a[N];

int main()
{
	cin_desync();
	cin >> n >> k;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll sum = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > k) {
			ans += (a[i] / k);
			a[i] %= k;
		}
		if(a[i] > 0) {
			ans ++;
			a[i + 1] = max(0ll, a[i + 1] - (k - a[i]));
		}
	}
	cout << ans << endl;
}