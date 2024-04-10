#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
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
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

int a, b, c, x, y, z, ans = 0;

int main()
{
    //freopen("gray-code.in", "r", stdin); freopen("gray-code.out", "w", stdout);
    cin >> a >> b >> c >> x >> y >> z;
    a = a - x;
    b = b - y;
    c = c - z;
    if (a > 0)
        ans += a / 2;
    else
        ans += a;
    if (b > 0)
        ans += b / 2;
    else
        ans += b;
    if (c > 0)
        ans += c / 2;
    else
        ans += c;
    if (ans >= 0)
        cout << "Yes";
    else
        cout << "No";
}