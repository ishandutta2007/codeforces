#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, m, fact[250005];

int add(int x, int y)
{
    return (x+y)%m;
}

int mul(int x, int y)
{
    return x*y%m;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    fact[0]=1;
    for(int i=1;i<250005;i++)
        fact[i]=mul(i, fact[i-1]);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=add(ans, mul(n+1-i, mul(fact[i], fact[n+1-i])));
    cout << ans;
}