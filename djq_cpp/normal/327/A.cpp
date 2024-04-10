#include <cstdio>
#define max(a,b) (a>b?a:b)
int pls1[105];
char in[105];
int main(){
	int n,ans,s1=0;
	scanf("%d",&n);
	getchar();
	for(int k=1;k<=n;k++){
		in[k]=getchar();getchar();
		if(in[k]=='1')s1++;
		pls1[k]=max(pls1[k-1],0)+(in[k]=='1'?-1:1);
	}
	ans=-s1;
	for(int k=1;k<=n;k++)
	if(ans<pls1[k])ans=pls1[k];
	printf("%d",ans+s1);
	return 0;
}