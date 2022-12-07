#include <bits/stdc++.h>

#define fir first
#define sec second
#define MP make_pair

using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

int main() {
	int n, i;
	cin >> n;
	LL p = (LL) n * (n + 1) / 2;
	cout << (p & 1) << endl; p /= 2;
	vector<int> ans;
	for(i = n; i; i--) {
		if(p >= i) {
			ans.push_back(i); p -= i;
		}
	}
	cout << ans.size() << " "; for(auto x : ans) cout << x << " "; 
	return 0;
}