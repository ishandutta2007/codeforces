#include <bits/stdc++.h>
#define int long long
#define iter set <int>::iterator
using namespace std;
const int sz=1e5+10;

template <class T>
class Segtree
{
public:

    int n;
    T *tree=nullptr;
    void (*push)(T&, T&, T&)=nullptr;
    void (*recalc)(T&, T&, T&, int)=nullptr;

    Segtree(int sz, void (*init)(T&, int, int), void (*pushf)(T&, T&, T&), void (*recalcf)(T&, T&, T&, int))
    {
        n=sz, tree=new T[sz*4];
        if(pushf) push=pushf;
        recalc=recalcf;
        build(1, 0, sz-1, init);
    }

    template <class T2>
    void change(int p, void (*chf)(T&, T2), T2 val)
    {
        cha(1, 0, n-1, p, chf, val);
    }

    template <class T2>
    void change(int l, int r, void (*chf)(T&, T2), T2 val)
    {
        cha(1, 0, n-1, l, r, chf, val);
    }

    template <class T2>
    T2 query(int p, T2 (*get)(T&, int))
    {
        return que(1, 0, n-1, p, get);
    }

    template <class T2>
    T2 query(int lg, int rg, T2 (*get)(T&, int), T2 (*sum)(T2, T2))
    {
        return que(1, 0, n-1, lg, rg, get, sum);
    }

    template <class T2>
    int descent(int lg, int rg, bool (*check)(T&, int, T2), T2 val)
    {
        return des(1, 0, n-1, lg, rg, check, val);
    }

private:

    void build(int nu, int l, int r, void (*init)(T &ve, int l, int r))
    {
        init(tree[nu], l, r);
        if(l!=r)
        {
            int mid=(l+r)>>1;
            build(nu*2, l, mid, init);
            build(nu*2+1, mid+1, r, init);
            recalc(tree[nu], tree[nu*2], tree[nu*2+1], r-l+1);
        }
    }

    template <class T2>
    void cha(int nu, int l, int r, int p, void (*chf)(T&, T2), T2 val)
    {
        if(l==r) chf(tree[nu], val);
        else
        {
            if(push) push(tree[nu], tree[nu*2], tree[nu*2+1]);
            int mid=(l+r)>>1;
            if(p<=mid) cha(nu*2, l, mid, p, chf, val);
            else cha(nu*2+1, mid+1, r, p, chf, val);
            recalc(tree[nu], tree[nu*2], tree[nu*2+1], r-l+1);
        }
    }

    template <class T2>
    void cha(int nu, int l, int r, int lg, int rg, void (*chf)(T&, T2), T2 val)
    {
        if(l>=lg and r<=rg) chf(tree[nu], val);
        else if(!(l>rg or r<lg))
        {
            if(push) push(tree[nu], tree[nu*2], tree[nu*2+1]);
            int mid=(l+r)>>1;
            cha(nu*2, l, mid, lg, rg, chf, val);
            cha(nu*2+1, mid+1, r, lg, rg, chf, val);
            recalc(tree[nu], tree[nu*2], tree[nu*2+1], r-l+1);
        }
    }

    template <class T2>
    T2 que(int nu, int l, int r, int p, T2 (*get)(T&, int))
    {
        if(l==r) return get(tree[nu], 1);
        else
        {
            if(push) push(tree[nu], tree[nu*2], tree[nu*2+1]);
            int mid=(l+r)>>1;
            T2 res;
            if(p<=mid) res=que(nu*2, l, mid, p, get);
            else res=que(nu*2+1, mid+1, r, p, get);
            recalc(tree[nu], tree[nu*2], tree[nu*2+1], r-l+1);
            return res;
        }
    }

    template <class T2>
    T2 que(int nu, int l, int r, int lg, int rg, T2 (*get)(T&, int), T2 (*sum)(T2, T2))
    {
        if(l>=lg and r<=rg) return get(tree[nu], r-l+1);
        else
        {
            if(push) push(tree[nu], tree[nu*2], tree[nu*2+1]);
            int mid=(l+r)>>1;
            T2 res;
            if(lg<=mid and rg>mid)
            {
                res=sum(que(nu*2, l, mid, lg, rg, get, sum), que(nu*2+1, mid+1, r, lg, rg, get, sum));
            }
            else if(lg<=mid) res=que(nu*2, l, mid, lg, rg, get, sum);
            else res=que(nu*2+1, mid+1, r, lg, rg, get, sum);
            recalc(tree[nu], tree[nu*2], tree[nu*2+1], r-l+1);
            return res;
        }
    }

    template <class T2>
    int des(int nu, int l, int r, int lg, int rg, bool (*check)(T&, int, T2), T2 val)
    {
        if(l>=lg and r<=rg)
        {
            if(check(tree[nu], r-l+1, val))
            {
                if(l==r) return l;
                else
                {
                    if(push) push(tree[nu], tree[nu*2], tree[nu*2+1]);
                    int mid=(l+r)>>1, res;
                    if(check(tree[nu*2], mid-l+1, val)) res=des(nu*2, l, mid, lg, rg, check, val);
                    else res=des(nu*2+1, mid+1, r, lg, rg, check, val);
                    recalc(tree[nu], tree[nu*2], tree[nu*2+1], r-l+1);
                    return res;
                }
            }
            else return -1;
        }
        else if(l>rg or r<lg) return -1;
        else
        {
            if(push) push(tree[nu], tree[nu*2], tree[nu*2+1]);
            int mid=(l+r)>>1, res;
            res=des(nu*2, l, mid, lg, rg, check, val);
            if(res==-1) res=des(nu*2+1, mid+1, r, lg, rg, check, val);
            recalc(tree[nu], tree[nu*2], tree[nu*2+1], r-l+1);
            return res;
        }
    }
};

int ar[sz];

struct el
{
    int su, add;
};
void init(el &ve, int l, int r)
{
    ve.add=0;
    if(l==r) ve.su=ar[l];
}
void push(el &rt, el &le, el &ri)
{
    le.add+=rt.add;
    ri.add+=rt.add;
    rt.add=0;
}
int vget(el &ve, int q)
{
    return ve.su+ve.add*q;
}
int sum(int l, int r)
{
    return l+r;
}
void recalc(el &rt, el &le, el &ri, int q)
{
    rt.su=vget(le, q/2+q%2)+vget(ri, q/2);
}
void cha(el &ve, int x)
{
    ve.add+=x;
}

main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <int> se;
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        se.insert(a);
    }
    int k[n-1];
    for(int a=0; a<n-1; a++) scanf("%lld", &k[a]);

    Segtree <el> tree(n, init, push, recalc);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        char ty[2];
        scanf("%s", ty);
        if(ty[0]=='s')
        {
            int l, r;
            scanf("%lld%lld", &l, &r);
            l--, r--;
            printf("%lld\n", tree.query(l, r, vget, sum));
        }
        else
        {
            int i, x;
            scanf("%lld%lld", &i, &x);
            i--;
            se.insert(i);
            iter lit=se.lower_bound(i), rit=lit;
            for(rit=se.lower_bound(i); (rit!=se.end() and x>0); rit++)
            {
                auto nit=rit;
                nit++;
                int l=(*rit), r=n-1;
                if(nit!=se.end()) r=(*nit)-1;
                tree.change(l, r, cha, x);
                if(r+1<n)
                {
                    int lva=tree.query(r, vget), rva=tree.query(r+1, vget);
                    x=k[r]-(rva-lva);
                }
            }
            se.erase(lit, rit);
            se.insert(i);
        }
    }
}