#include<cstdio>
#define max(a,b)a>b?a:b
int n,a[100000],ans=1;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=1,j=0;i<n;i++){
	  if(a[i]<a[i-1])j=i;
	  ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}