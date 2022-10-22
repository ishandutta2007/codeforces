#include<cstdio>
#include<algorithm>
int n,a[101],used[101],ans;
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)if(!used[i]){
	  for(int j=i;j<=n;j++)if(a[j]%a[i]==0)used[j]=1;
	  ans++;
	}printf("%d",ans);
	return 0;
}