#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
struct dr
{
    int ch, zn;
    bool operator < (const dr x) const
    {
        return (1ll*ch*x.zn)<(1ll*x.ch*zn);
    }
};
bool comp(pair <dr, dr> a, pair <dr, dr> b)
{
    if(a.first<b.first or b.first<a.first) return a.first<b.first;
    else return b.second<a.second;
}
int dot[sz*4], lg, rg, p;
void ins(int nu, int l, int r)
{
    if(l==r) dot[nu]++;
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) ins(nu*2, l, mid);
        else ins(nu*2+1, mid+1, r);
        dot[nu]=dot[nu*2]+dot[nu*2+1];
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        return que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, w;
    cin>>n>>w;
    pair <dr, dr> ot[n];
    map <dr, int> ma;
    for(int a=0; a<n; a++)
    {
        int di, sp;
        scanf("%d%d", &di, &sp);
        ot[a].first.ch=abs(di), ot[a].first.zn=abs(sp)+w;
        ot[a].second.ch=abs(di), ot[a].second.zn=abs(sp)-w;
        if(sp<0) swap(ot[a].first, ot[a].second);
        ma[ot[a].first]=0;
        ma[ot[a].second]=0;
    }
    sort(ot, ot+n, comp);
    int m=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        (*it).second=m, m++;
    }
    long long an=0;
    for(int a=n-1; a>=0; a--)
    {
        lg=ma[ot[a].first], rg=ma[ot[a].second];
        lg=0, an+=que(1, 0, m-1);
        p=rg, ins(1, 0, m-1);
    }
    cout<<an;
}