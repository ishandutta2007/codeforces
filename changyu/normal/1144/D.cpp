#include<cstdio>
const int N=2e5+1;
int n,a[N],b[N],x,xa,p;
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	  scanf("%d",a+i);b[a[i]]++;
	  if(b[a[i]]>x)x=b[a[i]],xa=a[i];
	}
	for(int i=1;i<=n;i++)if(a[i]==xa){p=i;break;}
	printf("%d\n",n-x);
	for(int i=p+1;i<=n;i++)if(a[i]!=xa)printf("%d %d %d\n",a[i]<a[i-1]?1:2,i,i-1),a[i]=a[i-1];
	for(int i=p-1;i;i--)printf("%d %d %d\n",a[i]<a[i+1]?1:2,i,i+1),a[i]=a[i+1];
	return 0;
}