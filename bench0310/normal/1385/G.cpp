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
        vector<array<int,2>> pos[n+1];
        for(int o=1;o<=2;o++)
        {
            for(int i=1;i<=n;i++)
            {
                int a;
                cin >> a;
                pos[a].push_back({o,i});
            }
        }
        bool ok=1;
        vector<int> v[n+1];
        vector<int> g[n+1];
        vector<array<int,2>> edges;
        for(int i=1;i<=n;i++)
        {
            ok&=(pos[i].size()==2);
            if(ok==0) break;
            auto [r1,c1]=pos[i][0];
            auto [r2,c2]=pos[i][1];
            if(c1==c2) continue;
            if(r1!=r2)
            {
                v[c1].push_back(c2);
                v[c2].push_back(c1);
            }
            else
            {
                g[c1].push_back(c2);
                g[c2].push_back(c1);
            }
        }
        if(ok==0)
        {
            cout << "-1\n";
            continue;
        }
        vector<int> id(n+1,0); //component id
        vector<int> comp[n+1]; //elements of component
        int idx=0;
        for(int i=1;i<=n;i++)
        {
            if(id[i]!=0) continue;
            queue<int> q;
            q.push(i);
            id[i]=++idx;
            while(!q.empty())
            {
                int a=q.front();
                q.pop();
                comp[idx].push_back(a);
                for(int to:v[a])
                {
                    if(id[to]!=0) continue;
                    q.push(to);
                    id[to]=idx;
                }
            }
        }
        vector<bool> vis(n+1,0);
        vector<int> res;
        for(int i=1;i<=n;i++)
        {
            if(vis[id[i]]==1) continue;
            vector<int> cycle={id[i]};
            vis[id[i]]=1;
            while(1)
            {
                int now=cycle.back();
                bool b=0;
                for(int x:comp[now])
                {
                    for(int to:g[x])
                    {
                        if(vis[id[to]]==0)
                        {
                            b=1;
                            cycle.push_back(id[to]);
                            vis[id[to]]=1;
                        }
                        if(b==1) break;
                    }
                    if(b==1) break;
                }
                if(b==0) break;
            }
            if(cycle.size()==1) continue;
            if(cycle.size()&1)
            {
                ok=0;
                break;
            }
            vector<int> c(2,0);
            for(int j=0;j<(int)cycle.size();j++) c[j&1]+=(comp[cycle[j]].size());
            for(int j=(c[1]<c[0]);j<(int)cycle.size();j+=2) for(int x:comp[cycle[j]]) res.push_back(x);
        }
        if(ok==1)
        {
            cout << res.size() << "\n";
            for(int a:res) cout << a << " ";
            cout << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}