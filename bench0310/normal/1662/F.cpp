#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct ST
{
    int n;
    function<array<int,2>(array<int,2>,array<int,2>)> f;
    vector<int> a;
    int d;
    int bad;
    vector<array<int,2>> tree;
    ST(int m,auto g,vector<int> b,int e,int tmp):n(m),f(g),a(b),d(e),bad(tmp)
    {
        tree.assign(4*n,{0,0});
        build(1,1,n);
    }
    void build(int idx,int l,int r)
    {
        if(l==r) tree[idx]={l+d*a[l],l};
        else
        {
            int m=(l+r)/2;
            build(2*idx,l,m);
            build(2*idx+1,m+1,r);
            tree[idx]=f(tree[2*idx],tree[2*idx+1]);
        }
    }
    void update(int idx,int l,int r,int pos,array<int,2> val)
    {
        if(l==r) tree[idx]=val;
        else
        {
            int m=(l+r)/2;
            if(pos<=m) update(2*idx,l,m,pos,val);
            else update(2*idx+1,m+1,r,pos,val);
            tree[idx]=f(tree[2*idx],tree[2*idx+1]);
        }
    }
    array<int,2> query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>qr) return {bad,0};
        if(l==ql&&r==qr) return tree[idx];
        int m=(l+r)/2;
        return f(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
    }
    void rm(int x){update(1,1,n,x,{bad,0});}
    array<int,2> qry(int l,int r){return query(1,1,n,l,r);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,a,b;
        cin >> n >> a >> b;
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) cin >> p[i];
        ST l(n,[](array<int,2> x,array<int,2> y)->array<int,2>{return min(x,y);},p,-1,(1<<30));
        ST r(n,[](array<int,2> x,array<int,2> y)->array<int,2>{return max(x,y);},p,1,-(1<<30));
        queue<int> q;
        vector<int> d(n+1,-1);
        auto add=[&](int x,int nd)
        {
            d[x]=nd;
            q.push(x);
            l.rm(x);
            r.rm(x);
        };
        add(a,0);
        while(!q.empty())
        {
            int e=q.front();
            q.pop();
            while(1)
            {
                auto [val,x]=l.qry(e,min(n,e+p[e]));
                if(val<=e) add(x,d[e]+1);
                else break;
            }
            while(1)
            {
                auto [val,x]=r.qry(max(1,e-p[e]),e);
                if(e<=val) add(x,d[e]+1);
                else break;
            }
        }
        cout << d[b] << "\n";
    }
    return 0;
}