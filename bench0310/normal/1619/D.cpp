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
        int m,n;
        cin >> m >> n;
        vector p(m+1,vector(n+1,int(0)));
        for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) cin >> p[i][j];
        int l=1,r=1000000001;
        while(l<r-1)
        {
            int lim=(l+r)/2;
            bool ok=1;
            vector<int> c(m+1,0);
            for(int j=1;j<=n;j++)
            {
                int x=0;
                for(int i=1;i<=m;i++)
                {
                    if(p[i][j]>=lim)
                    {
                        c[i]++;
                        x=1;
                    }
                }
                ok&=x;
            }
            int y=0;
            for(int i=1;i<=m;i++) y|=(c[i]>=2);
            ok&=y;
            if(ok) l=lim;
            else r=lim;
        }
        cout << l << "\n";
    }
    return 0;
}