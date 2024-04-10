#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<string,ll> psi;
typedef pair<ll,char> pic;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 100005

ll n,mod,p[MAXN],ps[MAXN][10],a[MAXN],up[10];
ll por[9][18*MAXN];
vector<ll> pr;

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!p[i])
            for(int j=i;j<MAXN;j+=i)
                p[j]=i;
}

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

struct node{
    int po[9];
    ll mul,sum;
}st[4*MAXN],lazy[4*MAXN];

void build(int p,int l,int r)
{
    st[p].mul=1;
    lazy[p].mul=1;
    for(int i=0;i<9;i++)
    {
        st[p].po[i]=0;
        lazy[p].po[i]=0;
    }
    if(l==r)
    {
        st[p].sum=(a[l])%mod;
        return ;
    }
    int mid=(l+r)>>1;

    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);
    st[p].sum=(st[p<<1].sum+st[(p<<1)+1].sum)%mod;
}

void push(int p,int l,int r)
{
    if(l==r)
        return;
    lazy[p<<1].mul=(lazy[p<<1].mul*lazy[p].mul)%mod;
    st[p<<1].mul=(st[p<<1].mul*lazy[p].mul)%mod;
    st[p<<1].sum=(st[p<<1].sum*lazy[p].mul)%mod;
    for(int i=0;i<9;i++)
    {
        lazy[p<<1].po[i]+=lazy[p].po[i];
        st[p<<1].po[i]+=lazy[p].po[i];
        st[p<<1].sum=(st[p<<1].sum*por[i][lazy[p].po[i]])%mod;
    }

    lazy[(p<<1)+1].mul=(lazy[(p<<1)+1].mul*lazy[p].mul)%mod;
    st[(p<<1)+1].mul=(st[(p<<1)+1].mul*lazy[p].mul)%mod;
    st[(p<<1)+1].sum=(st[(p<<1)+1].sum*lazy[p].mul)%mod;
    for(int i=0;i<9;i++)
    {
        lazy[(p<<1)+1].po[i]+=lazy[p].po[i];
        st[(p<<1)+1].po[i]+=lazy[p].po[i];
        st[(p<<1)+1].sum=(st[(p<<1)+1].sum*por[i][lazy[p].po[i]])%mod;
    }

    lazy[p].mul=1;
    for(int i=0;i<9;i++)
        lazy[p].po[i]=0;
}

ll query(int p,int l,int r,int L,int R)
{
    push(p,l,r);
    if(L<=l && r<=R)
        return (st[p].sum)%mod;
    if(l>R || L>r)
        return 0;
    int mid=(l+r)>>1;

    return (query(p<<1,l,mid,L,R)+query((p<<1)+1,mid+1,r,L,R))%mod;
}

ll q1(int p,int l,int r,int pos)
{
    push(p,l,r);
    if(l==r && l==pos)
        return p;
    if(l>pos || r<pos)
        return -1;
    int mid=(l+r)>>1;

    return max(q1(p<<1,l,mid,pos),q1((p<<1)+1,mid+1,r,pos));
}

void update(int p,int l,int r,int L,int R)
{
    push(p,l,r);
    if(L<=l && r<=R)
    {
        st[p].mul=(st[p].mul*up[0])%mod;
        lazy[p].mul=(lazy[p].mul*up[0])%mod;
        st[p].sum=(st[p].sum*up[0])%mod;
        for(int i=0;i<9;i++)
        {
            st[p].po[i]+=up[i+1];
            lazy[p].po[i]+=up[i+1];
            st[p].sum=(st[p].sum*por[i][up[i+1]])%mod;
        }
        return ;
    }
    if(l>R || L>r)
        return ;
    int mid=(l+r)>>1;

    update(p<<1,l,mid,L,R);
    update((p<<1)+1,mid+1,r,L,R);

    st[p].sum=(st[p<<1].sum+st[(p<<1)+1].sum)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    criba();

    cin >> n >> mod;
    ll moddd=mod;
    ll fi=mod;
    for(ll i=2;i<MAXN;i++)
    {
        if(p[i]==i && moddd%i==0)
        {
            fi=(fi*(i-1))/i;
            pr.push_back(i);
            while(moddd%i==0)
                moddd/=i;
        }
    }
    if(moddd!=1)
    {
        pr.push_back(moddd);
        fi=(fi*(moddd-1))/moddd;
    }
    for(int i=0;i<9;i++)
    {
        por[i][0]=1;
        for(int j=1;j<18*MAXN;j++)
        {
            if(i<pr.size())
                por[i][j]=(por[i][j-1]*pr[i])%mod;
            else
                por[i][j]=1;
        }
    }

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        int xxxx=a[i];
        for(int j=0;j<pr.size();j++)
            while(xxxx%pr[j]==0)
            {
                ps[i][j+1]++;
                xxxx/=pr[j];
            }
        ps[i][0]=xxxx;
    }

    build(1,0,n-1);

    int q;
    cin >> q;
    while(q--)
    {
//        db("")
        int t;
        cin >> t;
        if(t==3)
        {
            int l,r;
            cin >> l >> r;
            l--,r--;
            db(query(1,0,n-1,l,r))
        }
        else if(t==2)
        {
            ll p,x;
            cin >> p >> x;
            p--;
            int pos=q1(1,0,n-1,p);
            ll mu=st[pos].mul;
            ll poo[9];
            for(int i=0;i<9;i++)
                poo[i]=st[pos].po[i];

            ll info[10];
            for(int i=0;i<10;i++)
                info[i]=0;
            for(int j=0;j<pr.size();j++)
                while(x%pr[j]==0)
                {
                    info[j+1]++;
                    x/=pr[j];
                }
            info[0]=x;

//            db(fi)
//            for(int i=0;i<10;i++)
//                cout << info[i] << ' ';
//            db("")
//            for(int i=0;i<10;i++)
//                cout << ps[p][i] << ' ';
//            db("")

            ps[p][0]=(ps[p][0]*qp(info[0],fi-1))%mod;
            for(int i=1;i<10;i++)
                ps[p][i]-=info[i];

            ll n_val=(ps[p][0]*st[pos].mul)%mod;
            for(int i=0;i<9;i++)
                n_val=(n_val*por[i][ps[p][i+1]+st[pos].po[i]])%mod;

//            for(int i=0;i<10;i++)
//                cout << ps[p][i] << ' ';
//            db("")
//            cout << st[pos].mul << ' ';
//            for(int i=0;i<9;i++)
//                cout << st[pos].po[i] << ' ';
//            db("")
            ll dif=(n_val-st[pos].sum+mod)%mod;
            while(pos)
            {
                st[pos].sum=(st[pos].sum+dif)%mod;
                pos>>=1;
            }
        }
        else
        {
            ll l,r,x;
            cin >> l >> r >> x;
            l--,r--;

            for(int i=0;i<10;i++)
                up[i]=0;
            for(int j=0;j<pr.size();j++)
                while(x%pr[j]==0)
                {
                    up[j+1]++;
                    x/=pr[j];
                }
            up[0]=x%mod;

            update(1,0,n-1,l,r);
        }
    }

    return 0;
}