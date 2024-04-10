#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct MinST
{
    int n;
    vector<int> a;
    vector<array<int,2>> tree;
    const int inf=(1<<30);
    MinST(vector<int> v)
    {
        n=int(v.size())-1;
        a=v;
        tree.resize(4*(n+5));
        build(1,1,n);
    }
    void build(int idx,int l,int r)
    {
        if(l==r) tree[idx]={a[l],l};
        else
        {
            int m=(l+r)/2;
            build(2*idx,l,m);
            build(2*idx+1,m+1,r);
            tree[idx]=min(tree[2*idx],tree[2*idx+1]);
        }
    }
    void update(int idx,int l,int r,int pos)
    {
        if(l==r) tree[idx]={inf,l};
        else
        {
            int m=(l+r)/2;
            if(pos<=m) update(2*idx,l,m,pos);
            else update(2*idx+1,m+1,r,pos);
            tree[idx]=min(tree[2*idx],tree[2*idx+1]);
        }
    }
    array<int,2> query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>qr) return {inf,0};
        if(l==ql&&r==qr) return tree[idx];
        int m=(l+r)/2;
        return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
    }
    int go(int l,int r,int lim) //must be <lim
    {
        auto [val,p]=query(1,1,n,l,r);
        if(val<lim)
        {
            update(1,1,n,p);
            return p;
        }
        else return -1;
    }
};

struct MaxST
{
    int n;
    vector<int> a;
    vector<array<int,2>> tree;
    const int inf=-(1<<30);
    MaxST(vector<int> v)
    {
        n=int(v.size())-1;
        a=v;
        tree.resize(4*(n+5));
        build(1,1,n);
    }
    void build(int idx,int l,int r)
    {
        if(l==r) tree[idx]={a[l],l};
        else
        {
            int m=(l+r)/2;
            build(2*idx,l,m);
            build(2*idx+1,m+1,r);
            tree[idx]=min(tree[2*idx],tree[2*idx+1]);
        }
    }
    void update(int idx,int l,int r,int pos)
    {
        if(l==r) tree[idx]={inf,l};
        else
        {
            int m=(l+r)/2;
            if(pos<=m) update(2*idx,l,m,pos);
            else update(2*idx+1,m+1,r,pos);
            tree[idx]=min(tree[2*idx],tree[2*idx+1]);
        }
    }
    array<int,2> query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>qr) return {inf,0};
        if(l==ql&&r==qr) return tree[idx];
        int m=(l+r)/2;
        return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
    }
    int go(int l,int r,int lim) //must be >lim
    {
        auto [val,p]=query(1,1,n,l,r);
        if(val>lim)
        {
            update(1,1,n,p);
            return p;
        }
        else return -1;
    }
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
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) cin >> p[i];
        vector<int> lsmall(n+1,0);
        vector<int> lbig(n+1,0);
        vector<int> rsmall(n+1,0);
        vector<int> rbig(n+1,0);
        stack<int> s;
        for(int i=1;i<=n;i++)
        {
            while(!s.empty()&&p[s.top()]>p[i]) s.pop();
            lsmall[i]=(!s.empty()?s.top():0);
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=1;i<=n;i++)
        {
            while(!s.empty()&&p[s.top()]<p[i]) s.pop();
            lbig[i]=(!s.empty()?s.top():0);
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n;i>=1;i--)
        {
            while(!s.empty()&&p[s.top()]>p[i]) s.pop();
            rsmall[i]=(!s.empty()?s.top():n+1);
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n;i>=1;i--)
        {
            while(!s.empty()&&p[s.top()]<p[i]) s.pop();
            rbig[i]=(!s.empty()?s.top():n+1);
            s.push(i);
        }
        while(!s.empty()) s.pop();
        MinST lsmallst(lsmall);
        MinST lbigst(lbig);
        MaxST rsmallst(rsmall);
        MaxST rbigst(rbig);
        queue<int> q;
        vector<int> d(n+1,-1);
        auto add=[&](int a,int nd)
        {
            if(d[a]==-1)
            {
                d[a]=nd;
                q.push(a);
            }
        };
        add(1,0);
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            int b=-1;
            while((b=lsmallst.go(a+1,rbig[a]-1,a))!=-1) add(b,d[a]+1);
            while((b=lbigst.go(a+1,rsmall[a]-1,a))!=-1) add(b,d[a]+1);
            while((b=rsmallst.go(lbig[a]+1,a-1,a))!=-1) add(b,d[a]+1);
            while((b=rbigst.go(lsmall[a]+1,a-1,a))!=-1) add(b,d[a]+1);
        }
        cout << d[n] << "\n";
    }
    return 0;
}