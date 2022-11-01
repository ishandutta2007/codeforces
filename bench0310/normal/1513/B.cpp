#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        const ll mod=1000000007;
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        int z=(1<<30)-1;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            z&=a[i];
        }
        for(int i=1;i<=n;i++) a[i]-=z;
        ll c=0;
        for(int i=1;i<=n;i++) c+=(a[i]==0);
        ll res=(c*(c-1))%mod;
        for(int i=1;i<=n-2;i++) res=(res*i)%mod;
        cout << res << "\n";
    }
    return 0;
}