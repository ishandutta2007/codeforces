#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 5123;
int n, m, s[MaxN][MaxN];
bool a[MaxN][MaxN];
int main() {
	int i, j, K;
	n = inp(); m = inp();
	for(i = 1; i <= n; i++){
		char ch[MaxN]; scanf("%s", ch);
		for(j = 0; j < m; j++) a[i][j + 1] = ch[j] - '0';
	} 
	int o = max(n, m);
	for(i = 1; i <= n + o; i++)
		for(j = 1; j <= m + o; j++){
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]; 
		}
	
	int ans = ~0U >> 1;
	for(K = 2; K <= o; K++) {
		int t = 0;
		for(i = 1; i <= n; i += K)
			for(j = 1; j <= m; j += K) {
				int u = s[i + K - 1][j + K - 1] - s[i - 1][j + K - 1] - s[i + K - 1][j - 1] + s[i - 1][j - 1];
				t += min(u, K * K - u);
			}
		cmin(ans, t);
	}
	cout << ans;
	return 0;
}