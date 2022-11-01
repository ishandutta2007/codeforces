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
        vector<string> s(n);
        for(int i=0;i<n;i++) cin >> s[i];
        vector vis(n,vector(m,bool(0)));
        auto in=[&](int r,int c)->bool{return (0<=r&&r<n&&0<=c&&c<m);};
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]||s[i][j]=='.') continue;
                queue<array<int,2>> q;
                int rmn=i,rmx=i,cmn=j,cmx=j;
                int cnt=0;
                auto add=[&](int r,int c)
                {
                    q.push({r,c});
                    vis[r][c]=1;
                    cnt++;
                    rmn=min(rmn,r);
                    rmx=max(rmx,r);
                    cmn=min(cmn,c);
                    cmx=max(cmx,c);
                };
                add(i,j);
                while(!q.empty())
                {
                    auto [r,c]=q.front();
                    q.pop();
                    for(int dr=-1;dr<=1;dr++)
                    {
                        for(int dc=-1;dc<=1;dc++)
                        {
                            if(dr==0&&dc==0) continue;
                            if(in(r+dr,c+dc)&&s[r+dr][c+dc]=='*'&&!vis[r+dr][c+dc]) add(r+dr,c+dc);
                        }
                    }
                }
                ok&=(cnt==3&&rmx-rmn==1&&cmx-cmn==1);
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}