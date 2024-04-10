/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
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
char s[1 << 19];
char tmp[1 << 19];

void solve() {
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	cont(i, k) {
		tmp[i] = '?';
		range(j, i, n, k) {
			if(s[j] != '?') {
				if(tmp[i] == '?') tmp[i] = s[j];
				else if(tmp[i] != s[j]) return void(puts("NO"));
			}
		}
	}
	int cnto = 0, cnti = 0;
	cont(i, k) {
		if(tmp[i] == '0') cnto++;
		else if(tmp[i] == '1') cnti++;
	}
	if(cnto > k / 2 || cnti > k / 2) puts("NO");
	else puts("YES");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}