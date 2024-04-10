#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 4000005

int st[4*MAXN],lazy[4*MAXN];

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

void update(int p,int l,int r,int L,int R,int v)
{
    push(p,l,r);
    if(L<=l && r<=R)
    {
        st[p]+=v;
        lazy[p]+=v;
        push(p,l,r);
        return ;
    }
    if(L>r || l>R)
        return ;
    int mid=(l+r)>>1;

    update(p<<1,l,mid,L,R,v);
    update((p<<1)+1,mid+1,r,L,R,v);

    st[p]=max(st[p<<1],st[(p<<1)+1]);
}

int query(int p,int l,int r,int L,int R)
{
    push(p,l,r);
    if(L<=l && r<=R)
        return st[p];
    if(L>r || l>R)
        return 0;
    int mid=(l+r)>>1;

    return max(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,r,x,y;
    cin >> n >> r;
    vector<pii> v;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        ll xx=x-y+(MAXN/2);
        ll yy=x+y;
        x=xx;
        y=yy;
        v.push_back(pii(y,x));
    }

    sort(v.rbegin(),v.rend());

    int pl=0,pr=0,res=0;
    for(int i=MAXN;i>-MAXN;i--)
    {
        while(pl<n && v[pl].first>i+2*r)
        {
            update(1,0,MAXN-1,max(v[pl].second-2*r,0),v[pl].second,-1);
            pl++;
        }

        while(pr<n && v[pr].first>=i)
        {
            update(1,0,MAXN-1,max(v[pr].second-2*r,0),v[pr].second,1);
            pr++;
        }

        res=max(res,st[1]);
    }
    db(res)

    return 0;
}