#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
int n;
const int inf=N;
vector<int> v[N];
vector<vector<int>> p(N,vector<int>(17,0));
vector<int> depth(N,0);
vector<int> sz(N,0);
vector<int> big(N,0);
vector<int> pos(N,0);
vector<int> head(N,0);
vector<int> tree(4*N,inf);
vector<vector<int>> city(4*N,{inf});
int tcnt=1;

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<17;i++) p[a][i]=p[p[a][i-1]][i-1];
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
        sz[a]+=sz[to];
        if(sz[to]>sz[big[a]]) big[a]=to;
    }
}

void decompose(int a,int h)
{
    pos[a]=tcnt++;
    head[a]=h;
    if(big[a]!=0) decompose(big[a],h);
    for(int to:v[a])
    {
        if(to==p[a][0]||to==big[a]) continue;
        decompose(to,to);
    }
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=16;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=16;i>=0;i--)
    {
        if(p[a][i]!=p[b][i])
        {
            a=p[a][i];
            b=p[b][i];
        }
    }
    return p[a][0];
}

void update(int idx,int l,int r,int id,int val)
{
    if(l==r)
    {
        if(city[idx].back()!=val) city[idx].push_back(val);
        else city[idx].pop_back();
        tree[idx]=city[idx].back();
    }
    else
    {
        int m=(l+r)/2;
        if(id<=m) update(2*idx,l,m,id,val);
        else update(2*idx+1,m+1,r,id,val);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return inf;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int up(int a,int b)
{
    int res=inf;
    while(depth[head[b]]>depth[a])
    {
        res=min(res,query(1,1,n,pos[head[b]],pos[b]));
        b=p[head[b]][0];
    }
    res=min(res,query(1,1,n,pos[a],pos[b]));
    return res;
}

int qry(int a,int b)
{
    int l=lca(a,b);
    return min(up(l,a),up(l,b));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,q;
    cin >> n >> m >> q;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    decompose(1,1);
    vector<int> c(m+1,0);
    for(int i=1;i<=m;i++) cin >> c[i];
    for(int i=m;i>=1;i--) update(1,1,n,pos[c[i]],i);
    while(q--)
    {
        int a,b,x;
        cin >> a >> b >> x;
        vector<int> res;
        while(x--)
        {
            int now=qry(a,b);
            if(now==inf) break;
            res.push_back(now);
            update(1,1,n,pos[c[now]],now);
        }
        cout << res.size();
        for(int now:res) cout << " " << now;
        cout << "\n";
        for(int i=(int)res.size()-1;i>=0;i--) update(1,1,n,pos[c[res[i]]],res[i]);
    }
    return 0;
}