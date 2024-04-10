#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[300005], b[300005], k, k1;
vector <int> g[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);

    int x = n - 1;
    int Max = b[n - 1];

    while(x >= 0 && b[x] == Max)
    {
        x--;
        k++;
    }

    while(x >= 0 && b[x] == Max - 1)
    {
        x--;
        k1++;
    }

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int Min = 1e18;

    for(int i = 0; i < n; i++)
    {
        int K = k;
        int K1 = k1;

        if(a[i] == Max)
            K--;

        for(auto to:g[i])
        {
            if(a[to] == Max)
            {
                K--;
                K1++;
            }

            if(a[to] == Max - 1)
                K1--;
        }

        if(K)
            Min = min(Min, Max + 2);
        else if(K1)
            Min = min(Min, Max + 1);
        else Min = min(Min, Max);
    }

    cout << Min;
}