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
        vector<array<int,2>> a(n+1);
        for(int j=0;j<2;j++) for(int i=1;i<=n;i++) cin >> a[i][j];
        vector<array<int,2>> res;
        for(int i=1;i<=n;i++)
        {
            array<int,2> m=a[i];
            for(int j=i;j<=n;j++) m=min(m,a[j]);
            int p=0;
            for(int j=i;j<=n;j++) if(m==a[j]) p=j;
            if(i<p)
            {
                res.push_back({i,p});
                swap(a[i],a[p]);
            }
        }
        bool ok=1;
        for(int i=1;i<n;i++) ok&=(a[i][1]<=a[i+1][1]);
        if(ok)
        {
            cout << res.size() << "\n";
            for(auto [i,j]:res) cout << i << " " << j << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}