#include<cstdio>
#include<algorithm>
const int N=2e5+1;
int a[N],b[N],t[N],n,m,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),t[i]=a[i];
	std::sort(t+1,t+1+n);
	for(int i=1;i<=n;i++)if(t[i]!=t[i-1])t[++m]=t[i];
	for(int i=1;i<=n;i++)b[std::lower_bound(t+1,t+1+m,a[i])-t]++;
	std::sort(b+1,b+1+m);
	for(int i=1;i<=n;i++)
	  for(int j=i,k=0;;j*=2){
		int tmp=std::lower_bound(b+k+1,b+m+1,j)-b;
		if(tmp>m){ans=std::max(ans,j-i);break;}
		k=tmp;
	  }
	printf("%d",ans);
	return 0;
}