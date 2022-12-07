//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
int n, q, ar[sz], lg, rg, zap[sz][3], ord[sz], inf=1e9;
vector <int> ch[sz], dot[sz*4], an;
bool us[sz];
bool comp(int a, int b){return zap[a][1]>zap[b][1];}
int checkq(int x, int q)
{
    int p=lower_bound(ch[x].begin(), ch[x].end(), lg)-ch[x].begin();
    if(p+q-1<ch[x].size())
    {
        return (ch[x][p+q-1]<=rg);
    }
    else return 0;
}
void recalc(int nu, int l, int r)
{
    int mi=(r-l+1)/5+1;
    lg=l, rg=r;
    for(int a=0; a<dot[nu*2].size(); a++)
    {
        int cu=dot[nu*2][a];
        us[cu]=1;
        if(checkq(cu, mi)) dot[nu].push_back(cu);
    }
    for(int a=0; a<dot[nu*2+1].size(); a++)
    {
        int cu=dot[nu*2+1][a];
        if(us[cu]==0)
        {
            if(checkq(cu, mi)) dot[nu].push_back(cu);
        }
    }
    for(int a=0; a<dot[nu*2].size(); a++) us[dot[nu*2][a]]=0;
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu].push_back(ar[l]);
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu, l, r);
    }
}
void que(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        for(int a=0; a<dot[nu].size(); a++) an.push_back(dot[nu][a]);
    }
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)/2;
        que(nu*2, l, mid);
        que(nu*2+1, mid+1, r);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>q;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        us[a+1]=0, ch[ar[a]].push_back(a);
    }
    build(1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        ord[a]=a;
        for(int b=0; b<3; b++) scanf("%d", &zap[a][b]);
    }
    sort(ord, ord+q, comp);
    int ans[q], yk=n-1;
    for(int a=0; a<q; a++)
    {
        int cu=ord[a];
        lg=zap[cu][0]-1, rg=zap[cu][1]-1;
        int cq=(rg-lg+1)/zap[cu][2]+1;
        for(int b=yk; b>rg; b--) ch[ar[b]].pop_back();
        yk=rg;
        an.clear();
        que(1, 0, n-1);
        ans[cu]=inf;
        for(int b=0; b<an.size(); b++)
        {
            int x=an[b];
            int si=ch[x].size();
            if(si>=cq)
            {
                if(ch[x][si-cq]>=lg) ans[cu]=min(ans[cu], x);
            }
        }
        if(ans[cu]==inf) ans[cu]=-1;
    }
    for(int a=0; a<q; a++) printf("%d\n", ans[a]);
}