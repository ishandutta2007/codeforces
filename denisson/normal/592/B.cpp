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

/*
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
*/
int main()
{
    //freopen("input.in", "r", stdin); //freopen("output.txt", "w", stdout);
    cin >> n;
        cout << (ll)(n - 2)*(n - 2);

}