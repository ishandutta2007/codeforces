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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        int res=n;
        for(int i=1;i<=n-1;i++)
        {
            int sum=0;
            for(int j=1;j<=i;j++) sum+=a[j];
            int now=i;
            int l=i+1;
            bool ok=1;
            while(l<=n)
            {
                int r=l;
                int s=a[l];
                while(r+1<=n&&s<sum) s+=(a[++r]);
                ok&=(s==sum);
                now=max(now,r-l+1);
                l=r+1;
            }
            if(ok) res=min(res,now);
        }
        cout << res << "\n";
    }
    return 0;
}