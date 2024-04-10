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
        int n,m,k;
        cin >> n >> m >> k;
        vector<string> s(n);
        for(int i=0;i<n;i++) cin >> s[i];
        vector vis(n,vector(m,bool(0)));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mx=-1;
                for(int x=0;i-x>=0&&j-x>=0&&j+x<m;x++)
                {
                    if(s[i-x][j-x]=='.'||s[i-x][j+x]=='.') break;
                    mx++;
                }
                if(mx>=k) for(int x=0;x<=mx;x++) vis[i-x][j-x]=vis[i-x][j+x]=1;
            }
        }
        bool ok=1;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j]=='*') ok&=vis[i][j];
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}