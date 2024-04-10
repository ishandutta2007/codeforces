#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;
const int MOD=1e9+7;

int n, m, f[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    f[0]=1;
    f[1]=1;
    for(int i=2;i<100005;i++)
        f[i]=(f[i-1]+f[i-2])%MOD;
    cout << 2*(f[n]+f[m]-1)%MOD;
}