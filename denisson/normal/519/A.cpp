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

int k1 = 0, k2 = 0;

void op(char c)
{
    if (c == 'Q')
        k2 += 9;
    if (c == 'R')
        k2 += 5;
    if (c == 'B')
        k2 += 3;
    if (c == 'N')
        k2 += 3;
    if (c == 'P')
        k2 += 1;
    if (c == 'K')
        k2 += 0;


    if (c == 'q')
        k1 += 9;
    if (c == 'r')
        k1 += 5;
    if (c == 'b')
        k1 += 3;
    if (c == 'n')
        k1 += 3;
    if (c == 'p')
        k1 += 1;
    if (c == 'k')
        k1 += 0;
}

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
    forn(i, 8)
        forn(j, 8)
        {
            char c;
            cin >> c;
            op(c);
        }
    if (k1 == k2)
        cout << "Draw";
    if (k1 > k2)
        cout << "Black";
    if (k1 < k2)
        cout << "White";
}
//190660JM