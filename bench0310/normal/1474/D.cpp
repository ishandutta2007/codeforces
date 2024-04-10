#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct SegTree
{
    int n;
    vector<ll> tree;
    vector<ll> lazy;
    SegTree(int _n):n(_n)
    {
        tree.assign(4*(_n+5),0);
        lazy.assign(4*(_n+5),0);
    }
    void push(int idx)
    {
        for(int i=0;i<2;i++)
        {
            tree[2*idx+i]+=lazy[idx];
            lazy[2*idx+i]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    void update(int idx,int l,int r,int ql,int qr,ll x)
    {
        if(ql>qr) return;
        if(l==ql&&r==qr)
        {
            tree[idx]+=x;
            lazy[idx]+=x;
        }
        else
        {
            int m=(l+r)/2;
            push(idx);
            update(2*idx,l,m,ql,min(qr,m),x);
            update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
            tree[idx]=min(tree[2*idx],tree[2*idx+1]);
        }
    }
    void upd(int ql,int qr,ll x){update(1,1,n,ql,qr,x);}
    ll query(int idx,int l,int r,int pos)
    {
        if(l==r) return tree[idx];
        int m=(l+r)/2;
        push(idx);
        if(pos<=m) return query(2*idx,l,m,pos);
        else return query(2*idx+1,m+1,r,pos);
    }
    ll qry(){return query(1,1,n,n);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        SegTree odd((n+1)/2);
        SegTree even(n/2);
        auto go=[&](int l,int r,ll x) //update [l,r] with x, with +x start
        {
            if(l&1)
            {
                odd.upd((l+2)/2,(r+1)/2,x);
                even.upd((l+1)/2,r/2,-x);
            }
            else
            {
                odd.upd((l+2)/2,(r+1)/2,-x);
                even.upd((l+1)/2,r/2,x);
            }
        };
        for(int i=1;i<=n;i++)
        {
            go(i,n,a[i]);
        }
        auto ch=[&]()->bool
        {
            bool ok=1;
            ok&=(odd.tree[1]>=0);
            ok&=(even.tree[1]>=0);
            if(n&1) ok&=(odd.qry()==0);
            else ok&=(even.qry()==0);
            return ok;
        };
        bool res=ch();
        auto sw=[&](int i)
        {
            go(i,n,-a[i]);
            go(i+1,n,-a[i+1]);
            swap(a[i],a[i+1]);
            go(i,n,a[i]);
            go(i+1,n,a[i+1]);
        };
        for(int i=1;i<n;i++)
        {
            sw(i);
            res|=ch();
            sw(i);
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}