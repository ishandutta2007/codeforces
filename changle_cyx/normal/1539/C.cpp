#include <bits/stdc++.h>

using namespace std; 

typedef long long s64; 

#define range(x) x.begin(), x.end()

const int MaxN = 200000 + 5; 

int n; 
s64 k, x, a[MaxN]; 

int main() {
	scanf("%d%lld%lld", &n, &k, &x); 
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i); 

	sort(a + 1, a + n + 1); 

	int ans = 1; 

	vector<s64> t; 
	for (int i = 2; i <= n; ++i) {
		if (a[i] - a[i - 1] > x) {
			++ans; 
			t.push_back((a[i] - a[i - 1] - 1) / x); 
		}
	}

	sort(range(t)); 
	for (s64 v : t) if (k >= v) k -= v, --ans; 

	cout << ans << '\n'; 

	return 0; 
}