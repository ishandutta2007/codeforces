#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
static inline unsigned long long rdtsc() { unsigned long long d; __asm__ __volatile__ ("rdtsc" : "=A" (d) ); return d; }
using namespace std;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
const int inf = (int)1e9;
const ld eps = 1e-9;
/*--- main part --- */
#define TASK "a"
const int maxn = (int)1e5 + 10000;
const int maxm = 15;
const int L = 300;
char s[maxn][maxm];
int n, m;
int N;
int d[maxn][maxm];
void calc(int id)
{
    forn(i, L){
        int x = id * L + i;
        forn(j, m) d[x][j] = -1;
        if (s[x][0] == '<') d[x][0] = m + x;
        if (m > 0 && s[x][m - 1] == '>') d[x][m - 1] =m+n+x;
        forn(j, m) if (s[x][j] == '^'){
            if (i == 0) d[x][j] = j;
            else d[x][j] = d[x - 1][j];
        }
        for (int j = 1; j < m; ++j) if (s[x][j] == '<') d[x][j] = d[x][j - 1];
        for (int j = m - 2; j >= 0; --j) if (s[x][j] == '>') d[x][j] = d[x][j + 1];
    }
}
void init()
{
    N = (n + L - 1) / L;
    forn(i, N) calc(i);
}
int GET(int x, int y)
{
    while (x >= 0)
    {
        int next = d[x][y];
        if (next==-1) return -1;
        if (next >= m) return next;
        int x2 = x - (x % L) - 1;
        int y2 = next;
        x = x2, y = y2;
    }
    return y;
}
pi getPair(int x)
{
    if (x == -1) return mp(-1, -1);
    if (x < m) return mp(0, x + 1);
    if (x < m + n) return mp(x - m + 1, 0);
    return mp(x - m - n + 1, m + 1);
}
int main()
{
//	freopen("input.txt","r",stdin);
    memset(s, '^', sizeof s);
    int q;
    scanf("%d%d%d", &n, &m, &q);
    forn(i, n) scanf("%s", s[i]);
    init();
    forn(i, q)
    {
        char t[2];
        scanf("%s", t);
        if (t[0] == 'A')
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x -= 1, y -= 1;
            int id = GET(x, y);
            pi res = getPair(id);
            printf("%d %d\n", res.fs, res.sc);
        }
        else if (t[0] == 'C')
        {
            int x, y;
            scanf("%d%d%s", &x, &y, t);
            x -= 1, y -= 1;
            s[x][y] = t[0];
            calc(x / L);
        }
    }
    return 0;
}