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
        auto up=[](ll a,ll b)->ll{return (a+b-1)/b;};
        int n;
        ll c;
        cin >> n >> c;
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<ll> b(n,0);
        for(int i=1;i<n;i++) cin >> b[i];
        ll res=(1ll<<60);
        ll d=0;
        ll now=0;
        for(int i=1;i<=n;i++)
        {
            res=min(res,d+max(0ll,up(c-now,a[i])));
            if(i<n)
            {
                ll tmp=max(0ll,up(b[i]-now,a[i]));
                d+=tmp;
                now+=(tmp*a[i]);
                now-=b[i];
                d++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}