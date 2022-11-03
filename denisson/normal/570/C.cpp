#include <bits/stdc++.h>
#include <Windows.h>
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

const bool is_testing = false;
const int MAXN = 1e6 + 7;

int n, m, num = 0, group = 0;
bool point[300007];


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n >> m;
    str s;
    cin >> s;
    forn(i, n)
    {
        if (s[i] == '.')
        {
            if (i == 0 || s[i - 1] != '.')
                group++;
            num++;
            point[i + 1] = true;
        }
    }
    //cout << num << ' ' << group << LN;
    forn(sdfasdfafsd, m)
    {
        int q;
        char c;
        cin >> q >> c;
        if (c == '.')
        {
            if (!point[q])
            {
                if (point[q - 1] && point[q + 1])
                    group--;
                else
                if (!point[q - 1] && !point[q + 1])
                    group++;
                num++;
            }
        }
        else
        {
            if (point[q])
            {
                if (point[q + 1] && point[q - 1])
                    group++;
                if (!point[q + 1] && !point[q - 1])
                    group--;
                num--;
            }
        }
        point[q] = (c == '.');
        //cout << num << ' ' << group << LN;
        cout << num - group << LN;
    }
}
//190660JM