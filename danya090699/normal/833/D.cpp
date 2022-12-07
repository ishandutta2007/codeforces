//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, mod=1e9+7, inf=2e9;
struct re
{
    int to, va;
    bool co;
};
re nel;
int n, anch=1, anzn=1, cuq, si[sz], sq, cu, lg, rg, add;
vector <re> sv[sz];
vector <pair <int, pair <int, int> > > pa[sz];
pair <int, int> dot[2][sz*8];
pair <int, int> recalc(pair <int, int> l, pair <int, int> r)
{
    pair <int, int> re;
    re.first=(1ll*l.first*r.first)%mod;
    re.second=l.second+r.second;
    return re;
}
void build(int nu, int l, int r)
{
    dot[cu][nu].first=1, dot[cu][nu].second=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
    }
}
void cha(int nu, int l, int r)
{
    if(l==r)
    {
        dot[cu][nu].first=(1ll*dot[cu][nu].first*add)%mod, dot[cu][nu].second++;
    }
    else
    {
        int mid=(l+r)/2;
        if(lg<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        dot[cu][nu]=recalc(dot[cu][nu*2], dot[cu][nu*2+1]);
    }
}
pair <int, int> que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[cu][nu];
    else if(l>rg or r<lg) return make_pair(1, 0);
    else
    {
        int mid=(l+r)/2;
        return recalc(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
    }
}
int pow(int x, int y)
{
    if(y==0) return 1;
    else if(y%2==1) return (1ll*pow(x, y-1)*x)%mod;
    else
    {
        int t=pow(x, y/2);
        return (1ll*t*t)%mod;
    }
}
void siz(int v, int pr)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].to;
        if(ne!=pr)
        {
            siz(ne, v);
            si[v]+=si[ne];
        }
    }
}
int find_ce(int v, int pr)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].to;
        if(ne!=pr and si[ne]>cuq/2) return find_ce(ne, v);
    }
    if(pr!=-1) si[pr]=cuq-si[v];
    return v;
}
void dfs2(int v, int pr, int rq, int bq, int le)
{
    pa[sq].push_back(make_pair(le, make_pair(rq, bq)));
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].to, r=0, b=0, nle=sv[v][a].va;
        if(sv[v][a].co==0) r++;
        else b++;
        if(ne!=pr) dfs2(ne, v, rq+r, bq+b, (1ll*le*nle)%mod);
    }
}
void dfs(int v, int q)
{
    cuq=q;
    siz(v, -1);
    int ce=find_ce(v, -1);
    sq=1;
    pa[0].push_back(make_pair(1, make_pair(0, 0)));
    for(int a=0; a<sv[ce].size(); a++)
    {
        int ne=sv[ce][a].to, rq=0, bq=0, le=sv[ce][a].va;
        if(sv[ce][a].co==0) rq=1;
        else bq=1;
        dfs2(ne, ce, rq, bq, le), sq++;
    }
    q++;
    cu=0, build(1, 0, q*2);
    cu=1, build(1, 0, q*2);
    for(int a=0; a<sq; a++)
    {
        for(int b=0; b<pa[a].size(); b++)
        {
            int le=pa[a][b].first, rq=pa[a][b].second.first, bq=pa[a][b].second.second;
            cu=0, lg=0, rg=-(bq-rq*2)+q;
            int qq;
            pair <int, int> ans=que(1, 0, q*2);
            qq=ans.second, anch=(1ll*anch*ans.first)%mod;
            cu=1, lg=0, rg=-(bq*2-rq)-1+q;
            ans=que(1, 0, q*2);
            qq-=ans.second, anzn=(1ll*anzn*ans.first)%mod;
            anch=(1ll*anch*pow(le, qq))%mod;
        }
        for(int b=0; b<pa[a].size(); b++)
        {
            int le=pa[a][b].first, rq=pa[a][b].second.first, bq=pa[a][b].second.second;
            cu=0, lg=(bq-rq*2)+q, add=le;
            cha(1, 0, q*2);
            cu=1, lg=(bq*2-rq)+q, add=le;
            cha(1, 0, q*2);
        }
        pa[a].clear();
    }
    while(sv[ce].size()>0)
    {
        int ne=sv[ce].back().to;
        for(int b=0; b<sv[ne].size(); b++) if(sv[ne][b].to==ce) sv[ne].erase(sv[ne].begin()+b);
        sv[ce].pop_back();
        dfs(ne, si[ne]);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v, va, co;
        scanf("%d%d%d%d", &u, &v, &va, &co);
        u--, v--;
        nel.to=v, nel.va=va, nel.co=co;
        sv[u].push_back(nel);
        nel.to=u, sv[v].push_back(nel);
    }
    dfs(0, n);
    int ans=(1ll*anch*pow(anzn, mod-2))%mod;
    cout<<ans;
}