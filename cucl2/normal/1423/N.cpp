/**** Hyperhydrochloric Acid ****\
|                H    H          |
|                 \  /           |
|             H    Cl            |
|              \  /              |
|   H           Cl               |
|    \          |                |
|     Cl        Cl        H      |
|    /  \      /  \      /       |
|   H    Cl--Cl    Cl--Cl    H   |
|       /      \  /      \  /    |
|      H        Cl        Cl     |
|               |           \    |
|               H            H   |
\********************************/
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

int n, k;
int u[1 << 20], v[1 << 20];
bool sel[1 << 14];
vector<pair<int, int> > nei[1 << 14], egs[1 << 14];
bool lgl[1 << 21];
int val[1 << 20], F[1 << 20];

int main() {
	scanf("%d%d", &n, &k);
	cont(i, k) {
		int a, b; scanf("%d%d", &a, &b);
		u[i] = a; v[i] = b;
		if(a < b) swap(a, b); // make a > b
		nei[a].pub(mak(b, i));
		egs[a].pub(mak(b, i));
		egs[b].pub(mak(a, i));
		val[i] = 1;
	}
	cont(i, n) {
		int fix = 0;
		loop(j, SZ(nei[i])) {
			int to = nei[i][j].first, eg = nei[i][j].second;
			if(sel[to]) {
				sel[to] = 0;
				++val[eg];
			}
		}
		loop(j, SZ(egs[i])) fix += val[egs[i][j].second];
		circ(j, fix - SZ(nei[i]), fix) lgl[j] = 0;
		loop(j, SZ(nei[i])) lgl[F[nei[i][j].first]] = 1;
		// Try to undo opers
		loop(j, SZ(nei[i])) {
			int to = nei[i][j].first, eg = nei[i][j].second;
			if(lgl[fix]) {
				sel[to] = 1;
				--val[eg]; --fix;
			} else {
				break;
			}
		}
		F[i] = fix;
	}
	int all = 0;
	cont(i, n) all += sel[i];
	printf("%d\n", all);
	cont(i, n) if(sel[i]) printf("%d\n", i);
	cont(i, k) printf("%d %d %d\n", u[i], v[i], val[i]);
	return 0;
}

/**
 * 8:50-9:50, 1h
 * 9:50-10:10, 20min
 * 
 *   1
 *   1
 *   S S 
 *    1 1
 *   S  S + 1  0..S 
 */