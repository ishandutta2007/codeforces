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

ll k1, k2;
ll ans = 0;
ll op(int a)
{
    ll pro = 1;
    forn(i, a)
        pro *= (ll)2;
    re pro;
}

ll con (vec <int> a)
{
    ll sum = 0;
    forn(i, a.size())
        sum += op(a.size() - 1 - i) * a[i];
    re sum;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("output.in", "r", stdin); //freopen("speeding.out", "w", stdout);
    //freopen("approximate.in", "r", stdin); freopen("approximate.out", "w", stdout);
    cin >> k1 >> k2;
    for (int i = 1; i <= 60; i++)
    {
        vec <int> a;
        a.pb(1);
        forn(sdgsdfgfdsg, i)
            a.pb(1);
        for (int j = 1; j <= a.size() - 1; j++)
        {
            a[j] = 0;
            ll q = con(a);
            //forn(qq, a.size())
            //    cout << a[qq];
            //cout << ' ' << q << LN;
            if (q >= k1 && q <= k2)
                ans++;
            a[j] = 1;
        }

    }
    cout << ans;
}