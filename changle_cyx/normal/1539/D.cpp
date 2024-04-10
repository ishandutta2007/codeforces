#include <bits/stdc++.h>

using namespace std; 

typedef long long s64; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar()));
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

const int MaxN = 100000 + 5; 

int n; 
s64 suma; 
pair<s64, s64> a[MaxN]; 

int main() {
	read(n); 
	for (int i = 1; i <= n; ++i) read(a[i].first), read(a[i].second), suma += a[i].first; 

	sort(a + 1, a + n + 1, [](pair<s64, s64> x, pair<s64, s64> y) {
		return x.second < y.second; 
	}); 

	// if (suma < a[1].second) return printf("%lld\n", suma * 2), 0; //

	s64 cur = 0, ans = 0; 
	for (int i = 1, p = n; i <= p; ++i) {
		while (p >= i && cur < a[i].second) {
			s64 d = a[i].second - cur; 

			if (a[p].first <= d) {
				s64 r = a[p].first; 
				ans += r << 1, cur += r, a[p--].first = 0;  
			} else {
				a[p].first -= d, ans += d << 1, cur += d; 
			}
		}
		cur += a[i].first, ans += a[i].first; 
	}

	cout << ans << '\n'; 	
	return 0; 
}