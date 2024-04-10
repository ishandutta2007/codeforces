///Profe, si quiere cambie el archivo predeterminado en
///C:\Program Files (x86)\CodeBlocks\share\CodeBlocks\templates\wizard\console\cpp
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define MAXN 100005
#define oo ((ll)(1e18))

ll a[MAXN],k[MAXN],st[4*MAXN],lazy[4*MAXN];
map<ll,ll> m;
set<ll> s;

void build(ll p,ll l,ll r)
{
    if(l==r)
    {
        st[p]=a[l];
        return ;
    }
    int mid=(l+r)>>1;

    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);

    st[p]=st[p<<1]+st[(p<<1)+1];
}

void push(ll p,ll l,ll r)
{
    if(!lazy[p])
        return;
    ll x=lazy[p];
    lazy[p]=0;
    st[p]=(st[p]+x*(r-l+1));
    if(l!=r)
    {
        lazy[p<<1]+=x;
        lazy[(p<<1)+1]+=x;
    }
}

void update(ll p,ll l,ll r,ll L,ll R,ll x)
{
    push(p,l,r);
    if(L<=l && r<=R)
    {
        lazy[p]=x;
        push(p,l,r);
        return;
    }
    if(l>R || L>r)
        return;
    int mid=(l+r)>>1;

    update(p<<1,l,mid,L,R,x);
    update((p<<1)+1,mid+1,r,L,R,x);

    st[p]=st[p<<1]+st[(p<<1)+1];
}

ll query(ll p,ll l,ll r,ll L,ll R)
{
    push(p,l,r);
    if(L<=l && r<=R)
        return st[p];
    if(l>R || L>r)
        return 0;
    int mid=(l+r)>>1;

    return query(p<<1,l,mid,L,R)+query((p<<1)+1,mid+1,r,L,R);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n-1;i++)
        cin >> k[i];
    for(int i=0;i<n-1;i++)
        if(a[i+1]!=(a[i]+k[i]))
        {
            s.insert(i);
            m[i]=a[i+1]-a[i]-k[i];
        }
    s.insert(n-1);
    m[n-1]=oo;

    build(1,0,n-1);

    cin >> q;
    while(q--)
    {
        char c;
        ll x,y;
        cin >> c >> x >> y;
        if(c=='s')
        {
            x--,y--;
            db(query(1,0,n-1,x,y))
        }
        else
        {
            x--;
            if(s.find(x-1)==s.end())
                s.insert(x-1);
            m[x-1]+=y;
            while(y)
            {
                int xxx=*(s.lower_bound(x));
                update(1,0,n-1,x,xxx,y);
//                cout << x << ' ' << xxx << ' ' << y << '\n';
                x=xxx+1;
                if(m[xxx]<=y)
                {
                    y-=m[xxx];
                    m[xxx]=0;
                    s.erase(xxx);
                }
                else
                {
                    m[xxx]-=y;
                    y=0;
                }
            }
        }
    }

    return 0;
}