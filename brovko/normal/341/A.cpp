#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

using li = long long;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    li num = 0;
    vector <li> ps(n + 1);

    for(int i = 0; i < n; i++)
    {
        num += a[i];
        ps[i + 1] = ps[i] + a[i];
    }

    for(int i = 0; i < n; i++)
        num += (a[i] * i - ps[i]) * 2;

    li den = n;

    int g = __gcd(num, den);

    num /= g;
    den /= g;

    cout << num << ' ' << den;
}