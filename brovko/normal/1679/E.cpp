#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;
const int MOD = 998244353;

vector <int> add[1 << 17];
vector <int> sum(1 << 17);
vector <int> add2[1 << 17];

int Add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
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

    int p = binpow(x, y / 2);

    return mul(p, p);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;



    int k = 0;

    for(auto x:s)
        k += (x == '?');

    for(int i = 0; i < n; i++)
    {
        int c = k, mask = 0;

        for(int j = i; (j >= 0 && i + 1 + i - j < n); j--)
        {
            char x = s[j];
            char y = s[i + 1 + i - j];

            if(x != '?' && y != '?')
            {
                if(x != y)
                {
                    c = -1;
                    break;
                }
            }
            else if(x != '?' || y != '?')
            {
                mask |= 1 << (x != '?' ? x - 'a' : y - 'a');
                c--;
            }
            else
            {
                c--;
            }

            if(c >= 0)
                add[mask].pb(c);
        }

        c = k;
        mask = 0;

        add[0].pb(k);

        for(int j = i - 1; (j >= 0 && i + i - j < n); j--)
        {
            char x = s[j];
            char y = s[i + i - j];

            if(x != '?' && y != '?')
            {
                if(x != y)
                {
                    c = -1;
                    break;
                }
            }
            else if(x != '?' || y != '?')
            {
                mask |= 1 << (x != '?' ? x - 'a' : y - 'a');
                c--;
            }
            else
            {
                c--;
            }

            if(c >= 0)
                add[mask].pb(c);
        }
    }

//    for(int i = 0; i < 8; i++)
//    {
//        for(auto x:add[i])
//            cout << x << ' ';
//
//        cout << endl;
//    }



    for(int i = 0; i < (1 << 17); i++)
    {

        for(int j = 0; j <= 17; j++)
        {
            int x = 0;

            for(auto y:add[i])
                x = Add(x, binpow(j, y));

            add2[i].pb(x);
        }
    }

//    for(int i = 0; i < 8; i++)
//    {
//        for(int j = 0; j < 5; j++)
//            cout << add2[i][j] << ' ';
//
//        cout << endl;
//    }

    for(int i = 0; i < (1 << 17); i++)
    {
        for(int j = i; j > 0; j = (i & j - 1))
            sum[i] = Add(sum[i], add2[j][__builtin_popcount(i)]);

        sum[i] = Add(sum[i], add2[0][__builtin_popcount(i)]);
    }

    int q;
    cin >> q;

    while(q--)
    {
        string s;
        cin >> s;

        int mask = 0;

        for(auto x:s)
            mask |= (1 << x - 'a');

        cout << sum[mask] << "\n";
    }
}