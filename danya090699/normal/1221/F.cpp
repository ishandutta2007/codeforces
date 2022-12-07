#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e6+10, inf=1e18;
pair <int, int> dot[sz*4];
int add[sz*4], p[sz];
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    dot[nu]=min(make_pair(dot[nu*2].first+add[nu*2], dot[nu*2].second), make_pair(dot[nu*2+1].first+add[nu*2+1], dot[nu*2+1].second));
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]={-p[l], l};
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int lg, rg, va;
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) add[nu]+=va;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
pair <int, int> que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return {dot[nu].first+add[nu], dot[nu].second};
    else if(l>rg or r<lg) return {inf, -1};
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        pair <int, int> re=min(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
        recalc(nu);
        return re;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <int, int> ma;
    int ar[n][3];
    for(int a=0; a<n; a++)
    {
        int l, r, w;
        scanf("%lld%lld%lld", &l, &r, &w);
        if(l>r) swap(l, r);
        ma[l]=0, ma[r]=0;
        ar[a][0]=l, ar[a][1]=r, ar[a][2]=w;
    }
    int m=0;
    for(auto it=ma.begin(); it!=ma.end(); it++) p[m]=(*it).first, (*it).second=m++;
    vector <pair <int, int> > sp[m];
    for(int a=0; a<n; a++)
    {
        sp[ma[ar[a][1]]].push_back({ma[ar[a][0]], ar[a][2]});
    }
    int su=0, an=0, anl=1e9+10, anr=anl;
    build(1, 0, m-1);
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<sp[a].size(); b++)
        {
            lg=sp[a][b].first+1, rg=m-1, va=sp[a][b].second;
            if(lg<=rg) cha(1, 0, m-1);
            su+=va;
        }
        lg=0, rg=a;
        pair <int, int> be=que(1, 0, m-1);

        if(su-p[a]-be.first>an)
        {
            an=su-p[a]-be.first, anl=p[be.second], anr=p[a];
        }
    }
    cout<<an<<" "<<anl<<" "<<anl<<" "<<anr<<" "<<anr;
}