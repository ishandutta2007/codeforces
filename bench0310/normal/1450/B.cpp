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
        vector<int> x(n+1,0);
        vector<int> y(n+1,0);
        for(int i=1;i<=n;i++) cin >> x[i] >> y[i];
        int res=-1;
        for(int i=1;i<=n;i++)
        {
            bool ok=1;
            for(int j=1;j<=n;j++) ok&=(abs(x[i]-x[j])+abs(y[i]-y[j])<=k);
            if(ok) res=1;
        }
        cout << res << "\n";
    }
    return 0;
}