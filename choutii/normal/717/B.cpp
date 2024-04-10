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

int main() {
	LL n, c0, c1;
	cin >> n >> c0 >> c1;
	if(!c0 || !c1) 
		return printf("%lld\n", (c0 + c1) * (n - 1)), 0;
	map<LL, LL> F;
	for (F[0] = 1, --n; n > 0; ) {
		pair<LL, LL> cur = *F.begin();
		if(cur.se <= n) {
			F.erase(F.begin());
			F[cur.fi + c0] += cur.se;
			F[cur.fi + c1] += cur.se;
		} else {
			F[cur.fi] -= n; 
			F[cur.fi + c0] += n;
			F[cur.fi + c1] += n;
		}
		n -= cur.se;
	}
	LL ans = 0;
	for (auto x : F)
		ans += x.fi * x.se;
	cout << ans << endl;
	return 0;
}