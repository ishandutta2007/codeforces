#include <bits/stdc++.h>
using namespace std;
int n, *sv, *sv2, *ar, *ar2, *ar3, *dot, yk, lg, inf=1e9, va;
bool *us;
vector <int> tout;
void recalc(int nu)
{
    dot[nu]=min(dot[nu*2], dot[nu*2+1]);
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=ar2[l];
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void cha(int nu, int l, int r)
{
    if(l==r) dot[nu]=inf;
    else
    {
        int mid=(l+r)/2;
        if(lg<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int que(int nu, int l, int r)
{
    if(l==r)
    {
        if(dot[nu]<va) return l;
        else return l+1;
    }
    else
    {
        int mid=(l+r)/2;
        if(dot[nu*2]<va) return que(nu*2, l, mid);
        else return que(nu*2+1, mid+1, r);
    }
}
void dfs(int v, int pr)
{
    us[v]=1;
    lg=ar3[v];
    cha(1, 0, n-1);
    ar2[lg]=inf;
    while(1==1)
    {
        va=sv[v];
        if(va==-2) va=n;
        int cu=que(1, 0, n-1);
        if(cu<=ar[v]) dfs(ar2[cu], v);
        else break;
    }
    if(sv2[v]!=-1) if(us[sv2[v]]==0) dfs(sv2[v], v);
    tout.push_back(v);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    yk=n-1;
    sv=new int[n], sv2=new int[n], ar=new int[n], ar2=new int[n], ar3=new int[n], dot=new int[n*4], us=new bool[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &sv[a]);
        sv[a]--;
        sv2[a]=-1, us[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        ar[a]=yk;
        if(sv[a]!=-2)
        {
            sv2[sv[a]]=a;
            ar2[yk]=sv[a];
            us[sv[a]]=1, yk--;
        }
    }
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            ar2[yk]=a, yk--;
        }
        us[a]=0;
    }
    for(int a=0; a<n; a++) ar3[ar2[a]]=a;
    build(1, 0, n-1);
    for(int a=0; a<n; a++) if(us[a]==0) dfs(a, -1);
    int an[n];
    for(int a=0; a<n; a++) an[tout[a]]=a+1;
    for(int a=0; a<n; a++) printf("%d ", an[a]);
}