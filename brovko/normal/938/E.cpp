#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD=1e9+7;

int n, a[1000005], fact[1000005];

int add(int x, int y)
{
    return (x+y)%MOD;
}

int mul(int x, int y)
{
    return x*y%MOD;
}

int binpow(int x, int y)
{
    if(y==0)
        return 1;
    if(y%2)
        return mul(x, binpow(x, y-1));
    int z=binpow(x, y/2);
    return mul(z, z);
}

int inv(int x)
{
    return binpow(x, MOD-2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0]=1;
    for(int i=1; i<1000005; i++)
        fact[i] = mul(fact[i-1], i);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);

    int Max = a[n-1];
    int ans = 0;

    int b=n;
    for(int i=0;i<n;i++)
        if(a[i]!=Max)
    {
        if(i!=0 && a[i]!=a[i-1])
            b=n-i;
        ans = add(ans, mul(a[i], divide(fact[n], b)));
    }
    cout << ans;
}