#include <bits/stdc++.h>
using namespace std;
struct el
{
    int ke, pr, add=0, su=1;
    el *l=0, *r=0;
};
el *dek=0;
void push(el &tr)
{
    tr.ke+=tr.add;
    if(tr.l!=0) (*tr.l).add+=tr.add;
    if(tr.r!=0) (*tr.r).add+=tr.add;
    tr.add=0;
}
void recalc(el &tr)
{
    int lsu=0, rsu=0;
    if(tr.l!=0) lsu=(*tr.l).su;
    if(tr.r!=0) rsu=(*tr.r).su;
    tr.su=lsu+1+rsu;
}
void merge(el *lt, el *rt, el *&tr)
{
    if(lt==0) tr=rt;
    else if(rt==0) tr=lt;
    else
    {
        if((*lt).pr>(*rt).pr)
        {
            tr=lt, push(*tr);
            merge((*lt).r, rt, (*lt).r);
        }
        else
        {
            tr=rt, push(*tr);
            merge(lt, (*rt).l, (*rt).l);
        }
        recalc(*tr);
    }
}
void split(el *tr, el *&lt, el *&rt, int ke)
{
    lt=0, rt=0;
    if(tr!=0)
    {
        push(*tr);
        if((*tr).ke<=ke)
        {
            lt=tr, split((*tr).r, (*tr).r, rt, ke);
        }
        else
        {
            rt=tr, split((*tr).l, lt, (*tr).l, ke);
        }
        recalc(*tr);
    }
}
void split2(el *tr, el *&lt, el *&rt, int ke)
{
    lt=0, rt=0;
    if(tr!=0)
    {
        int lsi=0;
        if((*tr).l!=0) lsi=(*(*tr).l).su;
        push(*tr);
        if(ke>lsi)
        {
            lt=tr, split2((*tr).r, (*tr).r, rt, ke-lsi-1);
        }
        else
        {
            rt=tr, split2((*tr).l, lt, (*tr).l, ke);
        }
        recalc(*tr);
    }
}
int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    int n, ans=0;
    cin>>n;
    dek=new el;
    (*dek).ke=0, (*dek).pr=rand()*rand();
    for(int a=0; a<n; a++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        el *rt=0, *nel=new el, *rt2=0;
        split(dek, dek, rt, l-1);
        (*nel).ke=l, (*nel).pr=rand()*rand();
        merge(dek, nel, dek);
        split(rt, rt, rt2, r-1);
        if(rt!=0)
        {
            (*rt).add=1;
            merge(dek, rt, dek);
        }
        if(rt2==0) ans++;
        else
        {
            el *del=0;
            split2(rt2, del, rt2, 1);
            delete del;
            merge(dek, rt2, dek);
        }
    }
    cout<<ans;
}