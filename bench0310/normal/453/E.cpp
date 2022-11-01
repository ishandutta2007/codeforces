#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node
{
    ll m,b;
    node *l,*r;
    node(ll x,ll y){m=x;b=y;l=r=nullptr;}
    node(node *one,node *two){l=one;r=two;m=(one->m+two->m);b=(one->b+two->b);}
};

node* build(int l,int r)
{
    if(l==r) return new node(ll(0),ll(0));
    int m=(l+r)/2;
    return new node(build(l,m),build(m+1,r));
}

node* update(node *now,int l,int r,int pos,ll x,ll y)
{
    if(l==r) return new node(now->m+x,now->b+y);
    int m=(l+r)/2;
    if(pos<=m) return new node(update(now->l,l,m,pos,x,y),now->r);
    else return new node(now->l,update(now->r,m+1,r,pos,x,y));
}

array<ll,2> query(node *now,int l,int r,int ql,int qr)
{
    if(ql>qr) return {0,0};
    if(l==ql&&r==qr) return {now->m,now->b};
    int m=(l+r)/2;
    auto one=query(now->l,l,m,ql,min(qr,m));
    auto two=query(now->r,m+1,r,max(ql,m+1),qr);
    return {one[0]+two[0],one[1]+two[1]};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> e(n+1,0);
    vector<ll> c(n+1,0);
    vector<ll> sum(n+1,0);
    set<array<int,4>> s; //l,r,prv,ini
    vector<array<int,2>> h(1,{0,0});
    for(int i=1;i<=n;i++)
    {
        int ini;
        cin >> ini >> c[i] >> e[i];
        sum[i]=sum[i-1]+e[i];
        s.insert({i,i,0,ini});
        if(e[i]>0) h.push_back({int((c[i]+e[i]-1)/e[i]),i});
    }
    ranges::sort(h);
    int cnt=(int)h.size()-1;
    vector<node*> st(cnt+1,nullptr);
    st[0]=build(1,n);
    for(int i=1;i<=cnt;i++)
    {
        auto [lim,j]=h[i];
        st[i]=update(st[i-1],1,n,j,e[j],c[j]);
    }
    auto qry=[&](int l,int r,int t)->ll
    {
        int p=(ranges::upper_bound(h,array<int,2>{t,n+1})-h.begin()-1);
        auto [x,y]=query(st[p],1,n,l,r);
        return (sum[r]-sum[l-1]-x)*t+y;
    };
    auto split=[&](int p)
    {
        if(p==0||p==n) return;
        auto it=s.lower_bound({p+1,0,0,0});
        it--;
        auto [l,r,prv,ini]=(*it);
        if(p<r)
        {
            s.erase(it);
            s.insert({l,p,prv,ini});
            s.insert({p+1,r,prv,ini});
        }
    };
    int m;
    cin >> m;
    while(m--)
    {
        int t,l,r;
        cin >> t >> l >> r;
        split(l-1); split(r);
        ll res=0;
        while(1)
        {
            auto it=s.lower_bound({l,0,0,0});
            if(it!=s.end()&&(*it)[0]<=r)
            {
                auto [tl,tr,prv,ini]=(*it);
                s.erase(it);
                if(ini>0) res+=min(ini+(t-prv)*e[tl],c[tl]);
                else res+=qry(tl,tr,t-prv);
            }
            else break;
        }
        s.insert({l,r,t,0});
        cout << res << "\n";
    }
    return 0;
}