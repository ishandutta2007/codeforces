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
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

int n, k, a[1000007], uk1, uk2 = -1;
int was[1000007];
pair<int, int> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("output.in", "r", stdin); //freopen("speeding.out", "w", stdout);
    //freopen("lcs.in", "r", stdin); freopen("lcs.out", "w", stdout);
    cin >> n >> k;
    forn(i, n)
        cin >> a[i];
    int q = 0;
    forn(i, n)
    if (q == k && was[a[i]] == 0)
    {
        uk2 = i - 1;
        break;
    }
    else
    {
        if (was[a[i]] == 0)
            q++;
        was[a[i]]++;
    }
    if (uk2 == -1)
    {
        cout << 1 << ' ' << n;
        exit(0);
    }
    ans = mp(0, uk2);
    for (int i = uk2 + 1; i < n; i++)
    {
        if (was[a[i]] == 0)
            q++;
        was[a[i]]++;
        while(q > k)
        {
            uk1++;
            was[a[uk1-1]]--;
            if (was[a[uk1-1]] == 0)
                q--;
        }
        if (i - uk1 > ans.YY - ans.XX)
            ans = mp(uk1, i);
    }
    cout << ans.XX + 1 << ' ' << ans.YY + 1;
}