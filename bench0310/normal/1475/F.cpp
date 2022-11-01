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
        vector<string> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        vector<string> b(n);
        for(int i=0;i<n;i++) cin >> b[i];
        vector<vector<int>> c(n,vector<int>(n,0));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) c[i][j]=(a[i][j]!=b[i][j]);
        for(int j=0;j<n;j++)
        {
            if(c[0][j]==1) for(int i=0;i<n;i++) c[i][j]^=1;
        }
        bool ok=1;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) ok&=(c[i][j]==c[i][0]);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}