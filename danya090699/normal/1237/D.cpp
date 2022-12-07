#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e9;
int dot[sz*4];
int va, p;
void cha(int nu, int l, int r)
{
    if(l==r) dot[nu]=min(dot[nu], va);
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        dot[nu]=min(dot[nu*2], dot[nu*2+1]);
    }
}
int lg, rg;
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return inf;
    else
    {
        int mid=(l+r)>>1;
        return min(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], an[n], ne[n];
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        ma[ar[a]]=0;
    }
    ma[0]=0;
    int m=0;
    for(auto it=ma.begin(); it!=ma.end(); it++) (*it).second=m++;
    for(int a=0; a<=m*4; a++) dot[a]=inf;
    for(int a=0; a<n; a++)
    {
        p=ma[ar[a]], va=a+n, cha(1, 0, m-1);
        //cout<<p<<" ";
    }
    for(int a=n-1; a>=0; a--)
    {
        auto it=ma.lower_bound((ar[a]+1)/2);
        it--;
        lg=0, rg=(*it).second;
        //cout<<rg<<" ";
        ne[a]=que(1, 0, m-1);
        //cout<<ne[a]<<" ";

        p=ma[ar[a]], va=a, cha(1, 0, m-1);
    }
    int mi=inf;
    for(int a=0; a<n; a++) mi=min(mi, n+ne[a]);
    for(int a=n-1; a>=0; a--)
    {
        mi=min(mi, ne[a]);
        if(mi<inf) an[a]=mi-a;
        else an[a]=-1;
    }
    for(int a=0; a<n; a++) printf("%d ", an[a]);
    //cout<<ne[1];
}