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
        int n,k;
        cin >> n >> k;
        vector<ll> s(k+1,0);
        for(int i=1;i<=k;i++) cin >> s[i];
        bool ok=1;
        ll lim=(1ll<<40);
        for(int i=k-1;i>=1;i--)
        {
            ok&=(s[i+1]-s[i]<=lim);
            lim=s[i+1]-s[i];
        }
        ok&=((n-k+1)*lim>=s[1]);
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}