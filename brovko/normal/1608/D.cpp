#include <bits/stdc++.h>
#define li long long
#define pb push_back
#define x first
#define y second

using namespace std;
const int MOD = 998244353;

int n, fact[200005];
string a[100005];

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

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int C(int x, int y)
{
    if(x < 0 || y < 0 || x < y)
        return 0;

    return divide(fact[x], mul(fact[x - y], fact[y]));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < 200005; i++)
        fact[i] = mul(fact[i - 1], i);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        if(a[i][1] == 'B')
            a[i][1] = 'W';
        else if(a[i][1] == 'W')
            a[i][1] = 'B';
    }

    int d = 0, c = 0, k = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == "W?" || a[i] == "?B")
            c++;
        else if(a[i] == "?W" || a[i] == "B?")
        {
            d--;
            c++;
        }
        else if(a[i] == "BW")
            d--;
        else if(a[i] == "WB")
            d++;
        else if(a[i] == "??")
            k++;
    }

//    cout << c << ' ' << d << ' ' << k << endl;

    int ans = 0;

    for(int i = 0; i <= k; i++)
    {
        int D = k - i - d;
        int C2 = c + k;

//        cout << C2 << ' ' << D << endl;

        ans = add(ans, mul(C(C2, D), C(k, i)));
    }

    int ans2 = 1;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == "BW" || a[i] == "WB")
            ans2 = 0;
        else if(a[i] == "??")
            ans2 = mul(ans2, 2);
    }

    int ans3 = 1;

    for(int i = 0; i < n; i++)
    {
        if(a[i][0] == 'W' || a[i][1] == 'W')
            ans3 = 0;
    }

    int ans4 = 1;

    for(int i = 0; i < n; i++)
    {
        if(a[i][0] == 'B' || a[i][1] == 'B')
            ans4 = 0;
    }

    cout << add(ans, add(MOD - ans2, add(ans3, ans4)));
}