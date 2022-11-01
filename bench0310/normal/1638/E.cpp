#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000005;
vector<ll> tree(4*N,0);

void update(int idx,int l,int r,int pos,ll x)
{
    if(l==r) tree[idx]+=x;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,x);
        else update(2*idx+1,m+1,r,pos,x);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    auto upd=[&](int l,int r,ll x)
    {
        update(1,1,n,l,x);
        if(r+1<=n) update(1,1,n,r+1,-x);
    };
    auto qry=[&](int p)->ll{return query(1,1,n,1,p);};
    vector<ll> col(n+1,0);
    set<array<ll,4>> s; //l,r,c,prv
    s.insert({1,n,1,0});
    auto time_travel=[&](int l,int r,auto it)->set<array<ll,4>>::iterator
    {
        int c=(*it)[2];
        ll t=(*it)[3];
        s.erase(it);
        upd(l,r,col[c]-t);
        auto [nit,_]=s.insert({l,r,c,col[c]});
        return nit;
    };
    auto one=[&](int p,bool rm=0)->tuple<int,int,set<array<ll,4>>::iterator>
    {
        auto it=s.lower_bound({p+1,0,0,0});
        it--;
        int l=(*it)[0],r=(*it)[1];
        it=time_travel(l,r,it);
        if(rm) s.erase(it);
        return {l,r,it};
    };
    auto split=[&](int l,int r,int p,auto it) //[l,p-1]&[p,r]
    {
        int c=(*it)[2];
        ll t=(*it)[3];
        s.erase(it);
        s.insert({l,p-1,c,t});
        s.insert({p,r,c,t});
    };
    auto color_range=[&](int l,int r,int c)
    {
        auto [xl,xr,xit]=one(l);
        if(xl<l) split(xl,xr,l,xit);
        auto [yl,yr,yit]=one(r);
        if(r<yr) split(yl,yr,r+1,yit);
        int p=l;
        while(p<=r)
        {
            auto [tl,tr,_]=one(p,1);
            p=tr+1;
        }
        s.insert({l,r,c,col[c]});
    };
    while(q--)
    {
        string t;
        cin >> t;
        if(t=="Color")
        {
            int l,r,c;
            cin >> l >> r >> c;
            color_range(l,r,c);
        }
        if(t=="Add")
        {
            int c,x;
            cin >> c >> x;
            col[c]+=x;
        }
        if(t=="Query")
        {
            int p;
            cin >> p;
            one(p);
            cout << qry(p) << "\n";
        }
    }
    return 0;
}