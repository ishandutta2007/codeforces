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
        vector<int> x(n);
        for(int i=0;i<n;i++) cin >> x[i];
        sort(x.begin(),x.end());
        int y;
        for(int i=0;i<n;i++) cin >> y;
        vector<int> best(n+1,0);
        int res=0;
        for(int i=n-1;i>=0;i--)
        {
            int l=i,r=n;
            while(l<r-1)
            {
                int m=(l+r)/2;
                if(x[i]+k>=x[m]) l=m;
                else r=m;
            }
            res=max(res,l-i+1+best[l+1]);
            best[i]=max(l-i+1,best[i+1]);
        }
        cout << res << "\n";
    }
    return 0;
}