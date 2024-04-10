/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

const ll yjsp = 114514ll * 1919810 * 114514;
int n, ts;
int a[1 << 17];
char f[1 << 17];
char tmp[5]; // ASCII Order: * + -
ll dp[105];
int pre[105];

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", a + i);
	scanf("%s", tmp); ts = strlen(tmp);
	sort(tmp, tmp + ts);
	if(tmp[0] != '*') {
		if(tmp[0] != '+') {
			cont(i, n) printf("%d%c", a[i], "-\n"[i == n]);
		} else {
			cont(i, n) printf("%d%c", a[i], "+\n"[i == n]);
		}
	} else {
		if(!tmp[1]) {
			cont(i, n) printf("%d%c", a[i], "*\n"[i == n]);
		} else if(tmp[1] != '+') {
			bool zr = 0;
			cont(i, n) {
				if(i > 1) putchar("*-"[!a[i]]);
				printf("%d", a[i]);
			}
			puts("");
		} else {
			circ(i, 2, n) f[i] = '+';
			int cr = 1;
			while(cr <= n) {
				while(cr <= n && !a[cr]) ++cr;
				if(cr > n) break;
				int l = cr, r;
				while(a[cr]) ++cr;
				r = cr - 1;
				while(l <= r && a[l] == 1) ++l;
				while(l <= r && a[r] == 1) --r;
				ll mul = 1;
				circ(i, l, r) {
					mul *= a[i];
					if(mul > yjsp) mul = yjsp;
				}
				if(mul == yjsp) {
					circ(i, l + 1, r) f[i] = '*';
					continue;
				}
				vector<pair<ll, pair<int, int> > > vec;
				int cur = l;
				while(cur <= r) {
					int nl = cur;
					if(a[nl] == 1) {
						while(cur <= r && a[cur] == 1) ++cur;
						vec.pub(mak(cur - nl, mak(nl, cur - 1)));
					} else {
						ll mul = 1;
						while(cur <= r && a[cur] > 1) {
							if(cur != nl) f[cur] = '*';
							mul *= a[cur], ++cur;
						}
						vec.pub(mak(mul, mak(nl, cur - 1)));
					}
				}
				cont(i, SZ(vec)) dp[i] = -INF;
				loop(i, SZ(vec)) {
					if(dp[i + 1] < dp[i] + vec[i].first) {
						dp[i + 1] = dp[i] + vec[i].first;
						pre[i + 1] = i;
					}
					if(!(i & 1)) {
						ll mul = 1;
						circ(j, i, SZ(vec) - 1) {
							if(!(j & 1)) {
								mul *= vec[j].first;
								if(dp[j + 1] < dp[i] + mul) {
									dp[j + 1] = dp[i] + mul;
									pre[j + 1] = i;
								}
							}
						}
					}
				}
				int now = SZ(vec);
				while(now) {
					int l = pre[now], r = now - 1;
					now = pre[now];
					if(l < r) {
						circ(i, vec[l].second.first + 1, vec[r].second.second) {
							f[i] = '*';
						}
					}
				}
			}
			printf("%d", a[1]);
			circ(i, 2, n) printf("%c%d", f[i], a[i]);
			puts("");
		}
	}
	return 0;
}