#include<cstdio>
int n,a[200001],l,r,k,t;char ans[200001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	l=1,r=n;
	for(;(a[l]>k||a[r]>k)&&l<r;){
	  if(a[l]>k&&a[r]<k||a[l]>k&&a[r]>k&&a[l]<a[r])ans[t++]='L',k=a[l++];
	  if(a[r]>k&&a[l]<k||a[l]>k&&a[r]>k&&a[r]<a[l])ans[t++]='R',k=a[r--];
	}if(l==r&&a[l]>k)ans[t++]='R';
	printf("%d\n%s",t,ans);
	return 0;
}