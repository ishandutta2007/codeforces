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
        vector<int> v[n+1];
        vector<int> va(n+1,0);
        for(int i=2;i<=n;i++)
        {
            cin >> va[i];
            va[i]++;
        }
        vector<int> vb(n+1,0);
        for(int i=2;i<=n;i++) cin >> vb[i];
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),[&](int a,int b)->bool{return (va[a]<va[b]);});
        vector<bool> vis(n+1,0);
        vector<int> adj(n+1,0);
        int unvis=n;
        ll res=0;
        ll now=0;
        auto make_vis=[&](int a)
        {
            now+=vb[a];
            va[a]=vb[a]=0;
            vis[a]=1;
            for(int to:v[a]) adj[to]=a;
            unvis--;
        };
        make_vis(1);
        auto go=[&](ll up,bool mv)->bool
        {
            vector<int> p(n+1,0);
            vector<ll> pw(n+1,0);
            queue<int> q;
            for(int i=1;i<=n;i++)
            {
                if(adj[i]!=0&&!vis[i]&&up>=va[i]&&p[i]==0)
                {
                    q.push(i);
                    p[i]=adj[i];
                    pw[i]=up+vb[i];
                }
                if(vis[i]) p[i]=i;
            }
            int one=0,two=0;
            while(!q.empty())
            {
                int a=q.front();
                q.pop();
                for(int to:v[a])
                {
                    if(to==p[a]) continue;
                    if(p[to]!=0)
                    {
                        one=a;
                        two=to;
                    }
                    if(pw[a]<va[to]) break;
                    if(p[to]==0)
                    {
                        p[to]=a;
                        pw[to]=pw[a]+vb[to];
                        q.push(to);
                    }
                }
            }
            if(one==0) return 0;
            if(mv)
            {
                while(p[one]!=one)
                {
                    make_vis(one);
                    one=p[one];
                }
                while(!vis[two])
                {
                    make_vis(two);
                    two=p[two];
                }
            }
            return 1;
        };
        while(unvis>0)
        {
            int l=-1,r=(1<<30);
            while(l<r-1)
            {
                int mid=(l+r)/2;
                if(go(now+mid,0)) r=mid;
                else l=mid;
            }
            now+=r;
            res+=r;
            go(now,1);
        }
        cout << res << "\n";
    }
    return 0;
}