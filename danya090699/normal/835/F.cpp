//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10;
vector <pair <int, int> > sv[sz];
int us[sz*2], pr[sz], prle[sz], fo=-1, lg, add=1, ban=0;
int ve[sz*2], re[sz*2];
void dfs(int v, int pre, int le)
{
    if(fo==-1)
    {
        pr[v]=pre, prle[v]=le;
        if(us[v]==1) fo=v;
        else
        {
            us[v]=1;
            for(int a=0; a<sv[v].size(); a++)
            {
                int ne=sv[v][a].first, nle=sv[v][a].second;
                if(us[ne]!=2 and ne!=pre) dfs(ne, v, nle);
            }
            us[v]=2;
        }
    }
}
int dfs2(int v)
{
    int ma=0, prbe=0;
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, nle=sv[v][a].second;
        if(us[ne]==0)
        {
            int cu=dfs2(ne)+nle;
            ma=max(ma, cu);
            ban=max(ban, prbe+cu);
            prbe=max(prbe, cu);
        }
    }
    return ma;
}
struct el
{
    int be=0, su=0, pref=0, suf=0;
};
el dot[sz*8];
void recalc(int nu, int gr)
{
    int va=0;
    if(us[gr]) va=ve[gr];
    dot[nu].be=max(dot[nu*2].be, dot[nu*2+1].be);
    dot[nu].be=max(dot[nu].be, dot[nu*2].suf+dot[nu*2+1].pref);
    dot[nu].su=dot[nu*2].su+dot[nu*2+1].su;
    dot[nu].pref=max(dot[nu*2].pref, dot[nu*2].su+max(dot[nu*2+1].pref, va));
    dot[nu].suf=max(dot[nu*2+1].suf, dot[nu*2+1].su+max(dot[nu*2].suf, va));
}
void cha(int nu, int l, int r)
{
    if(l==r)
    {
        if(add)
        {
            dot[nu].be=ve[l]+re[l]+ve[l+1];
            dot[nu].su=re[l];
            dot[nu].pref=ve[l+1]+re[l];
            dot[nu].suf=ve[l]+re[l];
        }
        else
        {
            dot[nu].be=0, dot[nu].su=0, dot[nu].pref=0, dot[nu].suf=0;
        }
    }
    else
    {
        int mid=(l+r)/2;
        if(lg<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        recalc(nu, mid+1);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        us[a]=0;
        int u, v, pri;
        scanf("%lld%lld%lld", &u, &v, &pri);
        u--, v--;
        sv[u].push_back(make_pair(v, pri));
        sv[v].push_back(make_pair(u, pri));
    }
    dfs(0, -1, 0);
    for(int a=0; a<n; a++) us[a]=0;
    int q=0, cu=fo;
    while(1)
    {
        ve[q]=cu, us[cu]=1;
        re[q]=prle[cu], q++;
        cu=pr[cu];
        if(cu==fo) break;
    }
    for(int a=0; a<q; a++) ve[a]=dfs2(ve[a]);
    for(int a=0; a<q; a++)
    {
        ve[a+q]=ve[a], re[a+q]=re[a];
    }
    for(int a=0; a<q*2; a++)
    {
        if(a<q) us[a]=1;
        else us[a]=0;
    }
    for(int a=0; a<q-1; a++)
    {
        lg=a, cha(1, 0, q*2-2);
    }
    int an=1e18;
    for(int a=0; a<q; a++)
    {
        an=min(an, dot[1].be);
        us[a]=0;
        lg=a, add=0, cha(1, 0, q*2-2);
        us[a+q]=1;
        lg=a+q-1, add=1, cha(1, 0, q*2-2);
    }
    cout<<max(an, ban);
}