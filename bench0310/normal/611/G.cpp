#include <bits/stdc++.h>

using namespace std;

typedef array<long long,2> point;
const long long mod=1000000007;
const int N=500005;
int n;
vector<point> v(N);

long long cross(int a,int b)
{
    return (v[a][0]*v[b][1]-v[b][0]*v[a][1])%mod;
}

long long crossx(int a,int b)
{
    return (v[a][0]*v[b][1]-v[b][0]*v[a][1]);
}

vector<long long> sum(N,0);
vector<long long> sumx(N,0);
vector<long long> sumy(N,0);

int mv(int idx)
{
    idx=((idx%n)+n)%n;
    if(idx==0) idx=n;
    return idx;
}

long long q(int l,int r)
{
    if(l<=r) return (sum[r]%mod-sum[l-1]%mod)%mod;
    else return (sum[n]%mod-sum[l-1]%mod+sum[r]%mod)%mod;
}

long long qx(int l,int r)
{
    if(l<=r) return (sum[r]-sum[l-1]);
    else return (sum[n]-sum[l-1]+sum[r]);
}

long long sx(int l,int r)
{
    if(l<=r) return (sumx[r]-sumx[l-1])%mod;
    else return (sumx[n]-sumx[l-1]+sumx[r])%mod;
}

long long sy(int l,int r)
{
    if(l<=r) return (sumy[r]-sumy[l-1])%mod;
    else return (sumy[n]-sumy[l-1]+sumy[r])%mod;
}

long long cross_sum_from(int idx,int l,int r)
{
    long long res=0;
    res=(res+v[idx][0]*sy(l,r))%mod;
    res=(res-v[idx][1]*sx(l,r))%mod;
    return res;
}

long long cross_sum_to(int idx,int l,int r)
{
    return -cross_sum_from(idx,l,r);
}

long long f(int i,int m)
{
    return (sum[n]%mod-2*q(i,mv(m-1))-2*cross(m,i))%mod;
}

int main()
{
    scanf("%d",&n);
    for(int i=n;i>=1;i--) scanf("%I64d%I64d",&v[i][0],&v[i][1]);
    for(int i=1;i<=n;i++)
    {
        sumx[i]=(sumx[i-1]+v[i][0])%mod;
        sumy[i]=(sumy[i-1]+v[i][1])%mod;
        sum[i]=(sum[i-1]+crossx(i,mv(i+1)));
    }
    long long area=sum[n]%mod;
    long long res=0;
    int m=1;
    long long l=0;
    long long r=0;
    for(int i=2;i<=n;i++) r=(r+f(1,i))%mod;
    for(int i=1;i<=n;i++)
    {
        while(m!=mv(i-2)&&(qx(i,m)+crossx(mv(m+1),i))<=sum[n]-(qx(i,m)+crossx(mv(m+1),i)))
        {
            m=mv(m+1);
            l=(l+f(i,m))%mod;
            r=(r-f(i,m))%mod;
        }
        res=(res+l-r-2*area)%mod;
        if(m==mv(i+1))
        {
            m=mv(m+1);
            l=(l+f(i,m))%mod;
            r=(r-f(i,m))%mod;
        }
        l=(l+2*cross(i,mv(i+1))*mv(m-(i+1)+1))%mod;
        l=(l+2*cross_sum_to(i,mv(i+1),m))%mod;
        l=(l-2*cross_sum_to(mv(i+1),mv(i+2),m))%mod;
        l=(l-area)%mod;
        r=(r+2*cross(i,mv(i+1))*mv((i-1)-(m+1)+1))%mod;
        r=(r+2*cross_sum_to(i,mv(m+1),mv(i-1)))%mod;
        r=(r-2*cross_sum_to(mv(i+1),mv(m+1),i))%mod;
        r=(r-2*q(mv(i+1),mv(i-1)))%mod;
        r=(r+area)%mod;
    }
    res=(res+mod)%mod;
    res=(res*500000004)%mod;
    printf("%I64d\n",res);
    return 0;
}