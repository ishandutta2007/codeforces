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
        vector<ll> a(n+2,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<ll> c(n+1,0);
        ll sum=0;
        for(int i=2;i<=n;i++)
        {
            c[i]=abs(a[i]-a[i-1]);
            sum+=c[i];
        }
        ll res=sum;
        auto ch=[&](int i,ll b)
        {
            if(i==1) res=min(res,sum-c[2]+abs(a[2]-b));
            else if(i<n) res=min(res,sum-c[i]-c[i+1]+abs(b-a[i-1])+abs(a[i+1]-b));
            else res=min(res,sum-c[n]+abs(b-a[n-1]));
        };
        for(int i=1;i<=n;i++)
        {
            ch(i,a[i-1]);
            ch(i,a[i+1]);
        }
        cout << res << "\n";
    }
    return 0;
}