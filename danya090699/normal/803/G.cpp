#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int n, k, q, ar[sz*2], sp[18][sz], sm=2e9, st2[sz*2], lg, rg, add;
struct el
{
    int mi, add=-1;
    el *l=0, *r=0;
};
el *dot;
el* cr(int l, int r)
{
    int le=r-l+1;
    el *re=new el;
    if(le>=n) (*re).mi=sm;
    else
    {
        l=l%n;
        int lev=st2[le];
        (*re).mi=min(sp[lev][l], sp[lev][l+(le-(1<<lev))]);
    }
    return re;
}
void push(el &cu)
{
    if(cu.add!=-1)
    {
        (*cu.l).add=cu.add;
        (*cu.r).add=cu.add;
        cu.add=-1;
    }
}
void recalc(el &cu)
{
    int lva=(*cu.l).mi, rva=(*cu.r).mi;
    if((*cu.l).add!=-1) lva=(*cu.l).add;
    if((*cu.r).add!=-1) rva=(*cu.r).add;
    cu.mi=min(lva, rva);
}
void cha(el &cu, int l, int r)
{
    if(l>=lg and r<=rg) cu.add=add;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)/2;
        if(cu.l==0) cu.l=cr(l, mid);
        if(cu.r==0) cu.r=cr(mid+1, r);
        push(cu);
        cha(*cu.l, l, mid);
        cha(*cu.r, mid+1, r);
        recalc(cu);
    }
}
int que(el &cu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        if(cu.add!=-1) return cu.add;
        else return cu.mi;
    }
    else if(l>rg or r<lg) return 2e9;
    else
    {
        int mid=(l+r)/2;
        if(cu.l==0) cu.l=cr(l, mid);
        if(cu.r==0) cu.r=cr(mid+1, r);
        push(cu);
        int an=min(que(*cu.l, l, mid), que(*cu.r, mid+1, r));
        recalc(cu);
        return an;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        ar[a+n]=ar[a];
        sm=min(sm, ar[a]);
    }
    for(int a=0; a<18; a++) for(int b=(1<<a); b<min(sz, (1<<(a+1))); b++) st2[b]=a;
    for(int a=0; a<n*2; a++) sp[0][a]=ar[a];
    for(int a=1; (1<<a)<=n*2; a++)
    {
        for(int b=0; b<=n*2-(1<<a); b++)
        {
            sp[a][b]=min(sp[a-1][b], sp[a-1][b+(1<<(a-1))]);
        }
    }
    dot=cr(0, n*k-1);
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%d%d%d", &ty, &lg, &rg);
        lg--, rg--;
        if(ty==1)
        {
            scanf("%d", &add);
            cha(*dot, 0, n*k-1);
        }
        else cout<<que(*dot, 0, n*k-1)<<"\n";
    }
}