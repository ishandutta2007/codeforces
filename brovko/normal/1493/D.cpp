#include <bits/stdc++.h>
//#define int long long

using namespace std;
const int MOD = 1e9 + 7;

int n, q, a[200005], k[200005], lp[200005], Min[200005];
multiset <int> s[200005];
map <int, int> m[200005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int binpow(int x, int y)
{
    if(y == 0)
        return 1;

    if(y % 2)
        return mul(x, binpow(x, y - 1));

    int z = binpow(x, y / 2);

    return mul(z, z);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 2; i < 200005; i++)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;

            if(i * 1ll * i < 200005)
            for(int j = i * i; j < 200005; j += i)
                if(lp[j] == 0)
                    lp[j] = i;
        }
    }

    for(int i = 0; i < n; i++)
    {
        while(a[i] > 1)
        {
            if(m[i][lp[a[i]]] > 0)
                s[lp[a[i]]].erase(s[lp[a[i]]].lower_bound(m[i][lp[a[i]]]));
            else k[lp[a[i]]]++;

            m[i][lp[a[i]]]++;

            s[lp[a[i]]].insert(m[i][lp[a[i]]]);

            a[i] /= lp[a[i]];
        }
    }



    int g = 1;

    for(int i = 2; i < 200005; i++)
        if(lp[i] == i && k[i] == n)
            {
                Min[i] = *(s[i].begin());
                g = mul(g, binpow(i, Min[i]));
            }


    while(q--)
    {
        int i, y;
        cin >> i >> y;
        i--;
        a[i] = y;

        while(a[i] > 1)
        {
            if(m[i][lp[a[i]]] > 0)
                s[lp[a[i]]].erase(s[lp[a[i]]].lower_bound(m[i][lp[a[i]]]));
            else k[lp[a[i]]]++;

            m[i][lp[a[i]]]++;

            s[lp[a[i]]].insert(m[i][lp[a[i]]]);

            if(k[lp[a[i]]] == n)
            {
                int x = lp[a[i]];
                int z = *(s[x].begin());

                g = mul(g, binpow(x, z - Min[x]));
                Min[x] = z;
            }

            a[i] /= lp[a[i]];
        }

        cout << g << endl;
    }
}

/*

4 3
1 6 8 12
1 12
2 3
3 3


*/