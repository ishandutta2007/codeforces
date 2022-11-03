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
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
template<class T> bool in(T a, T x1, T x2) {return (a >= x1 && a <= x2);}

int n, ans = 0, q1, q2, u1, u2, q3;
vec <int> a;


int main()
{
    cin >> n;
    a.resize(n);
    forn(i, n)
        cin >> a[i];
    if (a[0] == a[1])
    {
        q1 = 0;
        u1 = a[0];
        q2 = -1;
        u2 = -1;
    }
    else
    {
        u1 = a[0];
        u2 = a[1];
        q1 = -1;
        q2 = 1;
    }
    q3 = 0;
    form(i, 2, n - 1)
    {
        if (u2 == -1 && u1 != a[i])
            u2 = a[i];
        if (a[i] == u1 || a[i] == u2)
        {
            if (a[i] == u1)
            {
                q2 = -1;
                if (q1 == -1)
                q1 = i;
            }
            else
            {
                q1 = -1;
                if (q2 == -1)
                q2 = i;
            }
        }
        else
        {
            //cout << i + 1 << LN;
            ans = max(ans, i - q3);
            if (q1 == -1)
            {
                u1 = a[i];
                q3 = q2;
                q1 = i;
                q2 = -1;
            }
            else
            {
                u2 = a[i];
                q3 = q1;
                q2 = i;
                q1 = -1;
            }
        }
    }
    ans = max(ans, n - q3);
    cout << ans;
}