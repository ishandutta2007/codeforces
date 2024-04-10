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
        vector<ll> c(n+1,0);
        vector<ll> a(n+1,0);
        vector<ll> b(n+1,0);
        for(int i=1;i<=n;i++) cin >> c[i];
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        ll res=0;
        ll now=abs(a[2]-b[2]);
        for(int i=2;i<=n;i++)
        {
            res=max(res,now+2+c[i]-1);
            if(i<n)
            {
                if(a[i+1]==b[i+1]) now=0;
                else
                {
                    if(a[i+1]>b[i+1]) swap(a[i+1],b[i+1]);
                    now+=(2+a[i+1]-1+c[i]-b[i+1]);
                    now=max(now,b[i+1]-a[i+1]);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}