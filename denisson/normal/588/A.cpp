#include <bits/stdc++.h>
#define XX first
#define YY second
#define db long double
#define str string
#define ll long long
#define vec vector
#define re return
#define sz size
#define in insert
#define y1 x345t89nm0238c50345df34nm5d3245d83dj83j980df96345d35d34d
#define pb push_back
#define mp make_pair
#define LN '\n'
#define sp(a) fixed << setprecision(a)
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)

using namespace std;
const int INF = 2e9 + 7;
const db pi = acos(-1.0);

int n, ans = 0;
pair <int, int> a[100007];

int main()
{
    cin >> n;
    forn(i, n)
        cin >> a[i].XX >> a[i].YY;
    int min1 = a[0].YY;
    forn(i, n)
    {
        min1 = min (min1, a[i].YY);
        ans += a[i].XX * min1;
    }
    cout << ans;
}