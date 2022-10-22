#include<cstdio>
#include<cstring>
const int N=101;
int n,a[N],b[N],ans,sum;char T[102],s[102];
int main(){
	scanf("%d%s",&n,T+1);
	memcpy(s,T,sizeof s);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",a+i,b+i);
	for(int i=1;i<=n;i++)ans+=s[i]-48;
	for(int j=1;j<=1000000;j++){
	  sum=0;
	  for(int i=1;i<=n;i++)s[i]^=j%a[i]==b[i]%a[i]&&j>=b[i],sum+=s[i]-48;
	  if(sum>ans)ans=sum;
	}printf("%d",ans);
	return 0;
}