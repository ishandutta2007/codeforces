#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50;
int n,a[N],mn,ans,l,r,x,y,b[N],s1[N],s2[N],s3[N],tot,dat;char s[N];
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)a[i]=a[i-1]+(s[i]=='('?1:-1),mn=min(mn,a[i]);
	for(int i=1;i<=n;i++)s1[i]=s1[i-1]+(a[i]==mn),s2[i]=s2[i-1]+(a[i]==mn+1),s3[i]=s3[i-1]+(a[i]==mn+2);
	if(a[n])puts("0\n1 1"),exit(0);ans=s1[n];l=1,r=1;
	b[tot=1]=0;for(int i=1;i<=n;i++)if(a[i]==mn)b[++tot]=i;b[++tot]=n;
	for(int i=1;i<tot;i++)if((dat=s2[y=b[i+1]-1]-s2[x=b[i]])>ans)ans=dat,l=x+1,r=y+1;
	b[tot=1]=0;for(int i=1;i<=n;i++)if(a[i]<mn+2)b[++tot]=i;b[++tot]=n;
	for(int i=1;i<tot;i++)if((dat=s1[n]+s3[y=b[i+1]-1]-s3[x=b[i]])>ans)ans=dat,l=x+1,r=y+1;
	x=y=0;for(int i=1;i<=n;i++)if(a[i]==mn){y=i;if(!x)x=i;}
	if(y!=n&&(dat=s2[x-1]+s2[n]-s2[y])>ans)ans=dat,l=x,r=y+1;
	x=y=0;for(int i=1;i<=n;i++)if(a[i]<mn+2){y=i;if(!x)x=i;}
	if(y!=n&&(dat=s3[x-1]+s3[n]-s3[y]+s1[n])>ans)ans=dat,l=x,r=y+1;
	printf("%d\n%d %d\n",ans,l,r);
	return 0;
}