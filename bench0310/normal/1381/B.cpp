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
        vector<vector<bool>> now(n+1,vector<bool>(2,0));
        now[0][0]=1;
        int m=0;
        for(int i=1;i<=2*n;i++)
        {
            int p;
            cin >> p;
            vector<vector<bool>> nxt(n+1,vector<bool>(2,0));
            for(int j=0;j<=n;j++)
            {
                for(int x=0;x<2;x++)
                {
                    if(x==0&&j+1<=n) nxt[j+1][x]=nxt[j+1][x]|now[j][x];
                    if(x==1) nxt[j][x]=nxt[j][x]|now[j][x];
                    if(p>m)
                    {
                        if(x==0) nxt[j][1-x]=nxt[j][1-x]|now[j][x];
                        if(x==1&&j+1<=n) nxt[j+1][1-x]=nxt[j+1][1-x]|now[j][x];
                    }
                }
            }
            m=max(m,p);
            now=nxt;
        }
        if(now[n][0]||now[n][1]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}