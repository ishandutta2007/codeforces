/* by Natsu Kinmoe */
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

int a[1 << 18], n, m;
int l[1 << 18], r[1 << 18];
int pos[1 << 18];

int main() {
    scanf("%d", &n); m = n << 1;
    cont(i, m) {
        char ch; scanf(" %c", &ch);
        if(ch == '+') a[i] = 0;
        else {
            scanf("%d", a + i);
            pos[a[i]] = i;
        }
        if(i > 1) l[i] = i - 1;
        if(i < m) r[i] = i + 1;
    }
    cont(i, n) {
        int p = pos[i];
        int q = l[p];
        if(a[q] || !q) return puts("NO"), 0;
        a[q] = -i;
        int np = r[p], nq = l[q];
        if(nq) r[nq] = np;
        if(np) l[np] = nq;
    }
    puts("YES");
    cont(i, m) if(a[i] < 0) printf("%d ", -a[i]);
    return 0;
}