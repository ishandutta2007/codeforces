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
        int n;
        cin >> n;
        vector<ll> s(n+1,0);
        for(int i=1;i<=n;i++) cin >> s[i];
        ll res=0;
        vector<ll> f(n+1,0);
        for(int i=1;i<=n;i++)
        {
            ll mx=max(ll(1),ll(n-i));
            ll c=max(ll(0),s[i]-mx);
            s[i]-=c;
            ll z=min(c,f[i]);
            c-=z;
            f[i]-=z;
            res+=c;
            while(s[i]>1)
            {
                if(f[i]==0) res++;
                else f[i]--;
                f[i+s[i]]++;
                s[i]=max(s[i]-1,ll(1));
            }
            if(i<n) f[i+1]+=f[i];
        }
        cout << res << "\n";
    }
    return 0;
}