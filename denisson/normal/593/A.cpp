#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
#define forn(i, n) for (ll i = 0; i < (ll)n; i++)
#define fornm(i, n, m) for (ll i = n; i <= (ll)m; i++)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define TASK "a"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 1;
const ll LINF = (ll)9e18 + 7;

int n;
vector <str> a;
int was1[30];

str con(int a)
{
    str s1 = "";
    while (a > 0)
    {
        s1 += '0' + a % 10;
        a /= 10;
    }
    reverse(s1.begin(), s1.end());
    return s1;
}

int main()
{
    //freopen("input.in", "r", stdin); //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        str s;
        cin >> s;
        int k1 = 0;
        memset(was1, false, 30);
        for (int j = 0; j < s.size(); j++)
        {
            if (!was1[s[j] - 'a'])
            {
                was1[s[j] - 'a'] = true;
                k1++;
            }
        }
        if (k1 <= 2)
        {
            a.pb(s);
        }
    }
    //for (int i = 0; i < a.size(); i++)
    //    cout << a[i] << ' ';
    //cout << LN;
    int ans = 0;
    for (char c1 = 'a'; c1 <= 'z'; c1++)
    for (char c = 'a'; c <= 'z'; c++)
    {
        int sum = 0;
        for (int i = 0; i < a.size(); i++)
        {
            bool f = true;
            for (int j = 0; j < a[i].size(); j++)
                if (a[i][j] != c && a[i][j] != c1)
                    f = false;
            if (f)
                sum += a[i].size();
        }
        ans = max(ans, sum);
    }
    cout << ans;
}