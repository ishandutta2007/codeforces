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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        const int lim=1000000000;
        int l=0,r=lim+1;
        while(l<r-1)
        {
            int m=(l+r)/2;
            int c=0;
            vector<int> b=a;
            for(int i=1;i<=n;i++)
            {
                if(2*b[i]<m)
                {
                    b[i]=lim;
                    c++;
                }
            }
            int opt=2;
            for(int i=1;i<n;i++) opt=min(opt,(b[i]<m)+(b[i+1]<m));
            if(c+opt<=k) l=m;
            else r=m;
        }
        cout << l << "\n";
    }
    return 0;
}