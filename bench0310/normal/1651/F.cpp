#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200000;

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
    vector<ll> sum(n+1,0);
    vector<ll> e(n+1,0);
    vector<ll> c(n+1,0);
    vector<node*> st(n+1,nullptr);
    st[0]=build(1,N);
    for(int i=1;i<=n;i++)
    {
        cin >> c[i] >> e[i];
        sum[i]=sum[i-1]+e[i];
        st[i]=st[i-1];
        ll lim=((c[i]+e[i]-1)/e[i]);
        if(lim<=N) st[i]=update(st[i],1,N,lim,e[i],c[i]);
    }
    auto qry_one=[&](int p,int t)->ll
    {
        auto [x,y]=query(st[p],1,N,1,t);
        return (sum[p]-x)*t+y;
    };
    auto qry=[&](int l,int r,int t)->ll{return (qry_one(r,t)-qry_one(l-1,t));};
    auto eval=[&](array<int,4> a,int t)->ll
    {
        auto [l,r,prv,ini]=a;
        if(ini==0) return qry(l,r,t-prv);
        else return min(ini+e[l]*(t-prv),c[l]);
    };
    stack<array<int,4>> s; //l,r,t,ini
    for(int i=n;i>=1;i--) s.push({i,i,0,int(c[i])});
    int q;
    cin >> q;
    ll res=0;
    while(q--)
    {
        int t;
        ll h;
        cin >> t >> h;
        while(!s.empty())
        {
            ll tmp=eval(s.top(),t);
            if(tmp<h)
            {
                h-=tmp;
                s.pop();
            }
            else break;
        }
        if(!s.empty())
        {
            auto [l,r,prv,ini]=s.top();
            s.pop();
            if(ini>0)
            {
                ll now=eval({l,l,prv,ini},t);
                s.push({l,l,t,int(now-h)});
            }
            else
            {
                ll tmp=qry_one(l-1,t-prv);
                int one=l-1,two=r;
                while(one<two-1)
                {
                    int m=(one+two)/2;
                    if(qry_one(m,t-prv)-tmp>=h) two=m;
                    else one=m;
                }
                if(two+1<=r) s.push({two+1,r,prv,0});
                ll cnt=h-(qry_one(two-1,t-prv)-tmp);
                ll now=min(e[two]*(t-prv),c[two]);
                s.push({two,two,t,int(now-cnt)});
                if(l<two) s.push({l,two-1,t,0});
            }
            if(l>=2) s.push({1,l-1,t,0});
            h=0;
        }
        else s.push({1,n,t,0});
        res+=h;
    }
    cout << res << "\n";
    return 0;
}