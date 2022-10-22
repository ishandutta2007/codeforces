#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 100005

vector<pii> g[MAXN],node_dis;
vector<int> nodes;
bool mk[MAXN],nk[MAXN];
int n,l,w;
int sons[MAXN][2];
ll res;

struct node{
    int cant;
    vector<pii> vvv;
    node *six,*sax,*siy,*say;
    node() : cant(0),six(0),sax(0),siy(0),say(0) {}
};

void update(node *p,int ix,int ax,int iy,int ay,int px,int py,bool flag)
{
    p->cant++;
    if(p->cant<=15000)
    {
        p->vvv.push_back(pii(px,py));
        return;
    }
    else if(p->cant==15001)
    {
        for(auto y : p->vvv)
            update(p,ix,ax,iy,ay,y.first,y.second,flag);
        p->vvv.clear();
        p->cant=15001;
    }
    if(!flag && ix!=ax)
    {
        int mid=(ix+ax)>>1;
        if(px>mid)
        {
            if(!(p->sax))
                p->sax=new node();
            update(p->sax,mid+1,ax,iy,ay,px,py,0);
        }
        else
        {
            if(!(p->six))
                p->six=new node();
            update(p->six,ix,mid,iy,ay,px,py,0);
        }
    }
    if(iy!=ay)
    {
        int mid=(iy+ay)>>1;
        if(py>mid)
        {
            if(!(p->say))
                p->say=new node();
            update(p->say,ix,ax,mid+1,ay,px,py,1);
        }
        else
        {
            if(!(p->siy))
                p->siy=new node();
            update(p->siy,ix,ax,iy,mid,px,py,1);
        }
    }
}

ll query(node *p,int ix,int ax,int iy,int ay,int px,int py)
{
    if(p->cant<=15000)
    {
        int sol=0;
        for(auto y : p->vvv)
            sol+=(px>=y.first && py>=y.second);
        return sol;
    }
    if(ax<=px && ay<=py)
        return p->cant;
    if(ax>px)
    {
        int mid=(ix+ax)>>1;
        if(px>mid)
        {
            int r1,r2;
            if(!(p->sax))
                r1=0;
            else
                r1=query(p->sax,mid+1,ax,iy,ay,px,py);
            if(!(p->six))
                r2=0;
            else
                r2=query(p->six,ix,mid,iy,ay,px,py);
            return r1+r2;
        }
        else
        {
            if(!(p->six))
                return 0;
            return query(p->six,ix,mid,iy,ay,px,py);
        }
    }
    else
    {
        int mid=(iy+ay)>>1;
        if(py>mid)
        {
            int r1,r2;
            if(!(p->say))
                r1=0;
            else
                r1=query(p->say,ix,ax,mid+1,ay,px,py);
            if(!(p->siy))
                r2=0;
            else
                r2=query(p->siy,ix,ax,iy,mid,px,py);
            return r1+r2;
        }
        else
        {
            if(!(p->siy))
                return 0;
            return query(p->siy,ix,ax,iy,mid,px,py);
        }
    }
}

void dfs(int u)
{
    sons[u][0]=nk[u]=1;
    nodes.push_back(u);
    for(auto y : g[u])
    {
        int v=y.first;
        if(!mk[v] && !nk[v])
        {
            dfs(v);
            sons[u][0]+=sons[v][0];
            sons[u][1]=max(sons[u][1],sons[v][0]);
        }
    }
}

void dfsd(int u,int d1,int d2)
{
    nk[u]=1;
    node_dis.push_back(pii(d1,d2));
    nodes.push_back(u);
    for(auto y : g[u])
    {
        int v=y.first,w1=y.second;
        if(!mk[v] && !nk[v])
            dfsd(v,d1+w1,d2+1);
    }
}

void solve(int u)
{
    dfs(u);

    int cent=-1,cant=(nodes.size()>>1);
    for(auto v : nodes)
    {
        if(cent==-1 && sons[v][0]>=cant && sons[v][1]<=cant)
            cent=v;
        sons[v][0]=sons[v][1]=nk[v]=0;
    }
    nodes.clear();

    mk[cent]=1;
    node* st=new node();
    update(st,0,l,0,w,0,0,0);
    for(auto y : g[cent])
    {
        int v=y.first;
        if(!mk[v])
        {
            dfsd(v,y.second,1);

            for(auto y : node_dis)
            {
                int l1=l-y.second;
                int w1=w-y.first;
                if(l1>=0 && w1>=0)
                    res+=query(st,0,l,0,w,l1,w1);
            }

            for(auto y : node_dis)
                if(y.second<=l && y.first<=w)
                    update(st,0,l,0,w,y.second,y.first,0);
            node_dis.clear();
        }
    }

    for(auto v : nodes)
        nk[v]=0;
    nodes.clear();
    for(auto y : g[cent])
        if(!mk[y.first])
            solve(y.first);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int u,w1;
    cin >> n >> l >> w;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> w1;
        u--;
        g[u].push_back(pii(i+1,w1));
        g[i+1].push_back(pii(u,w1));
    }

    solve(0);

    db(res)

    return 0;
}