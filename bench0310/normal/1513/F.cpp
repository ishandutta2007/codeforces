#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll inf=(1ll<<60);

struct SegTree
{
    int n;
    vector<array<ll,2>> tree;
    //0: root to the left
    //1: root to the right
    void ini(int _n)
    {
        n=_n;
        tree.assign(4*(n+5),{inf,inf});
    }
    void update(int idx,int l,int r,int pos,ll val,int t)
    {
        if(l==r) tree[idx][t]=val;
        else
        {
            int m=(l+r)/2;
            if(pos<=m) update(2*idx,l,m,pos,val,t);
            else update(2*idx+1,m+1,r,pos,val,t);
            for(int i=0;i<2;i++) tree[idx][i]=min(tree[2*idx][i],tree[2*idx+1][i]);
        }
    }
    void upd(int pos,ll val,ll mv)
    {
        update(1,1,n,pos,val-mv,0);
        update(1,1,n,pos,val+mv,1);
    }
    void rm(int pos)
    {
        update(1,1,n,pos,inf,0);
        update(1,1,n,pos,inf,1);
    }
    ll query(int idx,int l,int r,int ql,int qr,int t)
    {
        if(ql>qr) return inf;
        if(l==ql&&r==qr) return tree[idx][t];
        int m=(l+r)/2;
        return min(query(2*idx,l,m,ql,min(qr,m),t),query(2*idx+1,m+1,r,max(ql,m+1),qr,t));
    }
    ll qry(int pos,ll val)
    {
        return min(query(1,1,n,1,pos-1,0)+val,query(1,1,n,pos,n,1)-val);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<ll,2>> v(n);
    for(int i=0;i<n;i++) cin >> v[i][0];
    for(int i=0;i<n;i++) cin >> v[i][1];
    sort(v.begin(),v.end());
    vector<ll> a(n+1,0);
    vector<ll> b(n+1,0);
    for(int i=1;i<=n;i++)
    {
        a[i]=v[i-1][0];
        b[i]=v[i-1][1];
    }
    vector<ll> cost(n+1,0);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cost[i]=abs(a[i]-b[i]);
        sum+=cost[i];
    }
    set<array<ll,2>> one;
    ll res=sum;
    vector<SegTree> st(2);
    for(int i=0;i<2;i++) st[i].ini(n);
    for(int i=n;i>=1;i--)
    {
        while(!one.empty()&&(*one.rbegin())[0]>a[i])
        {
            int pos=(*one.rbegin())[1];
            one.erase({b[pos],pos});
            st[0].rm(pos);
            st[1].upd(pos,-cost[pos]+b[pos],a[pos]);
        }
        int l=0,r=n+1;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(a[m]>=b[i]) r=m;
            else l=m;
        }
        res=min(res,sum-cost[i]+a[i]+st[0].qry(r,b[i]));
        res=min(res,sum-cost[i]-a[i]+st[1].qry(r,b[i]));
        st[0].upd(i,-cost[i]-b[i],a[i]);
        one.insert({b[i],i});
    }
    cout << res << "\n";
    return 0;
}