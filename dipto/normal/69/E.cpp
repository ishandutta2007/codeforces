#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
#define INF 2000000000
#define FOR(i,x,n) for(int i=x;i<=n;i++)
#define REV(i,x,n) for(int i=x;i>=n;i--)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define LL long long
#define test int T;scanf("%d",&T);while(T--)
#define pb push_back
#define b() begin()
#define e() end()
#define s() size()
#define cl() clear()
#define S 1000000

int m[S],f[S],a[S],b[S],flag;
void update(int l,int r,int x,int n)
{
if(l==r)
        {
        f[n]+=flag;
        if(f[n]==1)
        m[n]=x;
        else
        m[n]=-INF;
        return;

}

int mid=(l+r)/2;

if(x<=mid) update(l,mid,x,2*n);
else update(mid+1,r,x,2*n+1);

m[n]=-INF;
if(f[2*n]==1) m[n]=max(m[n],m[2*n]);
if(f[2*n+1]==1) m[n]=max(m[n],m[2*n+1]);

f[n]=1;

}


int main()
{
map<int,int> index;
index.clear();
int N,K;

si(N);si(K);
FOR(i,0,N-1)
{si(a[i]);
b[i]=a[i];}

sort(b,b+N);
FOR(i,0,N-1)
if(index[b[i]]==0)
index[b[i]]=i+1;

FOR(i,0,K-1)
{flag=1;
update(1,N,index[a[i]],1);}

if(m[1]==-INF) printf("Nothing\n");
else printf("%d\n",b[m[1]-1]);

FOR(i,K,N-1)
{
flag=1;
update(1,N,index[a[i]],1);
flag=-1;
update(1,N,index[a[i-K]],1);

if(m[1]==-INF) printf("Nothing\n");
else printf("%d\n",b[m[1]-1]);

}

//cin>>K;
return 0;
}