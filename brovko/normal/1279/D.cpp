#include <bits/stdc++.h>
#define int long long

using namespace std;
const int mod=998244353;

int n, k[1000005], kx[1000005], a, y, z;
vector <int> v[1000005];

int sum(int x, int y)
{
    return (x+y)%mod;
}
int mul(int x, int y)
{
    return x*y%mod;
}
int binpow(int x, int y)
{
    if(y==0)
        return 1;
    if(y%2==0)
    {
        int ans=binpow(x, y/2);
        return ans*ans%mod;
    }
    return binpow(x, y-1)*x%mod;
}
int inv(int x)
{
    return binpow(x, mod-2);
}
int divide(int x, int y)
{
    return mul(x, inv(y));
}

int32_t main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> k[i];
        for(int j=0;j<k[i];j++)
        {
            cin >> a;
            v[i].push_back(a);
            kx[a]++;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<k[i];j++)
    {
        y=divide(kx[v[i][j]], mul(k[i], mul(n, n)));
        z=sum(z, y);
    }
    cout << z;
    return 0;
}