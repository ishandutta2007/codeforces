#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define debug(x) cout<<#x<<": "<<x<<endl

#define ld double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
ll st[400008];
ll marked[400008];
ll ar[200009];
ll ans[50005];
ll qr[50005][4];
ll pwr=1;
void build(ll v,ll tl,ll tr)
{
    if(tl== tr)
    {
        st[v]=ar[tl];
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        st[v]=st[v*2]+st[v*2+1]; 
    }
}
void push(ll v,ll tl,ll tr)
{
    if(v<400008&&marked[v])
    {
        ll tm=(tl+tr)/2;
        marked[2*v]=marked[2*v]^1;
        st[2*v]=tm-tl+1-st[2*v];
        marked[2*v+1]=marked[2*v+1]^1;
        st[2*v+1]=tr-tm-st[2*v+1];
        marked[v]=0;
    }
}
void update(ll v, ll tl,ll tr,ll l,ll r)
{
    if(l>r)
    {
        return;
    }
    else if(l==tl&&r==tr)
    {
        // debug(l);
        // debug(r);
        marked[v]=marked[v]^1;
        st[v]=r-l+1-st[v];
    }
    else
    {
        push(v,tl,tr);
        ll tm=(tl+tr)/2;
        update( 2*v, tl,tm,l,min(r,tm));
        update( 2*v+1, tm+1,tr,max(l,tm+1),min(r,r));
        st[v]=st[2*v]+st[v*2+1];
    }
}
ll get(ll v,ll tl,ll tr,ll l, ll r)
{
    if(l>r)
    {
        return 0;
    }
    else if(l==tl&&r==tr)
    {
        // debug(l);
        // debug(r);
        // debug(st[v]);
        return st[v];
    }
    push(v,tl,tr);
    ll tm=(tl+tr)/2;
    return get(2*v,tl,tm,l,min(r,tm))+get(2*v+1,tm+1,tr,max(l,tm+1),r);
}
#define INF 100000000000000000
int main()
{
    
    long double pi= 3.14159265358979323846;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n,q;
    cin>>n;
    ll num[n];
    rep(i,n)
    {
        cin>>num[i];
    }
    cin>>q;
    // debug(q);
    rep(i,q)
    {
        ll a,b,c,d;
        cin>>a;
        qr[i][0]=a;
        if(a==1)
        {
            cin>>b>>c;
            qr[i][1]=b;
            qr[i][2]=c;
        }
        else
        {
            cin>>b>>c>>d;
            qr[i][1]=b;
            qr[i][2]=c;
            qr[i][3]=d;
        }
    }
    rep(dka,20)
    {
        rep(i,400008)
        {
            marked[i]=0;
        }
        rep(i,n)
        {
            ar[i]=num[i]%2;
            // debug(num[i]);
            num[i]/=2;
        }
        build(1,0,n-1);
        
        // cout<<"SF"<<endl;
        rep(i,q)
        {
            if(qr[i][0]==1)
            {
                ll zz=get(1,0,n-1,qr[i][1]-1,qr[i][2]-1);
                ans[i]+=zz*pwr;
                // debug(zz);
                // debug(qr[i][1]);
                // debug(qr[i][2]);
            }
            else
            {
                ll zz=qr[i][3]%2;
                qr[i][3]/=2;
                if(zz)
                {
                    update(1,0,n-1,qr[i][1]-1,qr[i][2]-1);
                }
            }
        }
        
        // debug("Fdas");
         pwr=pwr*2;
    }
    rep(i,q)
    {
        if(qr[i][0]==1)
        {
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}