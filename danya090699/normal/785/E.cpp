#include <bits/stdc++.h>
using namespace std;
struct el
{
    int va, pri, su=1;
    el *l=0, *r=0;
};
int n, q, lq, rq, nu1, nu2, lg, rg, p1, p2;
el **dot;
void copy(el &a, el &b)
{
    a.va=b.va, a.pri=b.pri, a.su=b.su;
    if(b.l!=0)
    {
        a.l=new el;
        copy(*a.l, *b.l);
    }
    if(b.r!=0)
    {
        a.r=new el;
        copy(*a.r, *b.r);
    }
}
void recalc(el &tr)
{
    tr.su=1;
    if(tr.l!=0) tr.su+=(*tr.l).su;
    if(tr.r!=0) tr.su+=(*tr.r).su;
}
void merge(el *lt, el *rt, el *&to)
{
    if(lt==0) to=rt;
    else if(rt==0) to=lt;
    else
    {
        if((*lt).pri>(*rt).pri)
        {
            to=lt, merge((*lt).r, rt, (*lt).r);
        }
        else
        {
            to=rt, merge(lt, (*rt).l, (*rt).l);
        }
        recalc(*to);
    }
}
void split(el *tr, el *&lt, el *&rt, int ke)
{
    if(tr!=0)
    {
        lt=0, rt=0;
        if((*tr).va<=ke)
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
void del(el *&tr, int va)
{
    el *de=0, *rt=0;
    split(tr, tr, rt, va-1);
    split(rt, de, rt, va);
    delete de;
    merge(tr, rt, tr);
}
void ins(el *&tr, int va)
{
    el *nel=new el, *rt=0;
    (*nel).va=va, (*nel).pri=rand()*rand();
    split(tr, tr, rt, va);
    merge(tr, nel, tr);
    merge(tr, rt, tr);
}
void que2(el *&tr, int va)
{
    el *rt=0;
    split(tr, tr, rt, va);
    if(tr!=0) lq+=(*tr).su;
    if(rt!=0) rq+=(*rt).su;
    merge(tr, rt, tr);
}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        dot[nu]=new el;
        (*dot[nu]).va=l;
        (*dot[nu]).pri=rand()*rand();
    }
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[nu]=new el;
        copy(*dot[nu], *dot[nu*2]);
        el *rt=new el;
        copy(*rt, *dot[nu*2+1]);
        merge(dot[nu], rt, dot[nu]);
    }
}
void cha(int nu, int l, int r)
{
    if(!(l<=p1 and r>=p2))
    {
        ins(dot[nu], nu1);
        del(dot[nu], nu2);
    }
    if(l!=r)
    {
        int mid=(l+r)/2;
        if(lg<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
    }
}
void que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) que2(dot[nu], nu1);
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)/2;
        que(nu*2, l, mid);
        que(nu*2+1, mid+1, r);
    }
}
int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    long long ans=0;
    dot=new el*[n*4];
    build(1, 0, n-1);
    int ar[n];
    for(int a=0; a<n; a++) ar[a]=a;
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &p1, &p2);
        p1--, p2--;
        if(p1>p2) swap(p1, p2);
        nu1=ar[p1], nu2=ar[p2];
        if(nu1<nu2) ans++;
        if(nu1>nu2) ans--;
        lg=p1+1, rg=p2-1;
        if(lg<=rg)
        {
            lq=0, rq=0;
            que(1, 0, n-1);
            ans-=lq, ans+=rq;
            lq=0, rq=0, nu1=nu2;
            que(1, 0, n-1);
            ans+=lq, ans-=rq;
        }
        lg=p1, nu1=ar[p2], nu2=ar[p1];
        cha(1, 0, n-1);
        lg=p2, nu1=ar[p1], nu2=ar[p2];
        cha(1, 0, n-1);
        swap(ar[p1], ar[p2]);
        printf("%lld\n", ans);
    }
}