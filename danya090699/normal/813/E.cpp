#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int n, k, q, last=0, ar[sz], inf=1e9, lg, rg;
vector <int> ch[sz];
struct el
{
    int va;
    el *l=0, *r=0;
};
el **dot;
bool comp(el a, el b){return (a.va<b.va);}
void merge(el *l, el *len, el *r, el *ren, el *re)
{
    el *st=re;
    while(l!=len or r!=ren)
    {
        (*re).va=min((*l).va, (*r).va);
        if(re!=st)
        {
            if((*(re-1)).va==(*re).va)
            {
                (*re).l=(*(re-1)).l, (*re).r=(*(re-1)).r;
            }
        }
        if((*re).l==0)
        {
            (*re).l=l, (*re).r=r;
        }
        if((*l).va<(*r).va) l++;
        else r++;
        re++;
    }
    (*re).l=l, (*re).r=r;
}
void build(int nu, int l, int r)
{
    dot[nu]=new el[r-l+2];
    dot[nu][r-l+1].va=inf;
    if(l==r) dot[nu][0].va=ar[l];
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        merge(dot[nu*2], dot[nu*2]+(mid-l+1), dot[nu*2+1], dot[nu*2+1]+(r-(mid+1)+1), dot[nu]);
    }
}
int que(int nu, int l, int r, el *yk)
{
    if(l>=lg and r<=rg) return(yk-dot[nu]);
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)/2;
        return que(nu*2, l, mid, (*yk).l)+que(nu*2+1, mid+1, r, (*yk).r);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        ch[x].push_back(a);
    }
    for(int a=0; a<sz; a++)
    {
        for(int b=0; b<ch[a].size(); b++)
        {
            if(b-k>=0) ar[ch[a][b]]=ch[a][b-k];
            else ar[ch[a][b]]=-1;
        }
    }
    dot=new el*[n*4];
    build(1, 0, n-1);
    cin>>q;
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &lg, &rg);
        lg=(lg+last)%n, rg=(rg+last)%n;
        if(lg>rg) swap(lg, rg);
        el nel;
        nel.va=lg;
        last=que(1, 0, n-1, lower_bound(dot[1], dot[1]+n+1, nel, comp));
        printf("%d\n", last);
    }
}