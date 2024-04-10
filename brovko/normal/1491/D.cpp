#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int q;

int k1(int x)
{
    if(x == 0)
        return 0;

    return x % 2 + k1(x / 2);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while(q--)
    {
        int u, v;
        cin >> u >> v;

        int f = 1;

        if(u > v)
            f = 0;

        for(int i = 0; i <= 30; i++)
            if(k1(u % (1ll << i)) < k1(v % (1ll << i)))
                f = 0;

        if(f)
            cout << "YES\n";
        else cout << "NO\n";
    }
}