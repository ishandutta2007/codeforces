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

struct Shuffle {
    vector<int> S;
    Shuffle() {}
    Shuffle(int len) {S.resize(len); iota(all(S), 0);}
    friend inline Shuffle operator*(const Shuffle &a, const Shuffle &b) {
        static Shuffle res; res = Shuffle(SZ(a.S));
        loop(i, SZ(a.S)) {
            res.S[i] = b.S[a.S[i]];
        }
        return res;
    }
};

int n, m;
char s[1 << 20], t[1 << 20];

int main() {
    scanf("%s", s); n = strlen(s);
    scanf("%d", &m);
    cont(i, m) {
        int k, d; scanf("%d%d", &k, &d);
        Shuffle a(n), b(n);
        loop(j, n) a.S[j] = (j + n - 1) % n;
        vector<vector<int> > ms(d);
        loop(j, k) ms[j % d].pub(j);
        int cnt = 0;
        loop(j, d) loop(k, SZ(ms[j])) {
            b.S[ms[j][k]] = cnt++;
        }
        a = b * a;
        b = Shuffle(n);
        int tms = n - k + 1;
        while(tms) {
            if(tms & 1) b = b * a;
            tms >>= 1; a = a * a;
        }
        loop(j, n) t[b.S[j]] = s[j];
        loop(j, n) s[j] = t[(j + k - 1) % n];
        printf("%s\n", s);
    }
    return 0;
}

/**
 * 
 *   Shuffle * 
 *   Shuffle
 *    Shuffle k  d 
 *    Shuffle
 *   Shuffle  n - k + 1  k - 1 
 *   O(nm log n)
 */