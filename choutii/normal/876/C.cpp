#include <bits/stdc++.h>

#define fir first
#define sec second
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

int n; vector<int> ans; int f[1000];
int main() {
	int i;
	cin >> n;
	
	for(i = 1; i < 90; i++) {
		int x = n - i, z; if(x < 0) break;
		
		z = x;
		while(z) x += z % 10, z /= 10;
		if(x == n) ans.push_back(n - i);
	}
	
	sort(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
	for(i = 0; i < ans.size(); i++) cout << ans[i] << endl;
	return 0;
}