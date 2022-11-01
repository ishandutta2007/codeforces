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
        int n,m;
        cin >> n >> m;
        vector<string> s(n+1,string(m,'.'));
        for(int i=1;i<=n;i++)
        {
            cin >> s[i];
            s[i]="."+s[i]+".";
        }
        vector<vector<int>> l(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) l[i][j]=((s[i][j]=='*')?l[i][j-1]+1:0);
        vector<vector<int>> r(n+1,vector<int>(m+2,0));
        for(int i=1;i<=n;i++) for(int j=m;j>=1;j--) r[i][j]=((s[i][j]=='*')?r[i][j+1]+1:0);
        int res=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int c=0;i+c<=n;c++)
                {
                    if(l[i+c][j]>=c+1&&r[i+c][j]>=c+1) res++;
                    else break;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}