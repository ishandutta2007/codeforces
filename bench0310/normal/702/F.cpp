#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rng(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}

struct Treap;
using twoTreaps=array<Treap*,2>;

struct Treap
{
    int id;
    int val;
    int res;
    int lazyres;
    int lazyval;
    int sz;
    int priority;
    twoTreaps kids;
    Treap(int a,int i){id=i;val=a;res=0;lazyval=lazyres=0;sz=1;priority=rng(1,(1<<30));kids[0]=kids[1]=nullptr;}
};

int sz(Treap *me){return (me?me->sz:0);}

void recalc(Treap *me)
{
    if(!me) return;
    me->sz=1;
    for(Treap *to:me->kids) if(to) me->sz+=to->sz;
}

void apply(Treap *me,int x,int y)
{
    if(!me) return;
    me->val-=x;
    me->res+=y;
    me->lazyval+=x;
    me->lazyres+=y;
}

void prop(Treap *me)
{
    if(!me) return;
    for(Treap *to:me->kids) apply(to,me->lazyval,me->lazyres);
    me->lazyval=me->lazyres=0;
}

twoTreaps splitval(Treap *me,int lim)
{
    if(!me) return {nullptr,nullptr};
    prop(me);
    if(me->val>lim)
    {
        twoTreaps res=splitval(me->kids[0],lim);
        me->kids[0]=res[1];
        recalc(me);
        return {res[0],me};
    }
    else
    {
        twoTreaps res=splitval(me->kids[1],lim);
        me->kids[1]=res[0];
        recalc(me);
        return {me,res[1]};
    }
}

twoTreaps splitcnt(Treap *me,int cnt)
{
    if(!me) return {nullptr,nullptr};
    prop(me);
    if(sz(me->kids[0])>=cnt)
    {
        twoTreaps res=splitcnt(me->kids[0],cnt);
        me->kids[0]=res[1];
        recalc(me);
        return {res[0],me};
    }
    else
    {
        twoTreaps res=splitcnt(me->kids[1],cnt-sz(me->kids[0])-1);
        me->kids[1]=res[0];
        recalc(me);
        return {me,res[1]};
    }
}

Treap* tmerge(Treap *a,Treap *b)
{
    if(!a) return b;
    if(!b) return a;
    prop(a);
    prop(b);
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

const int N=200005;
vector<int> opt(N,0);

void solve(Treap *me)
{
    if(!me) return;
    prop(me);
    opt[me->id]=me->res;
    for(Treap *to:me->kids) solve(to);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> v(n);
    for(int i=0;i<n;i++) for(int j=0;j<2;j++) cin >> v[i][j];
    sort(v.begin(),v.end(),[](const array<int,2> &a,const array<int,2> &b){return (a[1]>b[1]||(a[1]==b[1]&&a[0]<b[0]));});
    int k;
    cin >> k;
    vector<array<int,2>> a(k);
    for(int i=0;i<k;i++)
    {
        cin >> a[i][0];
        a[i][1]=i;
    }
    sort(a.begin(),a.end());
    Treap *root=new Treap(a[0][0],a[0][1]);
    for(int i=1;i<k;i++) root=tmerge(root,new Treap(a[i][0],a[i][1]));
    auto ins=[&](Treap *me,Treap *x)->Treap*
    {
        twoTreaps res=splitval(me,x->val);
        return tmerge(tmerge(res[0],x),res[1]);
    };
    for(int i=0;i<n;i++)
    {
        int c=v[i][0];
        auto [one,tmp]=splitval(root,c-1);
        apply(tmp,c,1);
        auto [two,three]=splitval(tmp,2*c);
        while(two)
        {
            twoTreaps res=splitcnt(two,1);
            one=ins(one,res[0]);
            two=res[1];
        }
        root=tmerge(one,three);
    }
    solve(root);
    for(int i=0;i<k;i++) cout << opt[i] << " \n"[i==k-1];
    return 0;
}