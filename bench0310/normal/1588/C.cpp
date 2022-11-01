#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct obj
{
    array<ll,2> mn;
    array<ll,2> mn_cnt;
    array<ll,2> lazy;
    obj(){mn={(1ll<<60),(1ll<<60)};mn_cnt={0,0};lazy={0,0};}
    void ini(int p)
    {
        int r=(p&1);
        mn[r]=0;
        mn_cnt[r]=1;
        mn[r^1]=(1ll<<60);
        mn_cnt[r^1]=0;
    }
    void pull(obj a,obj b)
    {
        for(int r=0;r<2;r++)
        {
            mn[r]=min(a.mn[r],b.mn[r]);
            mn_cnt[r]=((a.mn[r]==mn[r])*a.mn_cnt[r]+(b.mn[r]==mn[r])*b.mn_cnt[r]);
        }
    }
    void apply(array<ll,2> t)
    {
        for(int r=0;r<2;r++)
        {
            mn[r]+=t[r];
            lazy[r]+=t[r];
        }
    }
    void push(obj &a,obj &b)
    {
        a.apply(lazy);
        b.apply(lazy);
        lazy={0,0};
    }
};

const int N=300005;
vector<obj> tree(4*N);

void pull(int idx){tree[idx].pull(tree[2*idx],tree[2*idx+1]);}
void apply(int idx,array<ll,2> t){tree[idx].apply(t);}
void push(int idx){tree[idx].push(tree[2*idx],tree[2*idx+1]);}

void build(int idx,int l,int r)
{
    tree[idx].lazy={0,0};
    if(l==r) tree[idx].ini(l);
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        pull(idx);
    }
}

void update(int idx,int l,int r,int ql,int qr,array<ll,2> t)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,t);
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),t);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,t);
        pull(idx);
    }
}

int descend(int idx,int l,int r)
{
    if(l==r) return l;
    int m=(l+r)/2;
    push(idx);
    if(min(tree[2*idx].mn[0],tree[2*idx].mn[1])<0) return descend(2*idx,l,m);
    else return descend(2*idx+1,m+1,r);
}

obj query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return obj();
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx);
    obj o;
    o.pull(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
    return o;
}

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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        build(1,1,n);
        ll res=0;
        for(int i=n;i>=1;i--)
        {
            int x=a[i];
            if(i&1) x=-x;
            update(1,1,n,i,n,{x,-x});
            int lim=n;
            if(min(tree[1].mn[0],tree[1].mn[1])<0) lim=descend(1,1,n)-1;
            obj o=query(1,1,n,i,lim);
            for(int r=0;r<2;r++) res+=((o.mn[r]==0)*o.mn_cnt[r]);
        }
        cout << res << "\n";
    }
    return 0;
}