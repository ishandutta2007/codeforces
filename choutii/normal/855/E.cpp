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
typedef vector<int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

LL l, r; int b;

int a[64], m;

LL f[11][64][1 << 10][2];

LL dp(int cur, int mask, int pre, int open) {
	if(!cur) 
		return !mask;
	if(!open && f[b][cur][mask][pre] != -1)
		return 	f[b][cur][mask][pre];
	LL u = open ? a[cur] : b - 1;
	LL sum = 0;
	if(pre)
		sum += dp(cur - 1, mask, 1, open && !a[cur]);
	else
		sum += dp(cur - 1, mask ^ 1, 0, open && !a[cur]);
	for (int i = 1; i <= u; i++)
		sum += dp(cur - 1, mask ^ (1 << i), 0, open && i == a[cur]); 
	if(open)
		return sum;
	else
		return f[b][cur][mask][pre] = sum;
}

LL dp(LL n) {
	for (m = 0; n; n /= b)
		a[++m] = n % b;
	return dp(m, 0, 1, 1);
}
int main() {
	memset(f, -1, sizeof(f));
	for (int T = read(); T--; ) {
		scanf("%d%lld%lld", &b, &l, &r);
		printf("%lld\n", dp(r) - dp(l - 1));
	} 
	return 0;
}