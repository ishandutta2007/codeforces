#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=2000005;
int tree[4*N];
int lazy[4*N];

void pull(int idx){tree[idx]=min(tree[2*idx],tree[2*idx+1]);}
void apply(int idx,int x){tree[idx]+=x;lazy[idx]+=x;}
void push(int idx){for(int i=0;i<2;i++)apply(2*idx+i,lazy[idx]);lazy[idx]=0;}

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

void clean(int idx,int l,int r)
{
    tree[idx]=lazy[idx]=0;
    if(l<r)
    {
        int m=(l+r)/2;
        clean(2*idx,l,m);
        clean(2*idx+1,m+1,r);
    }
}

void pull2(int idx){tree[idx]=tree[2*idx]+tree[2*idx+1];}

void update2(int idx,int l,int r,int pos,int x)
{
    if(l==r) tree[idx]+=x;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update2(2*idx,l,m,pos,x);
        else update2(2*idx+1,m+1,r,pos,x);
        pull2(idx);
    }
}

int query2(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query2(2*idx,l,m,ql,min(qr,m))+query2(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<array<int,3>> h;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            h.push_back({a[i],i,0});
        }
        vector<int> b(m+1,0);
        for(int i=1;i<=m;i++)
        {
            cin >> b[i];
            h.push_back({b[i],i,1});
        }
        ranges::sort(h);
        int id=0;
        for(int i=0;auto [x,j,tp]:h)
        {
            if(i==0||x!=h[i-1][0]) id++;
            if(tp==0) a[j]=id;
            else b[j]=id;
            i++;
        }
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            res+=query2(1,1,n+m,a[i]+1,n+m);
            update2(1,1,n+m,a[i],1);
        }
        for(int i=1;i<=n;i++) update2(1,1,n+m,a[i],-1);
        clean(1,1,n+m);
        vector<array<int,2>> v;
        for(int i=1;i<=n;i++) v.push_back({a[i],i});
        ranges::sort(v);
        int x=0;
        int p=-1;
        for(int i=1;i<=n;i++) update(1,0,n,i,n,1);
        auto mv=[&](int nx)
        {
            while(x<nx)
            {
                for(int i=p;i>=0&&v[i][0]==x;i--) update(1,0,n,0,v[i][1]-1,1);
                x++;
                while(p+1<n&&v[p+1][0]==x)
                {
                    p++;
                    update(1,0,n,v[p][1],n,-1);
                }
            }
        };
        ranges::sort(b);
        for(int i=1;i<=m;i++)
        {
            mv(b[i]);
            res+=tree[1];
        }
        cout << res << "\n";
        mv(n+m+1);
        for(int i=1;i<=n;i++) update(1,0,n,0,i-1,-1);
        clean(1,0,n);
    }
    return 0;
}