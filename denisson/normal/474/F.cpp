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
const ll MOD = 1e9 + 7;

int n, m;
int a[100007];
int gcd_t[8*100007];
pair<int, int> min_t[8*100007];

int gcd(int a, int b)
{
    if (b == 0)
        re a;
    re gcd(b, a % b);
}

void build(int v, int vl, int vr)
{
    if (vl == vr)
    {
        gcd_t[v] = a[vl];
    }
    else
    {
        int vm = (vl + vr) / 2;
        build(v * 2 + 1, vl, vm);
        build(v * 2 + 2, vm + 1, vr);
        gcd_t[v] = gcd(gcd_t[v * 2 + 1], gcd_t[v * 2 + 2]);
    }
}

int get(int v, int vl, int vr, int l, int r)
{
    if (vr < l || vl > r)
        re INF;
    if (vl >= l && vr <= r)
    {
        re gcd_t[v];
    }
    else
    {
        int vm = (vl + vr) / 2;
        int q1 = get(v * 2 + 1, vl, vm, l, r);
        int q2 = get(v * 2 + 2, vm + 1, vr, l, r);
        if (q1 == INF)
            re q2;
        if (q2 == INF)
            re q1;
        re gcd(q1, q2);
    }
}

void build_min(int v, int vl, int vr)
{
    if (vl == vr)
    {
        min_t[v].XX = a[vl];
        min_t[v].YY = 1;
    }
    else
    {
        int vm = (vl + vr) / 2;
        build_min(v * 2 + 1, vl, vm);
        build_min(v * 2 + 2, vm + 1, vr);
        if (min_t[v * 2 + 1].XX == min_t[v * 2 + 2].XX)
        {
            min_t[v].XX = min_t[v * 2 + 1].XX;
            min_t[v].YY = min_t[v * 2 + 1].YY + min_t[v * 2 + 2].YY;
        }
        else
        {
            min_t[v] = min(min_t[v * 2 + 1], min_t[v * 2 + 2]);
        }
    }
}

pair<int, int> get_min(int v, int vl, int vr, int l, int r)
{
    if (vr < l || vl > r)
        return mp(INF, INF);
    if (vl >= l && vr <= r)
    {
        re min_t[v];
    }
    else
    {
        int vm = (vl + vr) / 2;
        pair<int, int> q1 = get_min(v * 2 + 1, vl, vm, l, r);
        pair<int, int> q2 = get_min(v * 2 + 2, vm + 1, vr, l, r);
        if (q1 == mp(INF, INF))
            re q2;
        if (q2 == mp(INF, INF))
            re q1;
        if (q1.XX == q2.XX)
        {
            re mp(q1.XX, q1.YY + q2.YY);
        }
        else
        {
            re min(q1, q2);
        }
    }
}

int main()
{
    //freopen("lock.in", "r", stdin); freopen("lock.out", "w", stdout);
    if (is_testing)
    {
    }
    cin >> n;
    forn(i, n)
        //cin >> a[i];
        scanf("%d", &a[i]);
    build(0, 0, n - 1);
    build_min(0, 0, n - 1);
    cin >> m;
    forn(i, m)
    {
        int l, r;
        //cin >> l >> r;
        scanf("%d%d", &l, &r);
        l--; r--;
        int GCD = get(0, 0, n - 1, l, r);
        pair<int, int> q = get_min(0, 0, n - 1, l, r);
        //cout << GCD << ' ' << q.XX << ' ' << q.YY << LN;
        if (GCD == q.XX)
            //cout << r - l - q.YY + 1;
            printf("%d\n", r - l - q.YY + 1);
        else
            //cout << r - l + 1;
            printf("%d\n", r - l + 1);
    }

}