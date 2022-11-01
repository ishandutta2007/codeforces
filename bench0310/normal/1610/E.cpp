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
        int res=0;
        for(int i=1;i<=n;i++)
        {
            int x=ranges::upper_bound(a,a[i])-a.begin();
            if(x==n+1)
            {
                res=max(res,n-i+1);
                continue;
            }
            int c=x-i+1;
            int d=(a[x]-a[i]);
            while(1)
            {
                int p=ranges::lower_bound(a,a[i]+2*d)-a.begin();
                if(p<=n)
                {
                    c++;
                    d=(a[p]-a[i]);
                }
                else break;
            }
            res=max(res,c);
        }
        cout << n-res << "\n";
    }
    return 0;
}