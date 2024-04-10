#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;

typedef long long LL;

template <typename T> inline bool cmin(T & a, const T &b) { return a > b ? a = b, 1 : 0; }
template <typename T> inline bool cmax(T & a, const T &b) { return a < b ? a = b, 1 : 0; }

const int MaxN = 1001234;
int n, a[MaxN], b[MaxN];
int main(){
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf("%d", a + i);
	LL ans = 0, t = 0;
	for(i = 1; i <= n; i++) {
		t += i - b[a[i]];
		ans += t;
		b[a[i]] = i;
	}
	
	cout << (ans * 2 - n)/ (double)((LL) n * n);
	return 0;
}