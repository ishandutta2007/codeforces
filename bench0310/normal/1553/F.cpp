#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;

vector<ll> fentree(N,0);
void fenupd(int x,ll val){for(;x<N;x=(x|(x+1))) fentree[x]+=val;}
ll fensum(int x)
{
    ll r=0;
    for(;x>=0;x=(x&(x+1))-1) r+=fentree[x];
    return r;
}

array<ll,2> operator+(const array<ll,2> &a,const array<ll,2> &b){return {a[0]+b[0],a[1]+b[1]};}
array<ll,2> operator-(const array<ll,2> &a,const array<ll,2> &b){return {a[0]-b[0],a[1]-b[1]};}
vector<array<ll,2>> fentree2(3*N,{0,0});
void fenupd2(int x,array<ll,2> val){for(;x<3*N;x=(x|(x+1))) fentree2[x]=fentree2[x]+val;}
array<ll,2> fensum2(int x)
{
    array<ll,2> r={0,0};
    for(;x>=0;x=(x&(x+1))-1) r=r+fentree2[x];
    return r;
}

const ll inf=(1ll<<60);
vector<ll> ini(N,0);
vector<ll> mn(4*N,inf);
vector<ll> sum(4*N,0);

void recalc(int idx)
{
    mn[idx]=min(mn[2*idx],mn[2*idx+1]);
    sum[idx]=0;
    for(int i=0;i<2;i++) if(sum[2*idx+i]!=inf) sum[idx]+=sum[2*idx+i];
}

void update(int idx,int l,int r,int pos,ll val)
{
    if(l==r) mn[idx]=sum[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        recalc(idx);
    }
}

void inc(int idx,int l,int r,ll lim)
{
    if(mn[idx]>lim) return;
    if(l==r)
    {
        while(sum[idx]<=lim)
        {
            sum[idx]+=ini[l];
            mn[idx]+=ini[l];
        }
    }
    else
    {
        int m=(l+r)/2;
        inc(2*idx,l,m,lim);
        inc(2*idx+1,m+1,r,lim);
        recalc(idx);
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return sum[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<array<int,2>> v(n);
    int lim=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        ini[i]=a[i];
        lim=max(lim,a[i]);
        v[i-1]={a[i],i};
    }
    sort(v.begin(),v.end());
    vector<int> smaller(n+1,0); //number of j<i with a[j]<a[i]
    for(int i=0;i<n;i++)
    {
        int x=v[i][1];
        smaller[x]=fensum(x-1);
        fenupd(x,1);
    }
    fentree.assign(N,0);
    vector<ll> sumsmaller(n+1,0);
    for(auto [val,x]:v)
    {
        sumsmaller[x]=fensum(x-1);
        fenupd(x,val);
    }
    vector<ll> res(n+1,0);
    for(int i=0;i<n;i++)
    {
        int x=v[i][1];
//        cout << "x=" << x << endl;
//        cout << "bigger=" << x-1-smaller[x] << endl;
//        cout << "sumsmaller=" << sumsmaller[x] << endl;
        //bigger
        int bigger=x-1-smaller[x];
        res[x]+=(ll(a[x])*bigger);
        //smaller
        inc(1,1,n,a[x]);
        ll tmp=(query(1,1,n,1,x-1)-(ll(a[x])*smaller[x]));
        res[x]+=(sumsmaller[x]-tmp);
        update(1,1,n,x,a[x]);
        res[x]+=sumsmaller[x];
    }
    for(int i=1;i<=n;i++)
    {
        int l=a[i],r=2*a[i];
        while(l<=lim)
        {
            auto [s,c]=(fensum2(r-1)-fensum2(l-1));
//            if(l<=10) cout << "[i=" << i << ",a[i]=" << a[i] << ",l=" << l << ",r=" << r << "]: [" << s << "," << c << "]" << endl;
            res[i]+=(s-ll(c)*l);
            l+=a[i];
            r+=a[i];
        }
        fenupd2(a[i],{a[i],1});
    }
    for(int i=1;i<=n;i++)
    {
        res[i]+=res[i-1];
        cout << res[i] << " \n"[i==n];
    }
    return 0;
}