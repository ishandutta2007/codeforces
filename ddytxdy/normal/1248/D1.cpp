#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50;
int n,a[N],mn,ans,l,r,ll,rr,b[N],s1[N],s2[N],s3[N],tot,dat;char s[N];
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)a[i]=a[i-1]+(s[i]=='('?1:-1),mn=min(mn,a[i]);
	for(int i=1;i<=n;i++)s1[i]=s1[i-1]+(a[i]==mn),s2[i]=s2[i-1]+(a[i]==mn+1),s3[i]=s3[i-1]+(a[i]==mn+2);
	if(a[n])puts("0\n1 1"),exit(0);ans=s1[n];l=1,r=1;
	for(int i=1;i<=n;i++)if(a[i]==mn)b[++tot]=i;
	for(int i=n;i;i--)if(s[i]==')'){if(i>b[tot])b[++tot]=i;break;}
	for(int i=1;i<=n;i++)if(s[i]=='('){if(i-1<b[1])b[0]=i-1;else b[0]=b[1]-1;break;}
	for(int i=0;i<tot;i++)if(b[i]+1!=b[i+1])
		if((dat=s2[rr=b[i+1]-1]-s2[ll=b[i]])>ans)ans=dat,l=ll+1,r=rr+1;
	tot=0;for(int i=1;i<=n;i++)if(a[i]<mn+2)b[++tot]=i;
	for(int i=n;i;i--)if(s[i]==')'){if(i>b[tot])b[++tot]=i;break;}
	for(int i=1;i<=n;i++)if(s[i]=='('){if(i-1<b[1])b[0]=i-1;else b[0]=b[1]-1;break;}
	for(int i=0;i<tot;i++)if(b[i]+1!=b[i+1])
		if((dat=s1[n]+s3[rr=b[i+1]-1]-s3[ll=b[i]])>ans)ans=dat,l=ll+1,r=rr+1;
	if(mn){
		ll=rr=0;for(int i=1;i<=n;i++)if(a[i]==mn){rr=i;if(!ll)ll=i;}
		if((dat=s2[ll-1]+s2[n]-s2[rr])>ans)ans=dat,l=ll,r=rr+1;
	}
	if(mn<-1){
		ll=rr=0;for(int i=1;i<=n;i++)if(a[i]<mn+2){rr=i;if(!ll)ll=i;}
		if((dat=s3[ll-1]+s3[n]-s3[rr]+s1[n])>ans)ans=dat,l=ll,r=rr+1;
	}
	printf("%d\n%d %d\n",ans,l,r);
	return 0;
}