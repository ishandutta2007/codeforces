#include<cstdio>
int n,ans;
int main(){
	scanf("%d",&n);printf("%d\n",ans=n/2+1);
	for(int i=1;i<=n-ans;i++)printf("%d %d\n",1,i);
	for(int i=1;i<=ans;i++)printf("%d %d\n",ans,i);
	return 0;
}