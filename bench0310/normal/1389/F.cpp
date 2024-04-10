#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct ST
{
    int n;
    vector<int> tree;
    vector<int> lazy;
    ST(int m)
    {
        n=m;
        tree.assign(4*(n+5),0);
        lazy.assign(4*(n+5),0);
    }
    void pull(int idx){tree[idx]=max(tree[2*idx],tree[2*idx+1]);}
    void apply(int idx,int x){tree[idx]+=x;lazy[idx]+=x;}
    void push(int idx)
    {
        for(int i=0;i<2;i++) apply(2*idx+i,lazy[idx]);
        lazy[idx]=0;
    }
    void update(int idx,int l,int r,int ql,int qr,int x)
    {
        if(ql>qr) return;
        if(l==ql&&r==qr) apply(idx,x);
        else
        {
            int m=(l+r)/2;
            push(idx);
            update(2*idx,l,m,ql,min(qr,m),x);
            update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
            pull(idx);
        }
    }
    void upd(int ql,int qr,int x){update(1,1,n,ql,qr,x);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,3>> a(n);
    vector<array<int,3>> h;
    for(int i=0;i<n;i++)
    {
        auto &[l,r,t]=a[i];
        cin >> l >> r >> t;
        t--;
        h.push_back({l,i,0});
        h.push_back({r,i,1});
    }
    ranges::sort(h);
    int id=0;
    for(int i=0;i<2*n;i++)
    {
        if(i==0||h[i][0]!=h[i-1][0]) id++;
        a[h[i][1]][h[i][2]]=id;
    }
    vector<array<int,2>> v[2*n+1];
    for(auto [l,r,t]:a) v[l].push_back({r,t});
    vector<ST> st(2,ST(2*n+1));
    int res=0;
    for(int l=2*n;l>=1;l--)
    {
        for(auto [r,t]:v[l]) st[t^1].upd(r+1,2*n+1,1);
        int mx=max(st[0].tree[1],st[1].tree[1]);
        for(int i=0;i<2;i++) st[i].upd(l,l,mx);
        res=max(res,mx);
    }
    cout << res << "\n";
    return 0;
}