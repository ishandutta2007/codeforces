#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
vector<int> tree(4*N,0);

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

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
        vector<int> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<array<int,19>> p(n+1);
        for(int i=0;i<=n;i++) p[i].fill(0);
        vector<int> depth(n+1,0);
        vector<int> tin(n+1,0);
        vector<int> tout(n+1,0);
        vector<int> h(n+1,0);
        int tcnt=0;
        function<void(int)> dfs=[&](int a)
        {
            depth[a]=depth[p[a][0]]+1;
            for(int i=1;i<19;i++) p[a][i]=p[p[a][i-1]][i-1];
            tin[a]=(++tcnt);
            h[tcnt]=a;
            for(int to:v[a])
            {
                if(to==p[a][0]) continue;
                p[to][0]=a;
                dfs(to);
            }
            tout[a]=tcnt;
        };
        dfs(1);
        auto lca=[&](int a,int b)->int
        {
            if(depth[a]>depth[b]) swap(a,b);
            for(int i=18;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
            if(a==b) return a;
            for(int i=18;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
            return p[a][0];
        };
        vector<int> ord;
        for(int i=1;i<=n;i++) ord.push_back(i);
        ranges::sort(ord,[&](int a,int b){return (depth[a]>depth[b]);});
        vector<int> res(n+1,n);
        int idx=0;
        set<int> s;
        int d=0;
        for(int lim=n;lim>=1;lim--)
        {
            while(idx<n&&depth[ord[idx]]-1>lim)
            {
                int a=ord[idx++];
                auto it=s.lower_bound(tin[a]);
                int u=a;
                if(it!=s.end())
                {
                    int l=lca(a,h[*it]);
                    if(u==a||depth[l]>depth[u]) u=l;
                }
                if(it!=s.begin())
                {
                    it--;
                    int l=lca(a,h[*it]);
                    if(u==a||depth[l]>depth[u]) u=l;
                }
                d=max(d,depth[a]+query(1,1,n,tin[u],tout[u])-2*depth[u]);
                update(1,1,n,tin[a],depth[a]);
                s.insert(tin[a]);
            }
            int y=(d+1)/2;
            int x=max(0,lim-y);
            res[x]=lim;
        }
        res[n]=depth[ord[0]]-1;
        for(int i=n-1;i>=1;i--) res[i]=min(res[i],res[i+1]);
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
        for(int i=1;i<=n;i++) update(1,1,n,i,0);
    }
    return 0;
}