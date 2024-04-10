#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector a(n+1,vector(m+1,int(0)));
    queue<array<int,2>> q;
    vector<array<int,3>> res;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            if(i<n&&j<m) q.push({i,j});
        }
    }
    auto in=[&](int r,int c)->bool{return (1<=r&&r<n&&1<=c&&c<m);};
    while(!q.empty())
    {
        auto [r,c]=q.front();
        q.pop();
        set<int> s;
        for(int i=0;i<=1;i++) for(int j=0;j<=1;j++) if(a[r+i][c+j]!=0) s.insert(a[r+i][c+j]);
        if(s.size()==1)
        {
            res.push_back({r,c,*s.begin()});
            for(int i=0;i<=1;i++) for(int j=0;j<=1;j++) a[r+i][c+j]=0;
            for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) if(in(r+i,c+j)) q.push({r+i,c+j});
        }
    }
    bool ok=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ok&=(a[i][j]==0);
    if(ok)
    {
        cout << res.size() << "\n";
        ranges::reverse(res);
        for(auto [r,c,col]:res) cout << r << " " << c << " " << col << "\n";
    }
    else cout << "-1\n";
    return 0;
}