#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> val(N,0);
vector<ll> sum(4*N,0);
vector<int> mn(4*N,0);
vector<int> mx(4*N,0);
vector<int> lazy(4*N,0);

void recalc(int idx)
{
    sum[idx]=sum[2*idx]+sum[2*idx+1];
    mn[idx]=mn[2*idx+1];
    mx[idx]=mx[2*idx];
}

void build(int idx,int l,int r)
{
    if(l==r)
    {
        sum[idx]=val[l];
        mn[idx]=val[l];
        mx[idx]=val[l];
    }
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        recalc(idx);
    }
}

void push(int idx,int l,int r,int m)
{
    if(lazy[idx]!=0)
    {
        sum[2*idx]=((ll)(m-l+1)*lazy[idx]);
        sum[2*idx+1]=((ll)(r-(m+1)+1)*lazy[idx]);
        mn[2*idx]=mn[2*idx+1]=mx[2*idx]=mx[2*idx+1]=lazy[2*idx]=lazy[2*idx+1]=lazy[idx];
        lazy[idx]=0;
    }
}

void update(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        sum[idx]=((ll)(r-l+1)*x);
        mn[idx]=x;
        mx[idx]=x;
        lazy[idx]=x;
    }
    else
    {
        int m=(l+r)/2;
        push(idx,l,r,m);
        update(2*idx,l,m,ql,min(qr,m),x);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
        recalc(idx);
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return sum[idx];
    int m=(l+r)/2;
    push(idx,l,r,m);
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int descend_min(int idx,int l,int r,int x)
{
    if(l==r) return l;
    int m=(l+r)/2;
    push(idx,l,r,m);
    if(mn[2*idx]<=x) return descend_min(2*idx,l,m,x);
    else return descend_min(2*idx+1,m+1,r,x);
}

int descend_sum(int idx,int l,int r,ll c)
{
    if(l==r) return l;
    int m=(l+r)/2;
    push(idx,l,r,m);
    if(sum[2*idx]+mx[2*idx+1]<=c) return descend_sum(2*idx+1,m+1,r,c-sum[2*idx]);
    else return descend_sum(2*idx,l,m,c);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> val[i];
    build(1,1,n);
    while(q--)
    {
        int t,x,y;
        cin >> t >> x >> y;
        if(t==1)
        {
            if(mn[1]>=y) continue;
            update(1,1,n,descend_min(1,1,n,y),x,y);
        }
        else
        {
            int res=0;
            int c=y;
            int now=x;
            while(now<=n)
            {
                if(mn[1]>c) break;
                int nxt=descend_min(1,1,n,c);
                if(nxt>now) now=nxt;
                ll one=0;
                if(now>1) one=query(1,1,n,1,now-1);
                int to=descend_sum(1,1,n,c+one);
                c-=query(1,1,n,now,to);
                res+=(to-now+1);
                now=to+1;
            }
            cout << res << "\n";
        }
    }
    return 0;
}