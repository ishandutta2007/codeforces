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
        vector<vector<int>> l(n+2,vector<int>(n+1,0));
        vector<vector<int>> r(n+2,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        {
            l[i]=l[i-1];
            l[i][a[i]]++;
        }
        for(int i=n;i>=1;i--)
        {
            r[i]=r[i+1];
            r[i][a[i]]++;
        }
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                res+=(l[i-1][a[j]]*r[j+1][a[i]]);
            }
        }
        cout << res << "\n";
    }
    return 0;
}