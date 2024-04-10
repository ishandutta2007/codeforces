#include<bits/stdc++.h>
using namespace std;
const int N=4e5+50;
int n,m,a[N],b[N],c[N],cnt,k[N],s[N],kk,ans=1e9;
int main(){
	scanf("%d%d",&n,&m);m*=8;
	for(int i=1,j=0;i<=n;i++){
		if((1<<j)<i)j++;
		k[i]=j;
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);a[0]=-1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])b[++cnt]=a[i];
		c[cnt]++;
	}
	for(int i=1;i<=cnt;i++)s[i]=s[i-1]+c[i];
	for(kk=cnt;kk;kk--)if(k[kk]*n<=m)break;
	for(int i=1,j=kk;j<=n;i++,j++)ans=min(ans,n-(s[j]-s[i-1]));
	printf("%d\n",ans);
	return 0;
}