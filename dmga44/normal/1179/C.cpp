#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef long double ld;
#define MAXN 1000005

int a[MAXN],b[MAXN];
int st[4*MAXN];
int lazy[4*MAXN];

void push(int p,int l,int r)
{
    if(l==r)
        return ;
    st[p<<1]+=lazy[p];
    st[(p<<1)+1]+=lazy[p];
    lazy[p<<1]+=lazy[p];
    lazy[(p<<1)+1]+=lazy[p];
    lazy[p]=0;
}

void update(int p,int l,int r,int pos,int v)
{
    push(p,l,r);
    if(r<=pos)
    {
        st[p]+=v;
        lazy[p]+=v;
        push(p,l,r);
        return ;
    }
    if(l>pos)
        return ;
    int mid=(l+r)>>1;

    update(p<<1,l,mid,pos,v);
    update((p<<1)+1,mid+1,r,pos,v);

    st[p]=max(st[p<<1],st[(p<<1)+1]);
}

int query(int p,int l,int r)
{
    push(p,l,r);
    if(st[p]<1)
        return -1;
    if(l==r)
        return l;
    int mid=(l+r)>>1;

    int x=query((p<<1)+1,mid+1,r);
    if(x==-1)
        return query(p<<1,l,mid);
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,x;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        update(1,0,MAXN-1,a[i],1);
    }

    for(int i=0;i<m;i++)
    {
        cin >> b[i];
        update(1,0,MAXN-1,b[i],-1);
    }

    int q;
    cin >> q;
    while(q--)
    {
        int t,x,y;
        cin >> t >> x >> y;
        x--;
        if(t==1)
        {
            update(1,0,MAXN-1,a[x],-1);
            a[x]=y;
            update(1,0,MAXN-1,a[x],1);
        }
        else
        {
            update(1,0,MAXN-1,b[x],1);
            b[x]=y;
            update(1,0,MAXN-1,b[x],-1);
        }

        db(query(1,0,MAXN-1))
    }

    return 0;
}