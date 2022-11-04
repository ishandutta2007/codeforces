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

int n, q;
set<pair<int, pair<int, char> > > st;

int main() {
    scanf("%d%d", &n, &q);
    st.insert(mak(0, mak(0, 'U')));
    st.insert(mak(n + 1, mak(0, 'L')));
    while(q--) {
        int x, y; char c;
        scanf("%d%d %c", &x, &y, &c);
        __typeof(st.begin()) it = st.lower_bound(mak(x, mak(0, 0)));
        if(it->first == x) {
            puts("0");
            continue;
        }
        if(c == 'L') --it;
        int ans = abs(x - it->first);
        if(it->second.second == c) ans += it->second.first;
        printf("%d\n", ans);
        st.insert(mak(x, mak(ans, c)));
    }
    return 0;
}

/**
 * 
 *   set x 
 *   set  x  x 
 *  
 *  
 */