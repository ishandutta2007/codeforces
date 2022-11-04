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

int n, K, M;
string s[15];
string t[1 << 19];
int nxt[1 << 19][15], pr[1 << 19];
int f[1 << 15][155];

int main() {
	ios::sync_with_stdio(0);
	cin >> n; M = n * (n - 1) >> 1;
	loop(i, n) cin >> s[i];
	int m; cin >> m;
	int mp = -1, mi = -1;
	cont(T, m) {
		cin >> K;
		cont(i, K) cin >> t[i];
		memset(pr, Inf, sizeof(pr));
		loop(j, n) nxt[K + 1][j] = Inf;
		range(i, K, 1, -1) {
			loop(j, n) if(t[i] == s[j]) pr[j] = i;
			loop(j, n) nxt[i][j] = pr[j];
		}
		memset(f, Inf, sizeof(f));
		f[0][0] = 0;
		loop(i, (1 << n) - 1) loop(j, M + 1) {
			if(f[i][j] == Inf) continue;
			loop(k, n) if(!((i >> k) & 1)) {
				int to = nxt[f[i][j] + 1][k];
				int add = __builtin_popcount(i & ~((1 << k) - 1));
				f[i | (1 << k)][j + add] = min(f[i | (1 << k)][j + add], to);
			}
		}
		loop(j, M + 1) if(f[(1 << n) - 1][j] != Inf && M + 1 - j > mp) {
			mp = M + 1 - j, mi = T; break;
		}
	}
	if(!~mp) {
		cout << "Brand new problem!\n";
		return 0;
	}
	cout << mi << endl;
	cout << "[:";
	loop(i, mp) cout << "|";
	cout << ":]\n";
	return 0;
}
/**
 * 
 *  
 *   f(i, j)  i  j
 *   next(i, j)  i  j 
 *  
 */