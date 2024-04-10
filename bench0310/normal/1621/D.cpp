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
        vector c(2*n+1,vector(2*n+1,int(0)));
        for(int i=1;i<=2*n;i++) for(int j=1;j<=2*n;j++) cin >> c[i][j];
        ll res=0;
        for(int i=n+1;i<=2*n;i++) for(int j=n+1;j<=2*n;j++) res+=c[i][j];
        int m=(1<<30);
        for(int i=1;i<=n;i+=max(1,n-1)) for(int j=1;j<=n;j+=max(1,n-1)) m=min({m,c[i+n][j],c[i][j+n]});
        cout << res+m << "\n";
    }
    return 0;
}