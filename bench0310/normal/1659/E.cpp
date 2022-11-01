#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> v[n+1];
    vector<int> good(n+1,0);
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
        if((w%2)==0) good[a]=good[b]=1;
    }
    vector c(n+1,vector(30,int(0)));
    vector ok(n+1,vector(30,int(0)));
    for(int b=0;b<30;b++)
    {
        int id=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i][b]!=0) continue;
            id++;
            vector<int> q={i};
            c[i][b]=id;
            int idx=0;
            while(idx<(int)q.size())
            {
                int a=q[idx++];
                for(auto [to,w]:v[a])
                {
                    if((w&(1<<b))&&c[to][b]==0)
                    {
                        c[to][b]=id;
                        q.push_back(to);
                    }
                }
            }
            int g=0;
            for(int a:q) g|=good[a];
            for(int a:q) ok[a][b]=g;
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        int zero=0;
        for(int i=0;i<30;i++) zero|=(c[a][i]==c[b][i]);
        int one=zero;
        for(int i=1;i<30;i++) one|=(ok[a][i]);
        cout << 2-zero-one << "\n";
    }
    return 0;
}