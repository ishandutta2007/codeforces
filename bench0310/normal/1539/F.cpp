#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
const int inf=(1<<30);

struct ST
{
    int n;
    vector<int> tree;
    vector<int> lazy;
    ST(int _n)
    {
        n=_n;
        tree.assign(4*(n+5),0);
        lazy.assign(4*(n+5),0);
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
    void update(int idx,int l,int r,int ql,int qr,int val)
    {
        if(ql>qr) return;
        if(l==ql&&r==qr)
        {
            tree[idx]+=val;
            lazy[idx]+=val;
        }
        else
        {
            int m=(l+r)/2;
            push(idx);
            update(2*idx,l,m,ql,min(qr,m),val);
            update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
            tree[idx]=max(tree[2*idx],tree[2*idx+1]);
        }
    }
    void upd(int ql,int qr,int val){update(1,1,n,ql,qr,val);}
    int query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>qr) return -inf;
        if(l==ql&&r==qr) return tree[idx];
        int m=(l+r)/2;
        push(idx);
        return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
    }
    int qry(int ql,int qr){return query(1,1,n,ql,qr);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> v[n+1];
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    vector<int> res(n+1,0);
    auto up=[&]()
    {
        ST l(n);
        ST r(n);
        for(int i=1;i<=n;i++)
        {
            l.upd(i,i,-i);
            r.upd(i,i,i);
        }
        for(int i=1;i<=n;i++)
        {
            for(int x:v[i]) res[x]=max(res[x],(l.qry(1,x)+r.qry(x,n)+1)/2);
            for(int x:v[i])
            {
                l.upd(x+1,n,2);
                r.upd(x,n,-2);
            }
        }
    };
    auto down=[&]()
    {
        ST l(n);
        ST r(n);
        for(int i=1;i<=n;i++)
        {
            l.upd(i,i,i);
            r.upd(i,i,-i);
        }
        for(int i=1;i<=n;i++)
        {
            for(int x:v[i])
            {
                l.upd(x+1,n,-2);
                r.upd(x,n,2);
            }
            for(int x:v[i]) res[x]=max(res[x],(l.qry(1,x)+r.qry(x,n)-2)/2);
        }
    };
    up();
    down();
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}