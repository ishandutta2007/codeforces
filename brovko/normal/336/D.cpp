#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int fact[N], ifact[N];

int add(int x, int y)
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

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int C(int x, int y)
{
    return mul(fact[x], mul(ifact[x - y], ifact[y]));
}

int main()
{
    fact[0] = ifact[0] = 1;
    
    for(int i = 1; i < N; i++)
    {
        fact[i] = mul(fact[i - 1], i);
        ifact[i] = inv(fact[i]);
    }
    
    int n, m, g;
    cin >> n >> m >> g;
    
    if(m == 0)
    {
        cout << (n % 2 != g);
        return 0;
    }
    
    int ans = 0;
    
    if(m == 1)
    {
        ans = (n % 2 == g ? MOD - 1 : 1);
    }
    
    for(int i = n + m - g; i >= m; i -= 2)
        ans = add(ans, C(i - 1, m - 1));
        
    cout << ans;
}