#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//

#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define read2(x, y) scanf("%d %d", &x, &y)

//
#define clr(a, n) memset(a, n, sizeof(a));
#define sqr(x) x*x
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 dsfgsdfgsdfgsdfgsdfgsdfg1
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const bool is_testing = 0;
const int p = 31;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 11;
const int MAXN = 2e5 + 7;

int n, kk;
map < int, map < int, bool> > g;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    srand(14123);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n >> kk;
    forn(i, n)
    {
        int z1, z2;
        cin >> z1 >> z2;
        g[z1][z2] = 1;
        g[z2][z1] = 1;
    }
    for (map < int, map < int, bool> >  :: iterator it = g.begin(); it != g.end(); it++)
    {
        int id = it -> first;
        cout << id << ": ";
        vec<int> t;
        for (map < int, map < int, bool> >  :: iterator it2 = g.begin(); it2 != g.end(); it2++)
            if (!g[id].count(it2 -> first) && it2 -> first != it -> first)
            {
                int k = 0;
                for (map < int, bool>  :: iterator it1 = g[id].begin(); it1 != g[id].end(); it1++)
                {
                    int id2 = it1 -> first;
                    if (g[id2].count(it2 -> first))
                        k++;
                }
                //cout << it2 -> first << ' ' << k << ' ' << it->second.size() << ' ' << (db)100 * (db)k / (db)it->second.size() << LN;
                if ((db)100 * (db)k / (db)it->second.size() >= kk)
                    t.pb(it2->first);
            }


        cout << t.size() << ' ';
        forn(i, t.size())
            cout << t[i] << ' ';
        cout << LN;
    }
}
//190660JM