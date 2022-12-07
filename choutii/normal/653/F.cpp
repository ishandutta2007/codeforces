#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

const int MaxN = 501234, Logn = 20;

int n; char s[MaxN];

namespace rmq {
	int mn[MaxN][Logn], lg[MaxN];
	
	void init(int n, int *a) {
		for (int i = 2; i <= n; i++)
			lg[i] = lg[i >> 1] + 1;
		for (int i = 1; i <= n; i++)
			mn[i][0] = a[i];
		for (int l = 1; l < Logn; l++) 
			for (int i = 1; i + (1 << l) - 1 <= n; i++) 
				mn[i][l] = min(mn[i][l - 1], mn[i + (1 << l - 1)][l - 1]); 
	}
	
	int qmin(int l, int r) {
		int x = lg[r - l + 1];
		return min(mn[l][x], mn[r - (1 << x) + 1][x]);
	}
} 

namespace SuffixArray {
	int rk[MaxN], sa[MaxN], h[MaxN];
	pair<pii, int> t[MaxN];
	void build(char *s) {
		for (int i = 1; i <= n; i++)
			rk[i] = s[i];
		for (int l = 0; l < Logn; l++) {
			for (int i = 1; i <= n; i++)
				t[i] = mp(mp(rk[i], rk[i + (1 << l)]), i);
			sort(t + 1, t + n + 1);
			int cur = 0;
			for (int i = 1; i <= n; i++) {
				rk[t[i].se] = cur + 1; 
				cur += (t[i].fi != t[i + 1].fi);
			}
			if(cur == n) break;
		}
		for (int i = 1; i <= n; i++)
			sa[rk[i]] = i;
		for (int i = 1, l = 0; i <= n; i++) {
			if(rk[i] == 1) continue;
			cmax(--l, 0); 
			for (int j = sa[rk[i] - 1]; s[i + l] == s[j + l]; ++l); 
			h[rk[i]] = l;
		}
	}
	
	int s[MaxN]; pii S[MaxN];
	void solve(char *a) {
		for (int i = 1; i <= n; i++) {
			s[i] = s[i - 1] + (a[i] == '(' ? 1 : -1);
			S[i] = mp(s[i], i);
		}
		rmq::init(n, s); sort(S + 1, S + n + 1);
		LL ans = 0;
		for (int i = 1; i <= n; i++) {
			if(a[i] == ')') continue;
			int l = i, r = n; 
			while(l < r) {
				int m = l + r + 1 >> 1;
				if(rmq::qmin(i, m) < s[i - 1])
					r = m - 1;
				else l = m;
			}
			int cur = l;
			if(cur - i + 1 <= h[rk[i]]) continue;
			ans += lower_bound(S + 1, S + n + 1, mp(s[i - 1], cur + 1)) - S;
			ans -= lower_bound(S + 1, S + n + 1, mp(s[i - 1], i + h[rk[i]])) - S;
		}
		cout << ans << endl;
	}
}

int main() {
	scanf("%d%s", &n, s + 1);
	SuffixArray::build(s);
	SuffixArray::solve(s);
	return 0;
}