#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct ST
{
    int n;
    vector<ll> tree;
    vector<ll> lazy;
    void ini(int m)
    {
        n=m;
        tree.assign(4*(n+5),0);
        lazy.assign(4*(n+5),0);
    }
    void pull(int idx){tree[idx]=tree[2*idx]+tree[2*idx+1];}
    void apply(int idx,int l,int r,ll x)
    {
        tree[idx]=(r-l+1)*x;
        lazy[idx]=x;
    }
    void push(int idx,int l,int r,int m)
    {
        if(lazy[idx]>0)
        {
            apply(2*idx,l,m,lazy[idx]);
            apply(2*idx+1,m+1,r,lazy[idx]);
            lazy[idx]=0;
        }
    }
    void update(int idx,int l,int r,int ql,int qr,ll x)
    {
        if(ql>qr) return;
        if(l==ql&&r==qr) apply(idx,l,r,x);
        else
        {
            int m=(l+r)/2;
            push(idx,l,r,m);
            update(2*idx,l,m,ql,min(qr,m),x);
            update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
            pull(idx);
        }
    }
    ll query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>qr) return 0;
        if(l==ql&&r==qr) return tree[idx];
        int m=(l+r)/2;
        push(idx,l,r,m);
        return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
    }
    void upd(int ql,int qr,ll x){update(1,0,n,ql,qr,x);}
    ll qry(int ql,int qr){return query(1,0,n,ql,qr);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q,k;
    cin >> n >> q >> k;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<ll> res(q+1,0);
    vector<array<int,2>> queries[n+1];
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin >> l >> r;
        res[i]=a[l];
        queries[l].push_back({r,i});
    }
    for(int i=n;i>=2;i--) a[i]=min(a[i],a[i-1]);
    vector<int> mn(n+1,0);
    deque<int> d;
    auto add=[&](int b)
    {
        while(!d.empty()&&d.back()>b) d.pop_back();
        d.push_back(b);
    };
    auto rm=[&](int b){if(d.front()==b)d.pop_front();};
    for(int i=1;i<k;i++) add(a[i]);
    for(int i=k;i<=n;i++)
    {
        add(a[i]);
        mn[i]=d.front();
        rm(a[i-k+1]);
    }
    vector<int> nxt(n+1,0);
    vector<ST> st(k);
    for(int i=k;i<=min(2*k-1,n);i++)
    {
        stack<array<int,2>> s;
        int x=(n-i)/k;
        int id=i-k;
        st[id].ini(x);
        s.push({0,x+1});
        for(int j=i+x*k;j>=i;j-=k)
        {
            while(s.top()[0]>=mn[j]) s.pop();
            nxt[j]=s.top()[1];
            s.push({mn[j],(j-i)/k});
        }
    }
    for(int i=n;i>=1;i--)
    {
        int id=(i%k);
        int p=(i/k)-1;
        for(auto [r,qid]:queries[i])
        {
            int t=(r-i)/k;
            if(t>0) res[qid]+=st[id].qry(p+1,p+t);
        }
        if(i>=k) st[id].upd(p,nxt[i]-1,mn[i]);
    }
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}