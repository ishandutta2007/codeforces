#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

struct Treap;
using twoTreaps=array<Treap*,2>;

struct Treap
{
    ll val,sum;
    ull two;
    int sz,priority;
    twoTreaps kids;
    Treap(ll a){val=sum=two=a;sz=1;priority=gen();kids={nullptr,nullptr};}
};

int sz(Treap *me){return (me?me->sz:0);}
ll safe_sum(Treap *me){return (me?me->sum:0);}
ull safe_two(Treap *me){return (me?me->two:0);}

void recalc(Treap *me)
{
    if(!me) return;
    me->sum=me->two=me->sz=0;
    auto ch=[&](ll s,int len,ull t)
    {
        me->sz+=len;
        me->two=(me->two+ull(len)*me->sum+t);
        me->sum+=s;
    };
    auto &[l,r]=me->kids;
    if(l) ch(l->sum,l->sz,l->two);
    ch(me->val,1,me->val);
    if(r) ch(r->sum,r->sz,r->two);
}

twoTreaps splitval(Treap *me,ll lim)
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

twoTreaps splitcnt(Treap *me,int cnt)
{
    if(!me) return {nullptr,nullptr};
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

ll query_sum(Treap *me,int cnt)
{
    if(cnt==0) return 0;
    if(sz(me->kids[0])>=cnt) return query_sum(me->kids[0],cnt);
    else if(sz(me->kids[0])+1==cnt) return (safe_sum(me->kids[0])+me->val);
    else return (safe_sum(me->kids[0])+me->val+query_sum(me->kids[1],cnt-sz(me->kids[0])-1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<ll> s(n);
    ll sum=0;
    for(ll &x:s)
    {
        cin >> x;
        sum+=x;
    }
    ranges::sort(s);
    Treap *root=nullptr;
    for(ll x:s) root=tmerge(root,new Treap(x));
    auto mn=[&](int i)->ll{return query_sum(root,i);};
    auto mx=[&](int i)->ll{return sum-query_sum(root,n-i);};
    auto disjoint_sum=[&](int lim)->ull
    {
        auto [one,two]=splitcnt(root,lim);
        ull t=(ull(sum)*ull(lim+1)-safe_two(one));
        root=tmerge(one,two);
        auto [three,four]=splitcnt(root,n-(lim+1));
        t-=(safe_two(four)+ull(safe_sum(three))*ull(lim+1));
        root=tmerge(three,four);
        return t;
    };
    auto full_disjoint=[&]()->ull
    {
        return (ull(n+1)*ull(safe_sum(root))-2*safe_two(root));
    };
    auto go=[&]()
    {
        int l=0,r=(n-1)/2+1;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(mn(m+1)>=mx(m)) l=m;
            else r=m;
        }
        if(l<(n-1)/2) cout << 2*disjoint_sum(l)+(sum-2*mn(l+1)) << "\n";
        else cout << full_disjoint() << "\n";
    };
    go();
    while(q--)
    {
        int t;
        ll a;
        cin >> t >> a;
        if(t==1)
        {
            auto [one,two]=splitval(root,a);
            root=tmerge(tmerge(one,new Treap(a)),two);
            sum+=a;
            n++;
        }
        else
        {
            auto [one,two]=splitval(root,a-1);
            auto [_,three]=splitcnt(two,1);
            root=tmerge(one,three);
            sum-=a;
            n--;
        }
        go();
    }
    return 0;
}