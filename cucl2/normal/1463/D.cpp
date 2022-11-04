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

int n;
int b[1 << 18];
bool is[1 << 19];

int inline getcnt() {
	int cnt = 0, res = 0;
	cont(i, n << 1) {
		if(!is[i]) ++cnt;
		else if(cnt) --cnt, ++res;
	}
	return res;
}

void solve() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", b + i);
	cont(i, n << 1) is[i] = 0;
	cont(i, n) is[b[i]] = 1;
	int lar = getcnt();
	reverse(is + 1, is + n + n + 1);
	int sml = n - getcnt();
	printf("%d\n", lar - sml + 1);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}