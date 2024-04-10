#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=998244353;
    int n;
    cin >> n;
    array<ll,2> c={0,1};
    for(int i=1;i<n;i++)
    {
        c[(i&1)^1]=(c[(i&1)^1]+c[i&1])%mod;
        //cout << "after " << i << ": " << c[0] << " " << c[1] << endl;
    }
    ll p=1;
    for(int i=1;i<=n;i++) p=(p*(mod+1)/2)%mod;
    cout << (c[n&1]*p)%mod << "\n";
    return 0;
}