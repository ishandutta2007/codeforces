
#include<cstdio>
#define N1 78
#define INF 2000000000
#define FOR(i,x,n) for(int i=x;i<=n;i++)
#define REV(i,x,n) for(int i=x;i>=n;i--)
#define si(x) scanf("%d",&x)
int a[2000],L[2000],R[2000];
int main()
{
int n;
si(n);
FOR(i,1,n)
si(a[i]);

a[0]=0;a[n+1]=0;
FOR(i,1,n)
{
if(a[i]>=a[i-1])
L[i]=L[i-1]+1;
else
L[i]=1;
}
REV(i,n,1)
{
if(a[i]>=a[i+1])
R[i]=R[i+1]+1;
else
R[i]=1;
}

int max=-1;

FOR(i,1,n)
if(L[i]+R[i]-1>max)
max=L[i]+R[i]-1;

printf("%d",max);

return 0;
}