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
        bool ok=1;
        auto chmin=[&](int &a,int b){a=min(a,b);};
        auto chmax=[&](int &a,int b){a=max(a,b);};
        vector<array<int,2>> z={{1,0},{-1,0},{0,-1},{0,1}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='0'||vis[i][j]) continue;
                int rmn=n,rmx=-1,cmn=m,cmx=-1;
                int cnt=0;
                queue<array<int,2>> q;
                auto add=[&](int r,int c)
                {
                    if(!(0<=r&&r<n&&0<=c&&c<m&&s[r][c]=='1')) return;
                    if(!vis[r][c])
                    {
                        q.push({r,c});
                        vis[r][c]=1;
                        cnt++;
                        chmin(rmn,r); chmax(rmx,r);
                        chmin(cmn,c); chmax(cmx,c);
                    }
                };
                add(i,j);
                while(!q.empty())
                {
                    auto [r,c]=q.front();
                    q.pop();
                    for(auto [dr,dc]:z) add(r+dr,c+dc);
                }
                ok&=((rmx-rmn+1)*(cmx-cmn+1)==cnt);
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}