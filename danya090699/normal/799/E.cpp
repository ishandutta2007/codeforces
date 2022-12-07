#include <bits/stdc++.h>
#define int long long
using namespace std;
struct el
{
    int va, ty;
};
el nel;
bool comp(el a, el b){return(a.va<b.va);}
vector <el> ar;
struct el2
{
    int q=0, va=0;
};
el2 *dot;
int lg, lef, cu;
void recalc(int nu)
{
    dot[nu].q=dot[nu*2].q+dot[nu*2+1].q;
    dot[nu].va=dot[nu*2].va+dot[nu*2+1].va;
}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        if(ar[l].ty==2)
        {
            dot[nu].q=1, dot[nu].va=ar[l].va;
        }
    }
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void ins(int nu, int l, int r)
{
    if(l==r)
    {
        dot[nu].q=1, dot[nu].va=ar[l].va;
    }
    else
    {
        int mid=(l+r)/2;
        if(lg<=mid) ins(nu*2, l, mid);
        else ins(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void que(int nu, int l, int r)
{
    if(l==r)
    {
        if(lef>0)
        {
            lef-=dot[nu].q, cu+=dot[nu].va;
        }
    }
    else
    {
        int mid=(l+r)/2;
        if(dot[nu*2].q>lef) que(nu*2, l, mid);
        else
        {
            lef-=dot[nu*2].q, cu+=dot[nu*2].va;
            que(nu*2+1, mid+1, r);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, mq, aq, mpr=0, apr=0, bpr=0, best=1e18;
    cin>>n>>m>>k;
    int pr[n];
    bool us[n][2];
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &pr[a]);
        us[a][0]=0, us[a][1]=0;
    }
    cin>>mq;
    for(int a=0; a<mq; a++)
    {
        int x;
        scanf("%lld", &x);
        x--;
        us[x][0]=1;
    }
    cin>>aq;
    for(int a=0; a<aq; a++)
    {
        int x;
        scanf("%lld", &x);
        x--;
        us[x][1]=1;
    }
    vector <int> ma, arc, both;
    vector <int> p_ma, p_arc;
    for(int a=0; a<n; a++)
    {
        if(us[a][0]==1 and us[a][1]==0) ma.push_back(pr[a]);
        else if(us[a][0]==0 and us[a][1]==1) arc.push_back(pr[a]);
        else if(us[a][0]==1 and us[a][1]==1) both.push_back(pr[a]);
        else
        {
            nel.va=pr[a], nel.ty=2;
            ar.push_back(nel);
        }
    }
    sort(both.begin(), both.end());
    sort(ma.begin(), ma.end());
    for(int a=0; a<ma.size(); a++)
    {
        nel.va=ma[a], nel.ty=0;
        ar.push_back(nel);
        mpr+=ma[a];
    }
    sort(arc.begin(), arc.end());
    for(int a=0; a<arc.size(); a++)
    {
        nel.va=arc[a], nel.ty=1;
        ar.push_back(nel);
        apr+=arc[a];
    }
    sort(ar.begin(), ar.end(), comp);
    for(int a=0; a<ar.size(); a++)
    {
        if(ar[a].ty==0) p_ma.push_back(a);
        else if(ar[a].ty==1) p_arc.push_back(a);
    }
    if(ar.size()>0)
    {
        dot=new el2[ar.size()*4];
        build(1, 0, ar.size()-1);
    }
    int myk=ma.size(), ayk=arc.size();
    for(int a=0; a<=both.size(); a++)
    {
        int so=max(k-a, 1ll*0);
        while(myk>so)
        {
            myk--;
            lg=p_ma[myk];
            ins(1, 0, ar.size()-1);
            mpr-=ma[myk];
        }
        while(ayk>so)
        {
            ayk--;
            lg=p_arc[ayk];
            ins(1, 0, ar.size()-1);
            apr-=arc[ayk];
        }
        if(myk==so and ayk==so)
        {
            lef=m-a-so*2;
            if(left>=0)
            {
                cu=bpr+mpr+apr;
                if(ar.size()>0) que(1, 0, ar.size()-1);
                if(lef==0) best=min(best, cu);
            }
        }
        if(a!=both.size()) bpr+=both[a];
    }
    if(best>1e17) cout<<-1;
    else cout<<best;
}