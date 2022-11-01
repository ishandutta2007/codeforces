#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,w;
    cin >> n >> m >> w;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];
    vector<array<int,2>> z={{1,0},{-1,0},{0,-1},{0,1}};
    auto in=[&](int r,int c)->bool{return (0<=r&&r<n&&0<=c&&c<m);};
    const ll inf=(1ll<<60);
    ll res=inf;
    auto go=[&](int sr,int sc)->ll
    {
        queue<array<ll,3>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        vis[sr][sc]=1;
        q.push({sr,sc,0});
        ll best=inf;
        while(!q.empty())
        {
            auto [r,c,d]=q.front();
            q.pop();
            if(a[r][c]>0) best=min(best,d+a[r][c]);
            if(sr==0&&sc==0&&r==n-1&&c==m-1) res=d;
            for(auto [dr,dc]:z)
            {
                int nr=r+dr;
                int nc=c+dc;
                if(in(nr,nc)&&a[nr][nc]!=-1&&vis[nr][nc]==0)
                {
                    q.push({nr,nc,d+w});
                    vis[nr][nc]=1;
                }
            }
        }
        return best;
    };
    ll t=go(0,0)+go(n-1,m-1);
    res=min(res,t);
    if(res==inf) res=-1;
    cout << res << "\n";
    return 0;
}