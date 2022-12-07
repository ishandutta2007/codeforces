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

const int MaxN = 5123;

int n, sA[MaxN], sB[MaxN]; char s[MaxN];

int main() {
	int i;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(i = 1; i <= n; i++){
		sA[i] = sA[i - 1] + (s[i] == 'a');
		sB[i] = sB[i - 1] + (s[i] == 'b');
	}
	int j;
	int ans = 0;
	for(i = 1; i <= n; i++)
		for(j = i; j <= n; j++)
			cmax(ans, sA[i] + sA[n] - sA[j - 1] + sB[j] - sB[i - 1] - (i == j && s[i] == 'a'));
	cout << ans;
	return 0;
}