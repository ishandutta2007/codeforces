#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++) cin >> p[i];
    vector<vector<int>> res(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        int sz=n-i;
        vector<int> pn(sz+1,0);
        vector<bool> vis(n+1,0);
        for(int j=1;j<=sz;j++)
        {
            if(vis[p[j]]==0&&p[j]>i)
            {
                pn[j]=p[j];
                vis[p[j]]=1;
            }
            else if(vis[p[j+1]]==0&&p[j+1]>i)
            {
                pn[j]=p[j+1];
                vis[p[j+1]]=1;
            }
        }
        int r=i;
        for(int c=1;r<=n;r++,c++)
        {
            res[r][c]=p[c];
        }
        p=pn;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) cout << res[i][j] << " \n"[j==i];
    return 0;
}