#include <bits/stdc++.h>
using namespace std;
const int sz=4e5+10;

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

    void print()
    {
        dfs(1, 0, n-1);
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

    void dfs(int nu, int l, int r)
    {
        cout<<nu<<": "<<tree[nu]<<"\n";
        if(l!=r)
        {
            int mid=(l+r)>>1;
            dfs(nu*2, l, mid), dfs(nu*2+1, mid+1, r);
        }
    }
};

int p[sz], p2[sz], h[sz], tin[sz], tout[sz], timer=0, sparse[20][sz];
vector <int> sv[sz];
void dfs(int v)
{
    tin[v]=timer, sparse[0][timer]=v, timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        h[ne]=h[v]+1, dfs(ne);
        sparse[0][timer]=v, timer++;
    }
    tout[v]=timer;
}
int get_min(int l, int r)
{
    int i=31-__builtin_clz(r-l+1);
    int lv=sparse[i][l], rv=sparse[i][r+1-(1<<i)];
    return (h[lv]<h[rv] ? lv : rv);
}
int lca(int u, int v)
{
    if(tin[u]>tin[v]) swap(u, v);
    return get_min(tin[u], tin[v]);
}
bool is_pr(int u, int v)
{
    return (tin[u]<=tin[v] and tout[u]>=tout[v]);
}

struct el
{
    bool ok;
    int ends[2];
};
ostream& operator << (ostream &out, const el &x)
{
    out<<x.ok;
    if(x.ok) out<<" "<<x.ends[0]<<" "<<x.ends[1];
    out<<"\n";
}
void init(el &ve, int l, int r)
{
    if(l==r) ve.ok=1, ve.ends[0]=p[l], ve.ends[1]=p[r];
}
void recalc(el &rt, el &le, el &ri, int q)
{
    rt.ok=0;
    if(le.ok and ri.ok)
    {
        int ve[4]={le.ends[0], le.ends[1], ri.ends[0], ri.ends[1]};

        for(int a=0; a<4; a++)
        {
            for(int b=a+1; b<4; b++)
            {
                int v=lca(ve[a], ve[b]), good=1;
                for(int c=0; c<4; c++)
                {
                    if(c!=a and c!=b)
                    {
                        if(is_pr(v, ve[c])==0 or (is_pr(ve[c], ve[a])==0 and is_pr(ve[c], ve[b])==0)) good=0;
                    }
                }
                if(good)
                {
                    rt.ok=1, rt.ends[0]=ve[a], rt.ends[1]=ve[b];
                    break;
                }
            }
            if(rt.ok) break;
        }
    }
}
void cha(el &ve, int x)
{
    ve.ends[0]=x, ve.ends[1]=x;
}
bool check(el &ve, int q, el *cu)
{
    el nel;
    recalc(nel, ve, *cu, 0);
    if(nel.ok)
    {
        *cu=nel;
        return false;
    }
    else return true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &p2[a]);
        p[p2[a]]=a;
    }
    for(int a=1; a<n; a++)
    {
        int pr;
        scanf("%d", &pr);
        pr--;
        sv[pr].push_back(a);
    }
    dfs(0);
    for(int i=1; (1<<i)<=n*2-1; i++)
    {
        for(int a=0; a+(1<<i)<=n*2-1; a++)
        {
            int lv=sparse[i-1][a], rv=sparse[i-1][a+(1<<(i-1))];
            sparse[i][a]=(h[lv]<h[rv] ? lv : rv);
        }
    }
    Segtree <el> tree(n, init, nullptr, recalc);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            int i, j;
            scanf("%d%d", &i, &j);
            i--, j--;
            swap(p2[i], p2[j]), swap(p[p2[i]], p[p2[j]]);
            tree.change(p2[i], cha, p[p2[i]]);
            tree.change(p2[j], cha, p[p2[j]]);
        }
        else
        {
            el cu;
            cu.ok=1, cu.ends[0]=p[0], cu.ends[1]=p[0];
            int re=tree.descent(0, n-1, check, &cu);
            if(re==-1) re=n;
            printf("%d\n", re);
        }
    }
}