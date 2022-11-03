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
#define sqr(x) x*x
#define clr(a, x) memset(a, x, sizeof(a));
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
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const bool is_testing = 0;

int l, r, n, m;

int main()
{
    //freopen("lock.in", "r", stdin); freopen("lock.out", "w", stdout);
    if (is_testing)
    {
        freopen("input.txt", "r", stdin);
    }
    int n, m;
    cin >> n >> m;
    l = 1, r = n;
    forn(i, m)
    {
        int q1, q2;
        cin >> q1 >> q2;
        if (q1 > q2)
            swap(q1, q2);
        l = max(l, q1);
        r = min(r, q2);
    }
    cout << max(0, r - l);
}