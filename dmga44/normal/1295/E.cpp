#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 200005

ll a[MAXN],c[MAXN];
ll st[4*MAXN],lazy[4*MAXN];

void push(int p,int l,int r)
{
    if(l==r)
    {
        lazy[p]=0;
        return ;
    }

    lazy[p<<1]+=lazy[p];
    st[p<<1]+=lazy[p];
    lazy[(p<<1)+1]+=lazy[p];
    st[(p<<1)+1]+=lazy[p];

    lazy[p]=0;
}

void update(int p,int l,int r,int L,int R,ll v)
{
    push(p,l,r);
    if(L<=l && r<=R)
    {
        st[p]+=v;
        lazy[p]=v;
        return ;
    }
    if(l>R || L>r)
        return ;
    int mid=(l+r)>>1;

    update(p<<1,l,mid,L,R,v);
    update((p<<1)+1,mid+1,r,L,R,v);

    st[p]=min(st[p<<1],st[(p<<1)+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    for(ll i=0;i<n;i++)
        cin >> a[i];
    for(ll i=0;i<n;i++)
        cin >> c[a[i]];

    for(ll i=1;i<=n;i++)
        update(1,1,n,i,n,c[i]);
    ll res=1e18;
    for(ll i=0;i<n-1;i++)
    {
//        for(int j=0;j<4*n;j++)
//            cout << j << ":" << st[j] << '\n';
//        cout << '\n';
        update(1,1,n,a[i],n,-c[a[i]]);
        if(a[i]>1)
            update(1,1,n,1,a[i]-1,c[a[i]]);
//                for(int j=0;j<4*n;j++)
//            cout << j << ":" << st[j] << '\n';
//        cout << '\n';

        res=min(res,st[1]);
    }
    db(min(res,min(c[a[0]],c[a[n-1]])))

    return 0;
}
/**
2
2 1
9 10
**/