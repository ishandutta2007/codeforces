#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
vector <pair <int, int> > dot[sz*4];
int lg, rg;
pair <int, int> va;
void ins(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[nu].push_back(va);
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        ins(nu*2, l, mid);
        ins(nu*2+1, mid+1, r);
    }
}
int pr[sz*2], qx[sz*2], qy[sz*2];

int find_pr(int v)
{
    if(pr[v]==v) return v;
    else return find_pr(pr[v]);
}

long long an=0;

void calc(int nu, int l, int r)
{
    for(int a=0; a<dot[nu].size(); a++)
    {
        int u=dot[nu][a].first, v=dot[nu][a].second;
        u=find_pr(u), v=find_pr(v);
        if(qx[u]+qy[u]<qx[v]+qy[v]) swap(u, v);
        dot[nu][a]={u, v};
        if(u!=v)
        {
            an-=1ll*qx[u]*qy[u]+1ll*qx[v]*qy[v];
            qx[u]+=qx[v], qy[u]+=qy[v];
            pr[v]=u;
            an+=1ll*qx[u]*qy[u];
        }
    }

    if(l==r) printf("%lld ", an);
    else
    {
        int mid=(l+r)>>1;
        calc(nu*2, l, mid);
        calc(nu*2+1, mid+1, r);
    }

    reverse(dot[nu].begin(), dot[nu].end());
    for(int a=0; a<dot[nu].size(); a++)
    {
        int u=dot[nu][a].first, v=dot[nu][a].second;
        if(u!=v)
        {
            an-=1ll*qx[u]*qy[u];
            pr[v]=v;
            qx[u]-=qx[v], qy[u]-=qy[v];
            an+=1ll*qx[u]*qy[u]+1ll*qx[v]*qy[v];
        }
    }
}
int main()
{
    for(int a=0; a<sz*2; a++) pr[a]=a;
    for(int a=0; a<sz; a++) qx[a]=1;
    for(int a=sz; a<sz*2; a++) qy[a]=1;

    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <pair <int, int>, int> ma;
    for(int a=0; a<n; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(ma.count({x, y}))
        {
            lg=ma[{x, y}], rg=a-1, va={x, y+sz};
            //cout<<lg<<" "<<rg<<" "<<x<<" "<<y<<"\n";
            ins(1, 0, n-1);

            ma.erase({x, y});
        }
        else ma[{x, y}]=a;
    }
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        lg=(*it).second, rg=n-1, va=(*it).first;
        va.second+=sz;
        ins(1, 0, n-1);
    }
    calc(1, 0, n-1);
}