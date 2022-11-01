#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int N=200005;
struct DSU
{
    vector<int> p;
    vector<int> sz;
    DSU(int n)
    {
        p.assign(n+1,0);
        for(int i=0;i<=n;i++) p[i]=i;
        sz.assign(n+1,1);
    }
    int find_set(int a)
    {
        if(a==p[a]) return a;
        else return p[a]=find_set(p[a]);
    }
    int merge_sets(int a,int b) //returns component with smaller size, or -1 if they are already connected
    {
        int origa=a;
        int origb=b;
        a=find_set(a);
        b=find_set(b);
        if(a==b) return -1;
        if(sz[a]<sz[b])
        {
            swap(a,b);
            swap(origa,origb);
        }
        p[b]=a;
        sz[a]+=sz[b];
        return origb;
    }
};
 
vector<set<int>> v(N);
vector<int> val(N,0);
vector<int> leader(N,0);
vector<set<int>> s(2*N);
int lidx=1;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<array<int,2>> edges(m+1,{0,0});
    DSU dsu(n);
    for(int i=1;i<=n;i++) cin >> val[i];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        edges[i]={a,b};
        v[a].insert(b);
        v[b].insert(a);
    }
    vector<bool> removed_edges(m+1,0);
    vector<array<int,2>> queries(q+1,{0,0});
    for(int i=1;i<=q;i++)
    {
        int t,a;
        cin >> t >> a;
        queries[i]={t,a};
        if(t==2) removed_edges[a]=1;
    }
    vector<int> disconnects(q+1,0); //0 if nothing is disconnected, the vertex with smaller current size otherwise
    for(int i=1;i<=m;i++) if(removed_edges[i]==0) dsu.merge_sets(edges[i][0],edges[i][1]);
    for(int i=q;i>=1;i--)
    {
        auto [t,a]=queries[i];
        if(t==1) continue;
        int x=dsu.merge_sets(edges[a][0],edges[a][1]);
        if(x!=-1) disconnects[i]=x;
    }
    for(int i=1;i<=n;i++)
    {
        if(leader[i]!=0) continue;
        queue<int> z;
        z.push(i);
        int now=lidx++;
        leader[i]=now;
        s[now].insert(val[i]);
        while(!z.empty())
        {
            int a=z.front();
            z.pop();
            for(int to:v[a])
            {
                if(leader[to]!=0) continue;
                leader[to]=now;
                s[now].insert(val[to]);
                z.push(to);
            }
        }
    }
    vector<bool> used(n+1,0);
    vector<int> h(n+1,0);
    for(int i=1;i<=n;i++) h[val[i]]=i;
    //set val[a]=0;
    for(int i=1;i<=q;i++)
    {
        auto [t,a]=queries[i];
        if(t==1)
        {
            int res=0;
            if(!s[leader[a]].empty())
            {
                int mx=(*s[leader[a]].rbegin());
                s[leader[a]].erase(mx);
                val[h[mx]]=0;
                res=mx;
            }
            cout << res << "\n";
        }
        else if(t==2)
        {
            auto [x,y]=edges[a];
            v[x].erase(y);
            v[y].erase(x);
            int src=disconnects[i];
            if(src!=0)
            {
                queue<int> z;
                z.push(src);
                int prv=leader[src];
                int now=lidx++;
                leader[src]=now;
                if(val[src]!=0) s[prv].erase(val[src]);
                if(val[src]!=0) s[now].insert(val[src]);
                while(!z.empty())
                {
                    int e=z.front();
                    z.pop();
                    for(int to:v[e])
                    {
                        if(leader[to]==now) continue;
                        leader[to]=now;
                        z.push(to);
                        if(val[to]!=0) s[prv].erase(val[to]);
                        if(val[to]!=0) s[now].insert(val[to]);
                    }
                }
            }
        }
    }
    return 0;
}