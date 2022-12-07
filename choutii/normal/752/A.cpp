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

int n, m, K;
int main() {
	int i;
	cin >> n >> m >> K;
	--K;
	
	cout << K / (2 * m) + 1 << " ";
	cout << K % (2 * m) /2 + 1 << " ";
	if((K % (2 * m) & 1)) 
		puts("R");
	else puts("L"); 
	return 0;
}