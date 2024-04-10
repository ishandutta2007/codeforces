#include<cstdio>
const int N=300001;
int c[N],n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	if(c[1]!=c[n])ans=n-1;
	else{
	  for(int i=1;i<=n;i++)
		if(c[i]!=c[1]&&i-1>ans)ans=i-1;
	  for(int i=1;i<=n;i++)
		if(c[i]!=c[n]&&n-i>ans)ans=n-i;
	}
	printf("%d",ans);
	return 0;
}