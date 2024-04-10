#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 oidhfdoif

using namespace std;
const int MOD=998244353;

int n, k, fact[500005];

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

int C(int x, int y)
{
    if(x<y)
        return 0;
    else return divide(fact[x], mul(fact[x-y], fact[y]));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> k;
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=mul(fact[i-1], i);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=add(ans, C(n/i-1, k-1));
    cout << ans;
}