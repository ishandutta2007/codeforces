#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rng(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}

struct Treap;
using twoTreaps=array<Treap*,2>;

struct Treap
{
    int val;
    int id;
    int mn;
    int priority;
    twoTreaps kids;
    Treap(int nval,int nid){val=nval;id=mn=nid;priority=rng(1,(1<<30));kids[0]=kids[1]=nullptr;}
};

void recalc(Treap *me)
{
    if(!me) return;
    me->mn=me->id;
    for(Treap *to:me->kids) if(to) me->mn=min(me->mn,to->mn);
}

twoTreaps split(Treap *me,int lim)
{
    if(!me) return {nullptr,nullptr};
    if(me->val>lim)
    {
        twoTreaps res=split(me->kids[0],lim);
        me->kids[0]=res[1];
        recalc(me);
        return {res[0],me};
    }
    else
    {
        twoTreaps res=split(me->kids[1],lim);
        me->kids[1]=res[0];
        recalc(me);
        return {me,res[1]};
    }
}

Treap* tmerge(Treap *a,Treap *b)
{
    if(!a) return b;
    if(!b) return a;
    if(a->priority<b->priority)
    {
        a->kids[1]=tmerge(a->kids[1],b);
        recalc(a);
        return a;
    }
    else
    {
        b->kids[0]=tmerge(a,b->kids[0]);
        recalc(b);
        return b;
    }
}

Treap *tinsert(Treap *me,int val,int id)
{
    auto [one,two]=split(me,val);
    return tmerge(tmerge(one,new Treap(val,id)),two);
}

const int N=50005;
const int inf=(1<<30);
vector<Treap*> tree(4*N,nullptr);

void update(int idx,int l,int r,int pos,int val,int id)
{
    tree[idx]=tinsert(tree[idx],val,id);
    if(l<r)
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val,id);
        else update(2*idx+1,m+1,r,pos,val,id);
    }
}

int query(int idx,int l,int r,int ql,int qr,int lim)
{
    if(ql>qr) return inf;
    if(l==ql&&r==qr)
    {
        auto [one,two]=split(tree[idx],lim);
        int tmp=(one?one->mn:inf);
        tree[idx]=tmerge(one,two);
        return tmp;
    }
    int m=(l+r)/2;
    return min(query(2*idx,l,m,ql,min(qr,m),lim),query(2*idx+1,m+1,r,max(ql,m+1),qr,lim));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> l(m+1,0);
    vector<int> r(m+1,0);
    vector<int> v[n+1];
    for(int i=1;i<=m;i++)
    {
        cin >> l[i] >> r[i];
        v[r[i]-l[i]+1].push_back(i);
    }
    vector<int> res(n+1,0);
    for(int i=n;i>=1;i--)
    {
        for(int id:v[i]) update(1,1,n,l[id],r[id],id);
        function<void(int,int)> go=[&](int a,int b)
        {
            int id=query(1,1,n,a,b,b);
            if(id!=inf)
            {
                res[i]+=(r[id]-l[id]+1);
                go(a,l[id]-1);
                go(r[id]+1,b);
            }
        };
        go(1,n);
    }
    for(int i=1;i<=n;i++) cout << res[i] << "\n";
    return 0;
}