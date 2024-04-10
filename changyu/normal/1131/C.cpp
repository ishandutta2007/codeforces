#include<cstdio>
#include<algorithm>
const int N=101,INF=0x3fffffff;
int n,a[N],f[N];
inline bool Check(int g)
{
	if(a[n]-a[1]<=g)return 1;
	for(int i=1,j=1,k;i<=n;i++)if(a[i]>=a[1]+g){
	  if(a[i]!=a[i-1])k=i;
	  for(;a[j]<a[i]-g;)j++;
	  if(k-j<2)return 0;
	}return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	if(n==1)return 0*printf("%d",a[1]);
	std::sort(a+1,a+1+n);
	int l=0,r=INF,m;
	for(;l<r;)m=l+r>>1,Check(m)?r=m:l=m+1;
	f[1]=1;
	for(int i=2,j=1;i<n;i++)
	  if(a[j]<a[i+1]-l)f[i]=1,j=i;
	for(int i=1;i<=n;i++)if(f[i])printf("%d ",a[i]);
	for(int i=n;i;i--)if(!f[i])printf("%d ",a[i]);
	return 0;
}