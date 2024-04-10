#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<array<int,2>> g[N];
vector<array<int,2>> tree[N];
vector<vector<int>> components;
vector<int> col(N,0);
vector<array<int,2>> p(N,{-1,-1});
vector<double> res(N);
vector<bool> st(N,0); //is res already set

double odd_cycle(int x,int y,int abc)
{
    queue<int> q;
    p[x]={0,0};
    q.push(x);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(auto [to,c]:tree[a])
        {
            if(p[to][0]==-1)
            {
                p[to]={a,c};
                q.push(to);
            }
        }
    }
    vector<int> val;
    int now=y;
    while(now!=x)
    {
        val.push_back(p[now][1]);
        now=p[now][0];
    }
    int sum=abc;
    for(int i=0;i<(int)val.size();i++)
    {
        if(i&1) sum+=val[i];
        else sum-=val[i];
    }
    return ((double)sum/2);
}

void fill_values(int x)
{
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(auto [to,c]:g[a])
        {
            if(st[to]==0)
            {
                res[to]=c-res[a];
                st[to]=1;
                q.push(to);
            }
        }
    }
}

void ini(int src)
{
    vector<int> comp;
    queue<int> q;
    q.push(src);
    vector<array<int,3>> edges;
    col[src]=1;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        comp.push_back(a);
        for(auto [to,c]:g[a])
        {
            edges.push_back({a,to,c});
            if(col[to]==0)
            {
                tree[a].push_back({to,c});
                tree[to].push_back({a,c});
                col[to]=3-col[a];
                q.push(to);
            }
        }
    }
    for(auto [a,b,c]:edges)
    {
        if(col[a]==col[b])
        {
            res[a]=odd_cycle(a,b,c);
            st[a]=1;
            fill_values(a);
            break;
        }
    }
    components.push_back(comp);
}

double eval(vector<int> &comp,double x)
{
    for(int a:comp) st[a]=0;
    res[comp[0]]=x;
    fill_values(comp[0]);
    double now=0;
    for(int a:comp) now+=abs(res[a]);
    return now;
}

void ternary_search(vector<int> &comp)
{
    double l=-1e9,r=1e9;
    while(r-l>1e-12)
    {
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;
        if(eval(comp,m1)<eval(comp,m2)) r=m2;
        else l=m1;
    }
    eval(comp,l);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const double eps=1e-9;
    int n,m;
    cin >> n >> m;
    vector<array<int,3>> edges(m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        edges[i]={a,b,c};
    }
    for(int i=1;i<=n;i++) if(col[i]==0) ini(i);
    for(vector<int> &comp:components)
    {
        if(st[comp[0]]==1) continue;
        ternary_search(comp);
    }
    bool ok=1;
    for(auto [a,b,c]:edges) ok&=(abs((double)c-(res[a]+res[b]))<=eps);
    if(ok)
    {
        cout << "YES\n";
        for(int i=1;i<=n;i++) cout << fixed << setprecision(10) << res[i] << " \n"[i==n];
    }
    else cout << "NO\n";
    return 0;
}