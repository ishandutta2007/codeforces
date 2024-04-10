#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD=1e9+7;

int n, q, ps[100005];
string s;

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);


    cin >> n >> q;
    cin >> s;

    for(int i=0;i<n;i++)
        ps[i+1]=ps[i]+s[i]-'0';

    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int k1=ps[r]-ps[l-1];
        int k0=(r-l+1)-k1;

        int x=add(binpow(2, k1), MOD-1);
        int y=binpow(2, k0);
        cout << mul(x, y) << "\n";
    }
}