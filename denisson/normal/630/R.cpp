#include <bits/stdc++.h>

#define ll long long
#define str string
#define XX first
#define YY second
#define vec vector
#define re return
#define y1 dasfasdf32s23s3224
#define LN '\n'
#define all(a) a.begin(), a.end()
#define in insert
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, a, b) for (int i = a; i <= b; i++)

const int INF = 1e9 + 7;
const int p = 5;
const int MOD = 1e9 + 7;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 5;
const bool is_testing = 0;
const int MAXN = 50000;

using namespace std;

ll take()
{
    re abs((((((ll)rand() << 16) + (ll)rand()) << 16) + (ll)rand()) << 16 + (ll)rand());
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie();
    //freopen("sufflcp.in", "r", stdin);
    //freopen("sufflcp.out", "w", stdout);
    if (is_testing)
    {
        freopen("input.txt", "r", stdin);
    }
    ll n;
    cin >> n;
    if (n % 2 == 0)
        cout << 2;
    else
        cout << 1;
}