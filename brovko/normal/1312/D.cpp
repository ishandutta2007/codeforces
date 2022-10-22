#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD=998244353;

int n, m, fact[200005];

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
    return divide(fact[x], mul(fact[x-y], fact[y]));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    fact[0]=1;
    for(int i=1;i<200005;i++)
        fact[i]=mul(fact[i-1], i);

    if(n==2)
        cout << 0;
    else cout << mul(C(m, n-1), mul(n-2, binpow(2, n-3)));
}