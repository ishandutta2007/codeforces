#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N=400000+5;
const ll M=400000+5;

ll n,m,cost;
ll x[N],d[N],p[N];
ll add[N];

struct AINT
{
    ll best;
    ll st;
    ll dr;
    ll sum;
};

AINT a[3*N];

void update(ll nod,ll st,ll dr,ll poz,ll val)
{
    if(st==dr)
    {
        a[nod].best=val;
        a[nod].st=val;
        a[nod].dr=val;
        a[nod].sum=val;
        return;
    }
    ll med=(st+dr)/2;
    if(poz<=med)
        update(2*nod,st,med,poz,val);
    else
        update(2*nod+1,med+1,dr,poz,val);
    a[nod].sum=a[2*nod].sum+a[2*nod+1].sum;
    a[nod].st=max(a[2*nod].st,a[2*nod].sum+a[2*nod+1].st);
    a[nod].dr=max(a[2*nod+1].dr,a[2*nod+1].sum+a[2*nod].dr);
    a[nod].best=max(max(a[2*nod].best,a[2*nod+1].best),a[2*nod].dr+a[2*nod+1].st);
}

ll best=0,s2=0;

void slove(ll nod,ll st,ll dr,ll x,ll y)
{
    if(x<=st && dr<=y)
    {
        best=max(best,a[nod].best);
        best=max(best,s2+a[nod].st);
        s2=max(s2+a[nod].sum,a[nod].dr);
    }
    else
    {
        ll med=(st+dr)/2;
        if(x<=med)
            slove(2*nod,st,med,x,y);
        if(y>=med+1)
            slove(2*nod+1,med+1,dr,x,y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>cost;
    for(ll i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(ll i=1;i<n;i++)
    {
        cin>>p[i];
        d[i]=x[i+1]-x[i];
    }
    for(int i=0;i<3*N;i++)
    {
        a[i].sum=-(1LL<<60);
        a[i].st=-(1LL<<60);
        a[i].dr=-(1LL<<60);
        a[i].best=-(1LL<<60);
    }
    for(ll i=1;i<n;i++)
    {
        add[i]=50*d[i]-p[i]*cost;
        update(1,1,n-1,i,add[i]);
    }
    ll ans=0;
    for(ll i=1;i<=m;i++)
    {
        ll st,dr;
        cin>>st>>dr;
        best=0;
        s2=0;
        slove(1,1,n-1,st,dr-1);
        ans+=best;
    }
    long double answer=ans;
    answer=0.01*answer;
    cout<<fixed<<setprecision(100)<<answer<<"\n";
    return 0;
}