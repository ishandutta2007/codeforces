#include<cstdio>

int main()
{
//while(1)
{
int i,j,k,c,n,a[1005];
scanf("%d",&n);

for(i=1;i<=n;i++)
scanf("%d",&a[i]);

for(i=1;i<=n;i++)
if(i!=a[i]) {c=j=i;break;}

if(i==n+1) {printf("0 0\n");return 0;}

for(i=n;i>=1;i--)
if(i!=a[i]) {k=i;break;}

for(i=k;i>=j;i--)
if(a[i]!=c++) break;

if(i==j-1) printf("%d %d\n",j,k);
else printf("0 0\n");
}

return 0;
}