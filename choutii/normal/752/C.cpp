#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

int n; string s;
int main() {
	int i;
	cin >> n;
	cin >> s;
	int X = 0, Y = 0, ans = 0;
	for(i = 0; i < s.size(); i++){
		char c = s[i];
		int x, y;
		if(c == 'L') x = -1, y = 0;
		if(c == 'R') x = 1, y = 0;
		if(c == 'U') x = 0, y = 1;
		if(c == 'D') x = 0, y = -1;
		
		if(x * X == -1 || y * Y == -1)
			X = Y = 0, ++ans;
			
		X = X ? X : x;
		Y = Y ? Y : y; 
	}
	
	cout << ans + 1;
	return 0;
}