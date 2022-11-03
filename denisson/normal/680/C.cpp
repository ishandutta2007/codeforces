#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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

const int l = 20;

bool ask(int a)
{
    cout << a << endl;
    str s;
    cin >> s;
    re (s[0] == 'y');
}

void ans(bool f)
{
    if (f)
        cout << "composite" << endl;
    else
        cout << "prime" << endl;
    exit(0);
}

bool prime(int a)
{
    bool f = (a > 1);
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0)
            f = false;
    re f;
}

int main()
{
    //freopen("lock.in", "r", stdin); freopen("lock.out", "w", stdout);
    if (is_testing)
    {
        freopen("input.txt", "r", stdin);
        freopen("input.out", "w", stdout);
    }
    bool ok = false;
    form(i, 2, 50)
    if (prime(i))
    {
        if (ask(i))
        {
            if (ok)
                ans(1);
            ok = true;
            if (i * i <= 100)
            if (ask(i * i))
            {
                if (ok)
                    ans(1);
                ok = true;
            }
        }
    }
    ans(0);
}