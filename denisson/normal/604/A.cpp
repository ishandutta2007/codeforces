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
#define TASK "a"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e6 + 7;
const ll LINF = (ll)9e18 + 7;

db m1, m2, m3, m4, m5, w1, w2, w3, w4, w5, q1, q2, ans = 0;

int main()
{
    cin >> m1 >> m2 >> m3 >> m4 >> m5 >> w1 >> w2 >> w3 >> w4 >> w5 >> q1 >> q2;
    ans += max((db)500*0.3, (1 - m1/250) * 500  - 50 * w1);
    ans += max((db)1000*0.3, (1 - m2/250) * 1000  - 50 * w2);
    ans += max((db)1500*0.3, (1 - m3/250) * 1500  - 50 * w3);
    ans += max((db)2000*0.3, (1 - m4/250) * 2000  - 50 * w4);
    ans += max((db)2500*0.3, (1 - m5/250) * 2500  - 50 * w5);
    ans += q1 * 100;
    ans -= q2 * 50;
    cout << ans;
}