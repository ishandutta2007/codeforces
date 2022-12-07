#include <bits/stdc++.h>
#define int long long
#define iter map <int, int>::iterator
using namespace std;
const int sz=1e5+10, inf=2e9;
int val[sz];

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
    int mi, add;
};

void init(el &ve, int l, int r)
{
    ve.mi=0, ve.add=0;
}
void push(el &rt, el &le, el &ri)
{
    le.add+=rt.add;
    ri.add+=rt.add;
    rt.add=0;
}
int getv(el &ve, int q)
{
    return ve.mi+ve.add;
}
void recalc(el &rt, el &le, el &ri, int q)
{
    rt.mi=min(getv(le, 0), getv(ri, 0));
}
void cha(el &ve, int va)
{
    ve.add+=va;
}
bool check(el &ve, int q, int va)
{
    return ve.mi+ve.add<=va;
}

main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    map <int, int> ma;
    int zap[q][4];
    for(int a=0; a<q; a++)
    {
        scanf("%lld", &zap[a][0]);
        if(zap[a][0]==1)
        {
            scanf("%lld%lld", &zap[a][1], &zap[a][2]);
            ma[zap[a][1]]=0;
        }
        else if(zap[a][0]==2) scanf("%lld", &zap[a][1]);
        else scanf("%lld%lld%lld", &zap[a][1], &zap[a][2], &zap[a][3]);
    }
    ma[0]=0, ma[inf]=0;
    int n=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        val[n]=(*it).first;
        (*it).second=n, n++;
    }

    Segtree <el> tree(n, init, push, recalc);

    map <int, int> se;
    se[0]=0, se[inf]=0;
    for(int a=0; a<q; a++)
    {
        int ty=zap[a][0];
        if(ty==1)
        {
            int t=zap[a][1], s=zap[a][2];
            iter it=se.lower_bound(t);
            int nt=(*it).first;
            it--;
            int pt=(*it).first, ps=(*it).second;

            tree.change(ma[t], ma[nt]-1, cha, (t-pt)*ps);

            tree.change(ma[nt], n-1, cha, (nt-t)*(s-ps));

            se[t]=s;
        }
        else if(ty==2)
        {
            int t=zap[a][1];
            iter it=se.find(t);
            int s=(*it).second;
            it++;
            int nt=(*it).first;
            it--, it--;
            int pt=(*it).first, ps=(*it).second;

            tree.change(ma[t], ma[nt]-1, cha, -(t-pt)*ps);

            tree.change(ma[nt], n-1, cha, -(nt-t)*(s-ps));

            se.erase(t);
        }
        else
        {
            int l=zap[a][1], r=zap[a][2], v=zap[a][3];
            if(v)
            {
                iter itl=se.lower_bound(l), itr=se.upper_bound(r);
                if(itl!=itr)
                {
                    int lp=(*itl).first, rp=(*itr).first;

                    int x=tree.query(ma[lp], getv);

                    int re=tree.descent(ma[lp], ma[rp]-1, check, x-v);

                    if(re==-1) re=ma[rp]-1;
                    else re--;

                    iter it=se.upper_bound(val[re]);
                    it--;
                    int t=(*it).first, s=(*it).second;

                    int pva=tree.query(re, getv);

                    if(pva+(r-t)*s<=x-v)
                    {
                        double an=t+(pva-(x-v))/(-1.0*s);
                        printf("%.10f\n", an);
                    }
                    else printf("-1\n");
                }
                else printf("-1\n");
            }
            else printf("%lld\n", l);
        }
    }
}