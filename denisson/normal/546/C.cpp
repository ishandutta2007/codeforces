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
const int MAXN = 1e5 + 8;

int n;

class deq
{
public:

    int a[100000], uk1, uk2;
    int empty()
    {
        re (uk2 - uk1 - 1 == 0);
    }
    void push1(int z)
    {
        a[uk2++] = z;
    }
    void push2(int z)
    {
        a[uk1--] = z;
    }
    int pop1()
    {
        re a[--uk2];
    }
    int pop2()
    {
        re a[++uk1];
    }
};

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n;
    deq d1, d2;
    d1.uk1 = 50000; d1.uk2 = 50001;
    d2.uk1 = 50000; d2.uk2 = 50001;
    int q;
    cin >> q;
    forn(i, q)
    {
        int z;
        cin >> z;
        d1.push2(z);
    }
    cin >> q;
    forn(i, q)
    {
        int z;
        cin >> z;
        d2.push2(z);
    }
    int kk = 0;
    while(!d1.empty() && !d2.empty())
    {
        if (/*(db)clock() / 1.0 / CLOCKS_PER_SEC >= (db)1.980*/ kk >= 50000)
        {
            cout << -1;
            exit(0);
        }
        kk++;
        int q1 = d1.pop1();
        int q2 = d2.pop1();
        if (q1 > q2)
        {
            d1.push2(q2);
            d1.push2(q1);
        }
        else
        {
            d2.push2(q1);
            d2.push2(q2);
        }
    }
    cout << kk << ' ';
    if (d1.empty())
        cout << 2;
    else
        cout << 1;
}
//190660JM