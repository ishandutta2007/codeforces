#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;
const int MOD = 998244353;

int n, a[1000005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i < 1000005; i++)
        for(int j = i; j < 1000005; j += i)
            a[j]++;

    cin >> n;

    int x = 0, s = 0;

    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            x = 1;
        else x = add(s, a[i + 1]);

        s = add(s, x);
    }

    cout << x << endl;
}