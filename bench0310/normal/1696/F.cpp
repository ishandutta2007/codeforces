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
        vector s(n+1,vector(n+1,string()));
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) cin >> s[i][j];
        auto eq=[&](int a,int b,int c)->bool //does d(a,c)=d(b,c) hold
        {
            if(a>b) swap(a,b);
            return (s[a][b][c-1]=='1');
        };
        //split into depth groups
        vector<vector<int>> g;
        int groups=0;
        for(int i=2;i<=n;i++)
        {
            bool done=0;
            for(int j=0;j<groups;j++)
            {
                if(eq(i,g[j][0],1))
                {
                    g[j].push_back(i);
                    done=1;
                }
            }
            if(!done)
            {
                groups++;
                g.push_back({i});
            }
        }
        //bruteforce g_1, then check
        auto res=[&]()->vector<array<int,2>>
        {
            for(int o=0;o<groups;o++)
            {
                vector<int> p(n+1,-1);
                p[1]=0;
                queue<int> q;
                for(int a:g[o])
                {
                    p[a]=1;
                    q.push(a);
                }
                while(!q.empty())
                {
                    int a=q.front();
                    q.pop();
                    for(int i=1;i<=n;i++)
                    {
                        if(p[i]==-1&&eq(i,p[a],a))
                        {
                            p[i]=a;
                            q.push(i);
                        }
                    }
                }
                vector d(n+1,vector(n+1,int(1<<29)));
                bool ok=1;
                for(int i=1;i<=n;i++)
                {
                    d[i][i]=0;
                    if(i>=2)
                    {
                        if(p[i]!=-1) d[i][p[i]]=d[p[i]][i]=1;
                        else ok=0;
                    }
                }
                if(!ok) continue;
                for(int k=1;k<=n;k++)
                {
                    for(int i=1;i<=n;i++)
                    {
                        for(int j=1;j<=n;j++)
                        {
                            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                        }
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    for(int j=i+1;j<=n;j++)
                    {
                        for(int k=1;k<=n;k++)
                        {
                            ok&=((d[i][k]==d[j][k])==(s[i][j][k-1]=='1'));
                        }
                    }
                }
                if(ok)
                {
                    vector<array<int,2>> v;
                    for(int i=2;i<=n;i++) v.push_back({p[i],i});
                    return v;
                }
            }
            return {};
        }();
        if(!res.empty())
        {
            cout << "Yes\n";
            for(auto [a,b]:res) cout << a << " " << b << "\n";
        }
        else cout << "No\n";
    }
    return 0;
}