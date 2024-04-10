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

const bool is_testing = false;
const int p = 31;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 11;
const int MAXN = 6e5 + 7;

int n, m;
ll step1[MAXN], step2[MAXN];

ll get1(str s)
{
    ll ans = 0;
    forn(i, s.size())
        ans = ((ll)ans + (ll)s[i] * (ll)step1[i]) % MOD;
    re ans;
}

ll get2(str s)
{
    ll ans = 0;
    forn(i, s.size())
        ans = ((ll)ans + (ll)s[i] * (ll)step2[i]) % MOD2;
    re ans;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    set< pair<ll, ll> > h;
    cin >> n >> m;
    step1[0] = 1;
    for (int i = 1; i < MAXN; i++)
        step1[i] = ((ll)step1[i - 1] * (ll)p) % MOD;
    step2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        step2[i] = ((ll)step2[i - 1] * (ll)p) % MOD2;

    forn(i, n)
    {
        str s;
        cin >> s;
        h.in(mp(get1(s), get2(s) ) );
    }
    forn(i, m)
    {
        str s;
        cin >> s;
        bool f = false;
        ll q1 = get1(s);
        ll q2 = get2(s);
        forn(i, s.size())
            for (char c = 'a'; c <= 'c'; c++)
                if (s[i] != c)
                {
                    ll qq1 = q1;
                    qq1 = (qq1 + step1[i] * (c - s[i]) + MOD) % MOD;
                    qq1 = ((ll)qq1 + (ll)MOD) % MOD;


                    ll qq2 = q2;
                    qq2 = (qq2 + step2[i] * (c - s[i]) + MOD2) % MOD2;
                    qq2 = ((ll)qq2 + (ll)MOD2) % MOD2;

                    //cout << q1 << LN;
                    if (h.count(mp(qq1, qq2)) )
                        f = true;
                }
        if (f)
            cout << "YES" << LN;
        else
            cout << "NO" << LN;
    }
}
//190660JM