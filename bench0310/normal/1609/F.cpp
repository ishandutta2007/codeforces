#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

struct Treap;
using twoTreaps=array<Treap*,2>;

struct Treap
{
    int l,r;
    int sum;
    twoTreaps kids;
    int priority;
    Treap(int tl,int tr){l=tl;r=tr;sum=r-l+1;kids={nullptr,nullptr};priority=gen();}
};

void trecalc(Treap *me)
{
    if(!me) return;
    me->sum=(me->r-me->l+1);
    for(Treap *to:me->kids)if(to){me->sum+=to->sum;}
}

twoTreaps tsplit(Treap *me,int lim) //<=lim | >lim
{
    if(!me) return {nullptr,nullptr};
    if(me->l<=lim)
    {
        twoTreaps res=tsplit(me->kids[1],lim);
        me->kids[1]=res[0];
        trecalc(me);
        return {me,res[1]};
    }
    else
    {
        twoTreaps res=tsplit(me->kids[0],lim);
        me->kids[0]=res[1];
        trecalc(me);
        return {res[0],me};
    }
}

Treap* tmerge(Treap *a,Treap *b)
{
    if(!a) return b;
    if(!b) return a;
    if(a->priority<b->priority)
    {
        a->kids[1]=tmerge(a->kids[1],b);
        trecalc(a);
        return a;
    }
    else
    {
        b->kids[0]=tmerge(a,b->kids[0]);
        trecalc(b);
        return b;
    }
}

Treap* get_right(Treap *me)
{
    if(!me->kids[1]) return me;
    else return get_right(me->kids[1]);
}

//void print(Treap *me)
//{
//    if(!me) return;
//    print(me->kids[0]);
//    cout << "[" << me->l << "," << me->r << "] ";
//    print(me->kids[1]);
//}
//
//void pr(Treap *me)
//{
//    cout << "treap: ";
//    print(me);
//    cout << endl;
//}

struct obj
{
    vector<Treap*> v;
    obj(){v.assign(60,nullptr);}
    int cntone(int a,int lim)
    {
        auto [one,two]=tsplit(v[a],lim);
        int c=(one?one->sum:0);
        if(one)
        {
            Treap *tmp=get_right(one);
            int r=tmp->r;
            if(lim<r) c-=(r-lim);
        }
        v[a]=tmerge(one,two);
        return c;
    }
    int cnt(int a,int l,int r){return cntone(a,r)-cntone(a,l-1);}
    void rm(int a,int lim)
    {
        auto [one,two]=tsplit(v[a],lim);
        v[a]=two;
    }
    void add(int a,int l,int r)
    {
        v[a]=tmerge(new Treap(l,r),v[a]);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    vector<int> pcnt(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        pcnt[i]=popcount(ull(a[i]));
    }
    vector<obj> v(2);
    stack<array<ll,2>> mn,mx;
    const ll inf=(1ll<<60);
    mn.push({-inf,n+1});
    mx.push({inf,n+1});
    ll res=0;
    int now=0;
    for(int i=n;i>=1;i--)
    {
        ll b=a[i];
        now++;
        mn.push({b,i});
        mx.push({b,i});
        v[0].add(pcnt[i],i,i);
        v[1].add(pcnt[i],i,i);
        //add one
        while(b<=mn.top()[0])
        {
            auto [c,l]=mn.top();
            mn.pop();
            int r=mn.top()[1]-1;
            v[0].rm(pcnt[l],r);
            now-=v[1].cnt(pcnt[l],l,r);
        }
        int tr=mn.top()[1]-1;
        mn.push({b,i});
        now+=v[1].cnt(pcnt[i],i,tr);
        v[0].add(pcnt[i],i,tr);
        //add two
        while(b>=mx.top()[0])
        {
            auto [c,l]=mx.top();
            mx.pop();
            int r=mx.top()[1]-1;
            v[1].rm(pcnt[l],r);
            now-=v[0].cnt(pcnt[l],l,r);
        }
        tr=mx.top()[1]-1;
        mx.push({b,i});
        now+=v[0].cnt(pcnt[i],i,tr);
        v[1].add(pcnt[i],i,tr);
        res+=now;
//        cout << "after " << i << endl;
//        cout << "mx: ";
//        for(int i=0;i<3;i++)
//        {
//            cout << i << " ";
//            pr(v[1].v[i]);
//        }
    }
    cout << res << "\n";
    return 0;
}