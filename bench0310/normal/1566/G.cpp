#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

struct Treap;
using twoTreaps=array<Treap*,2>;

struct Treap
{
    int val;
    int sz=1;
    int priority=gen();
    twoTreaps kids={nullptr,nullptr};
    Treap(int nval){val=nval;}
};

int sz(Treap *me){return (me?me->sz:0);}

void recalc(Treap *me)
{
    if(!me) return;
    me->sz=1;
    for(Treap *to:me->kids) me->sz+=sz(to);
}

twoTreaps tsplit(Treap *me,int lim)
{
    if(!me) return {nullptr,nullptr};
    if(me->val>lim)
    {
        twoTreaps res=tsplit(me->kids[0],lim);
        me->kids[0]=res[1];
        recalc(me);
        return {res[0],me};
    }
    else
    {
        twoTreaps res=tsplit(me->kids[1],lim);
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

int kth(Treap *me,int k)
{
    if(sz(me->kids[0])>=k) return kth(me->kids[0],k);
    else if(sz(me->kids[0])+1==k) return me->val;
    else return kth(me->kids[1],k-sz(me->kids[0])-1);
}

Treap* tinsert(Treap *me,int val)
{
    auto [one,two]=tsplit(me,val);
    return tmerge(tmerge(one,new Treap(val)),two);
}

Treap* terase(Treap *me,int val)
{
    auto [tmp,two]=tsplit(me,val);
    Treap *one=tsplit(tmp,val-1)[0];
    return tmerge(one,two);
}

int cnt(Treap *me,int lim)
{
    if(!me) return 0;
    if(me->val>lim) return cnt(me->kids[0],lim);
    else return sz(me->kids[0])+1+cnt(me->kids[1],lim);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,4>> queries(m);
    vector<array<int,2>> z;
    vector<ll> h;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        queries[i]={a,b,c,1};
        z.push_back({c,i});
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        int t,a,b;
        cin >> t >> a >> b;
        int c=0;
        if(t==1)
        {
            cin >> c;
            z.push_back({c,m+i});
        }
        queries.push_back({a,b,c,t});
    }
    sort(z.begin(),z.end());
    for(int i=0;i<(int)z.size();i++)
    {
        queries[z[i][1]][2]=i;
        h.push_back(z[i][0]);
    }
    Treap *active=nullptr;
    vector<Treap*> edges(n+1,nullptr);
    auto get_e=[&](int c)->array<int,2>
    {
        int p=z[c][1];
        return {queries[p][0],queries[p][1]};
    };
    auto disjoint=[&](int c,int d)->bool
    {
        auto [ca,cb]=get_e(c);
        auto [da,db]=get_e(d);
        return (ca!=da&&ca!=db&&cb!=da&&cb!=db);
    };
    auto intersection=[&](int c,int d)->int
    {
        auto [ca,cb]=get_e(c);
        auto [da,db]=get_e(d);
        for(int x:{ca,cb}) for(int y:{da,db}) if(x==y) return x;
        return -1;
    };
    auto chosen=[&](int c)->ll
    {
        auto [a,b]=get_e(c);
        if(sz(edges[a])+sz(edges[b])-1==sz(active)) return (1ll<<60);
        int l=0,r=sz(active);
        while(l<r-1)
        {
            int mid=(l+r)/2;
            int t=kth(active,mid);
            if(cnt(edges[a],t)+cnt(edges[b],t)-(c<=t)==mid) l=mid;
            else r=mid;
        }
        return h[c]+h[kth(active,l+1)];
    };
    map<array<int,2>,int> tmp;
    for(int o=0;o<m+q;o++)
    {
        auto [a,b,c,t]=queries[o];
        if(t==0) c=tmp[{min(a,b),max(a,b)}];
        if(t==0)
        {
            edges[a]=terase(edges[a],c);
            edges[b]=terase(edges[b],c);
            active=terase(active,c);
        }
        else
        {
            edges[a]=tinsert(edges[a],c);
            edges[b]=tinsert(edges[b],c);
            active=tinsert(active,c);
            tmp[{min(a,b),max(a,b)}]=c;
        }
        if(o>=m-1)
        {
            vector<int> e(5,-1);
            for(int i=1;i<=4;i++) e[i]=kth(active,i);
            cout << [&]()->ll
            {
                if(disjoint(e[1],e[2])) return (h[e[1]]+h[e[2]]);
                if(disjoint(e[1],e[3])) return (h[e[1]]+h[e[3]]);
                ll four=(1ll<<60);
                for(int i=1;i<=3;i++) if(disjoint(e[i],e[4])) four=min(four,h[e[i]]+h[e[4]]);
                if(intersection(e[1],e[2])!=intersection(e[1],e[3]))
                {
                    if(intersection(e[2],e[3])==-1) return min(h[e[2]]+h[e[3]],chosen(e[1]));
                    else return min({four,chosen(e[1]),chosen(e[2])});
                }
                return min({h[e[1]]+h[e[2]]+h[e[3]],four,chosen(e[1]),chosen(e[2])});
            }() << "\n";
        }
    }
    return 0;
}