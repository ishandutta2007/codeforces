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
    ll sum;
    ll res;
    int sz;
    int priority;
    twoTreaps kids;
    Treap(int a){val=a;sum=a;res=0;sz=1;priority=rng(1,(1<<30));kids[0]=kids[1]=nullptr;}
};

int sz(Treap *me){return (me?me->sz:0);}

void recalc(Treap *me)
{
    if(!me) return;
    me->sz=1;
    for(Treap *to:me->kids) if(to) me->sz+=to->sz;
    me->sum=me->val;
    for(Treap *to:me->kids) if(to) me->sum+=to->sum;
    me->res=0;
    for(Treap *to:me->kids) if(to) me->res+=to->res;
    if(me->kids[0]) me->res+=((ll)sz(me->kids[0])*me->val-me->kids[0]->sum);
    if(me->kids[1]) me->res+=(me->kids[1]->sum-(ll)sz(me->kids[1])*me->val);
    if(me->kids[0]&&me->kids[1]) me->res+=((ll)sz(me->kids[0])*me->kids[1]->sum-(ll)sz(me->kids[1])*me->kids[0]->sum);
}

twoTreaps splitval(Treap *me,int lim)
{
    if(!me) return {nullptr,nullptr};
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

Treap* tinsert(Treap *me,Treap *a)
{
    twoTreaps res=splitval(me,a->val);
    return tmerge(tmerge(res[0],a),res[1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n+1,0);
    for(int i=1;i<=n;i++) cin >> x[i];
    Treap *root=new Treap(x[1]);
    for(int i=2;i<=n;i++) root=tinsert(root,new Treap(x[i]));
    int m;
    cin >> m;
    while(m--)
    {
        int t,l,r;
        cin >> t >> l >> r;
        if(t==1)
        {
            auto [one,tmp]=splitval(root,x[l]-1);
            auto [two,three]=splitval(tmp,x[l]);
            root=tmerge(one,three);
            x[l]+=r;
            two->val+=r;
            recalc(two);
            root=tinsert(root,two);
        }
        else if(t==2)
        {
            auto [one,tmp]=splitval(root,l-1);
            auto [two,three]=splitval(tmp,r);
            cout << (two?two->res:0) << "\n";
            root=tmerge(tmerge(one,two),three);
        }
    }
    return 0;
}