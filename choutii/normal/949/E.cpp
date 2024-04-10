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
typedef vector <int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

int n; VI ans, a, cur;

void dfs(VI a, int d) {
	if(d > (1 << 18))
		return;
	sort(ALL(a)); a.erase(unique(ALL(a)), a.end());
	for (int i = 0; i < SZ(a); i++)
		if(!a[i]) a.erase(a.begin() + i);
		
	if(!SZ(a)) {
		if(!SZ(ans) || SZ(cur) < SZ(ans))
			ans = cur;
		return;
	}
	for (int i = 0; i < SZ(a); i++) {
		if(a[i] & 1) {
			VI t = a; cur.pb(d);
			for (auto &x : t)
				if(x & 1)
					x = x - 1 >> 1;
				else
					x >>= 1;
			dfs(t, d << 1);
			cur.back() = -d;
			t = a;
			for (auto &x : t) 
				if(x & 1)
					x = x + 1 >> 1;
				else
					x >>= 1;
			dfs(t, d << 1);
			cur.pop_back();
			return;
		}
	}
	
	for (auto &x : a) 
		x >>= 1;
	dfs(a, d << 1);
	
}
int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		a.pb(read());
	dfs(a, 1);
	printf("%d\n", SZ(ans));
	for (auto x : ans)
		printf("%d ", x);
	return 0;
}