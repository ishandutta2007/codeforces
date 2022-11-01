#include <bits/stdc++.h>

using namespace std; 

typedef pair<int, int> pii; 
typedef long long s64; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

const int MaxN = 800000 + 5; 

int n; 
pii a[MaxN]; 

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout); 
#endif

	read(n); 
	for (int i = 1; i <= n; ++i) {
		int x, y; 
		read(x), read(y); 
		a[i] = make_pair(x + y, x - y); 
	}

	sort(a + 1, a + n + 1); 

	static priority_queue<s64> heapL; 
	static priority_queue<s64, vector<s64>, greater<s64> > heapR; 
	heapL.push(0), heapR.push(0); 

	s64 ans = 0; 
	for (int i = 1; i <= n; ++i) {
		s64 x = a[i].first, y = a[i].second; 
		s64 l = heapL.top() - x, r = heapR.top() + x; 
		
		// cerr << x << ' ' << y << ':' << l << ' ' << r << '\n'; //

		if (y <= l) {
			ans += l - y; 

			heapR.push(heapL.top() - 2LL * x); 
			heapL.pop(); 
			heapL.push(y + x); 
			heapL.push(y + x); 
		} else if (y <= r) {
			heapL.push(y + x); 
			heapR.push(y - x); 
		} else {
			ans += y - r; 
			
			heapL.push(heapR.top() + 2LL * x); 
			heapR.pop(); 
			heapR.push(y - x); 
			heapR.push(y - x); 
		}
	}

	cout << ans / 2 << '\n'; 

	return 0; 
}