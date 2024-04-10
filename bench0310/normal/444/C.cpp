#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<ll> tree(4*N,0);
vector<ll> lazy(4*N,0);

void push(int idx,int l,int r,int m)
{
    tree[2*idx]+=(lazy[idx]*(m-l+1));
    tree[2*idx+1]+=(lazy[idx]*(r-m));
    lazy[2*idx]+=lazy[idx];
    lazy[2*idx+1]+=lazy[idx];
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,ll x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]+=(x*(r-l+1));
        lazy[idx]+=x;
    }
    else
    {
        int m=(l+r)/2;
        push(idx,l,r,m);
        update(2*idx,l,m,ql,min(qr,m),x);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
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

vector<int> ctree(4*N,0);
vector<int> clazy(4*N,0);

void cpush(int idx)
{
    if(clazy[idx]==0) return;
    for(int i=0;i<2;i++)
    {
        ctree[2*idx+i]=clazy[idx];
        clazy[2*idx+i]=clazy[idx];
    }
    clazy[idx]=0;
}

void cupdate(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        ctree[idx]=x;
        clazy[idx]=x;
    }
    else
    {
        int m=(l+r)/2;
        cpush(idx);
        cupdate(2*idx,l,m,ql,min(qr,m),x);
        cupdate(2*idx+1,m+1,r,max(ql,m+1),qr,x);
    }
}

int cquery(int idx,int l,int r,int pos)
{
    if(l==r) return ctree[idx];
    int m=(l+r)/2;
    cpush(idx);
    if(pos<=m) return cquery(2*idx,l,m,pos);
    else return cquery(2*idx+1,m+1,r,pos);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    set<int> s;
    auto col=[&](int pos)->int{return cquery(1,1,n,pos);};
    for(int i=1;i<=n;i++)
    {
        if(i<n) s.insert(i);
        cupdate(1,1,n,i,i,i);
    }
    while(m--)
    {
        int t,l,r,x;
        cin >> t >> l >> r;
        if(t==1)
        {
            cin >> x;
            s.insert(r);
            int now=l;
            while(now<=r)
            {
                int nxt=*s.lower_bound(l);
                int y=col(now);
                update(1,1,n,now,nxt,abs(x-y));
                s.erase(nxt);
                now=nxt+1;
            }
            cupdate(1,1,n,l,r,x);
            if(l>1&&col(l-1)!=x) s.insert(l-1);
            if(r<n&&col(r+1)!=x) s.insert(r);
        }
        else cout << query(1,1,n,l,r) << "\n";
    }
    return 0;
}