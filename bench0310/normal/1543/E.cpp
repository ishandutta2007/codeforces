#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> colorings[17];
    for(int n=1;n<=16;n*=2)
    {
        int m=(1<<n);
        for(int i=0;i<m;i++)
        {
            int x=0;
            for(int j=0;j<n;j++) if(i&(1<<j)) x^=j;
            colorings[n].push_back(x);
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v[(1<<n)];
        int m=(1<<n);
        vector<int> col(m,-1);
        vector<int> h(m,-1);
        function<vector<int>(vector<array<int,2>>)> solve=[&](vector<array<int,2>> edges)->vector<int>
        {
            if(edges.size()==1) return {edges[0][0],edges[0][1]};
            vector<int> x;
            for(auto [a,b]:edges)
            {
                v[a].push_back(b);
                v[b].push_back(a);
                x.push_back(a);
                x.push_back(b);
            }
            sort(x.begin(),x.end());
            x.erase(unique(x.begin(),x.end()),x.end());
            queue<int> q;
            auto [one,two]=edges[0];
            col[one]=0;
            col[two]=1;
            q.push(one);
            q.push(two);
            while(!q.empty())
            {
                int a=q.front();
                q.pop();
                for(int to:v[a])
                {
                    if(col[to]==-1)
                    {
                        col[to]=col[a];
                        q.push(to);
                    }
                }
            }
            vector<array<int,2>> le,me;
            for(auto [a,b]:edges)
            {
                if(col[a]==0&&col[b]==0) le.push_back({a,b});
                if(col[a]!=col[b])
                {
                    if(col[a]==1) swap(a,b);
                    me.push_back({a,b});
                }
            }
            for(int a:x)
            {
                col[a]=-1;
                v[a].clear();
            }
            vector<int> p=solve(le);
            for(auto [a,b]:me) h[a]=b;
            int sz=p.size();
            for(int i=0;i<sz;i++) p.push_back(h[p[i]]);
            for(int a:x) h[a]=-1;
            return p;
        };
        vector<array<int,2>> edges;
        for(int i=0;i<n*(1<<(n-1));i++)
        {
            int a,b;
            cin >> a >> b;
            edges.push_back({a,b});
        }
        vector<int> p=solve(edges);
        for(int i=0;i<m;i++) cout << p[i] << " \n"[i==m-1];
        if(!colorings[n].empty())
        {
            vector<int> c(m,-1);
            for(int i=0;i<m;i++) c[p[i]]=colorings[n][i];
            for(int i=0;i<m;i++) cout << c[i] << " \n"[i==m-1];
        }
        else cout << "-1\n";
    }
    return 0;
}