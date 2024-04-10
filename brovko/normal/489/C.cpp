#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;

    if(s == 0 && n == 1)
    {
        cout << "0 0";
        return 0;
    }

    if(s == 0 || s > 9 * n)
    {
        cout << "-1 -1";
        return 0;
    }

    vector <int> v(n);

    int s1 = s, x = 0;

    while(s1 > 0)
    {
        int y = min(9ll, s1);
        v[x++] = y;
        s1 -= y;
    }

    vector <int> Max = v;

    v[--x]--;
    v[n - 1]++;

    reverse(v.begin(), v.end());

    for(auto x:v)
        cout << x;

    cout << ' ';

    for(auto x:Max)
        cout << x;
}