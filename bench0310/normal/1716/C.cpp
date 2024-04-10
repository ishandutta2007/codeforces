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
        vector a(2,vector(n+1,int(0)));
        for(int i=0;i<2;i++) for(int j=1;j<=n;j++) cin >> a[i][j];
        a[0][1]=-1;
        auto process=[&](vector<int> b)->array<vector<int>,2>
        {
            vector<int> l(n+2,-2*n);
            for(int i=n;i>=1;i--) l[i]=max(b[i],l[i+1]-1);
            vector<int> r(n+2,-2*n);
            for(int i=n;i>=1;i--) r[i]=max(b[i]-(n-i),r[i+1]);
            return {l,r};
        };
        auto [al,ar]=process(a[0]);
        auto [bl,br]=process(a[1]);
        int res=(1<<30)+n;
        int now=0;
        for(int i=1;i<=n;i++)
        {
            if(i&1) res=min(res,max({now,al[i]-(2*(i-1)-1),br[i]-(2*n-1-(n-i)-1)}));
            else res=min(res,max({now,bl[i]-(2*(i-1)-1),ar[i]-(2*n-1-(n-i)-1)}));
            if(i&1) now=max({now,a[0][i]-(2*i-3),a[1][i]-(2*i-2)});
            else now=max({now,a[1][i]-(2*i-3),a[0][i]-(2*i-2)});
        }
        cout << res+2*n-1 << "\n";
    }
    return 0;
}