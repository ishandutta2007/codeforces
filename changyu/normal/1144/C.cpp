#include<cstdio>
const int N=2e5+1;
int n,a[N],b[N],ans1[N],k1,ans2[N],k2;
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),b[a[i]]++;
	for(int j=0;j<N;j++)
	  if(b[j])ans1[++k1]=j,b[j]--;
	for(int j=0;j<N;j++){
	  if(b[j])ans2[++k2]=j,b[j]--;
	  if(b[j])return 0*puts("NO");
	}puts("YES");
	printf("%d\n",k1);
	for(int i=1;i<=k1;i++)printf("%d ",ans1[i]);puts("");
	printf("%d\n",k2);
	for(int i=k2;i;i--)printf("%d ",ans2[i]);puts("");
	return 0;
}