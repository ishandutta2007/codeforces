#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct ST
{
    int n;
    vector<int> tree;
    map<ll,int> h;
    ST(vector<ll> val)
    {
        ranges::sort(val);
        n=0;
        for(int i=0;i<(int)val.size();i++)
        {
            if(i==0||val[i-1]!=val[i]) n++;
            h[val[i]]=n;
        }
        tree.assign(4*(n+5),-(1<<30));
    }
    void update(int idx,int l,int r,int pos,int val)
    {
        if(l==r) tree[idx]=max(tree[idx],val);
        else
        {
            int m=(l+r)/2;
            if(pos<=m) update(2*idx,l,m,pos,val);
            else update(2*idx+1,m+1,r,pos,val);
            tree[idx]=max(tree[2*idx],tree[2*idx+1]);
        }
    }
    int query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>qr) return -(1<<30);
        if(l==ql&&r==qr) return tree[idx];
        int m=(l+r)/2;
        return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
    }
    void upd(ll p,int val){update(1,1,n,h[p],val);}
    int qry_below(ll p){return query(1,1,n,1,h[p]-1);}
    int qry_above(ll p){return query(1,1,n,h[p]+1,n);}
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
        vector<ll> s(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            s[i]=s[i-1]+a[i];
        }
        ST pos(s);
        ST neg(s);
        map<ll,int> mx;
        auto upd=[&](ll p,int val,int i)
        {
            pos.upd(p,val-i);
            neg.upd(p,val+i);
            if(mx.contains(p)) mx[p]=max(mx[p],val);
            else mx[p]=val;
        };
        upd(0,0,0);
        for(int i=1;i<=n;i++)
        {
            int now=max(pos.qry_below(s[i])+i,neg.qry_above(s[i])-i);
            if(mx.contains(s[i])) now=max(now,mx[s[i]]);
            upd(s[i],now,i);
            if(i==n) cout << now << "\n";
        }
    }
    return 0;
}