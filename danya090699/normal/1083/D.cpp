#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7, sz=1e5+10;
int nl[sz], nr[sz], ar[sz];

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

struct el
{
    int su, add;
};
void init(el &ve, int l, int r)
{
    ve.add=0, ve.su=0;
}
void push(el &rt, el &le, el &ri)
{
    le.add+=rt.add;
    ri.add+=rt.add;
    rt.add=0;
}
void recalc(el &rt, el &le, el &ri, int q)
{
    rt.su=le.su+le.add*((q+1)/2)+ri.su+ri.add*(q/2);
}
int getv(el &ve, int q)
{
    return ve.su+ve.add*q;
}
int sum(int l, int r)
{
    return l+r;
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
    map <int, vector <int> > ma;
    for(int a=0; a<n; a++)
    {
        nr[a]=n, nl[a]=-1;
        int x;
        scanf("%lld", &x);
        if(ma[x].size())
        {
            nr[ma[x].back()]=a, nl[a]=ma[x].back();
        }
        ma[x].push_back(a);
        ar[a]=x;
    }
    Segtree <el> ltree(n, init, push, recalc), rtree(n, init, push, recalc);
    deque <int> l, r;
    l.push_back(-1), r.push_back(-1);
    int gr=-1, su=0, an=0;
    for(int a=0; a<n; a++)
    {
        if(nl[a]>l.front())
        {
            int b=l.front()+1;
            l.pop_front(), r.pop_front();
            for(b; b<=nl[a]; b++)
            {
                su-=(b-nl[l.front()]-1)*(nr[r.front()]-a);
                if(l.front()==b) l.pop_front();
                if(r.front()==b) r.pop_front();
            }
            l.push_front(nl[a]), r.push_front(nl[a]);
        }
        if(a-1>l.front())
        {
            su-=ltree.query(l.front()+1, a-1, getv, sum);
            rtree.change(l.front()+1, a-1, cha, -1ll);
        }
        while(l.size()>1 and nl[l.back()]<nl[a])
        {
            int p=l.back();
            l.pop_back();
            su-=rtree.query(l.back()+1, p, getv, sum)*(nl[a]-nl[p]);
            ltree.change(l.back()+1, p, cha, -(nl[a]-nl[p]));
        }
        l.push_back(a);
        while(r.size()>1 and nr[r.back()]>nr[a])
        {
            int p=r.back();
            r.pop_back();
            su-=ltree.query(r.back()+1, p, getv, sum)*(nr[p]-nr[a]);
            rtree.change(r.back()+1, p, cha, -(nr[p]-nr[a]));
        }
        r.push_back(a);
        ltree.change(a, cha, a-nl[a]-1);
        rtree.change(a, cha, nr[a]-a-1);
        su+=(a-nl[a]-1)*(nr[a]-a-1);
        an=(an+su)%mod;
    }
    cout<<an;
}