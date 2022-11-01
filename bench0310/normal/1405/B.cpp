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
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        ll rm=0;
        ll pos=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>0) pos+=a[i];
            else if(a[i]<0)
            {
                ll x=min(pos,-a[i]);
                a[i]+=x;
                pos-=x;
                rm+=x;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]>0)
            {
                ll x=min(a[i],rm);
                a[i]-=x;
                rm-=x;
            }
        }
        ll res=0;
        for(int i=1;i<=n;i++) res+=abs(a[i]);
        cout << res/2 << "\n";
    }
    return 0;
}