#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n=41;
        int m=720;
        vector v(n+1,vector(m,int(0)));
        int w;
        cin >> w;
        while(w--)
        {
            char c;
            cin >> c;
            if(c=='C')
            {
                int r,a,b;
                cin >> r >> a >> b;
                for(int i=2*a;i!=(2*b+1)%m;i=(i+1)%m) v[2*r][i]=1;
            }
            if(c=='S')
            {
                int a,b,t;
                cin >> a >> b >> t;
                for(int i=2*a;i<=2*b;i++) v[i][2*t]=1;
            }
        }
        vector vis(n+1,vector(m,bool(0)));
        queue<array<int,2>> q;
        auto in=[&](int r)->bool{return (0<=r&&r<=n);};
        auto add=[&](int r,int t)
        {
            if(!vis[r][t]&&v[r][t]==0)
            {
                q.push({r,t});
                vis[r][t]=1;
            }
        };
        add(n,0);
        while(!q.empty())
        {
            auto [r,t]=q.front();
            q.pop();
            for(int dr=-1;dr<=1;dr+=2) if(in(r+dr)) add(r+dr,t);
            for(int dt=-1;dt<=1;dt+=2) add(r,(t+dt+m)%m);
        }
        if(vis[0][0]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}