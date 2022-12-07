#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 101234;

int n, d, b; LL a[MaxN];

bool chk(int mid) {
	int need = b;
	for (int i = 1, j = mid + 1; i <= n; i++) {
		for (int cur = a[i]; cur;) {
			if(abs(i - j) / d + (abs(i - j) % d != 0) > min(j, n + 1 - j)) 
				break;
			int u = min(cur, need);
			cur -= u, need -= u;
			if(!need) 
				need = b, j++;
			if(j >= n - mid + 1) return 1; 
		}
	}
	return 0;
} 
int main() {
	scanf("%d%d%d", &n, &d, &b);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	int L = 0, R = n + 1 >> 1, ans = 0;
		
	while(L <= R) {
		int mid = L + R >> 1;
		if(chk(mid))
			ans = mid, R = mid - 1;
		else
			L = mid + 1;
	}
	cout << ans << endl;
	return 0;
}