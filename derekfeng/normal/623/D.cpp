#include<bits/stdc++.h>
using namespace std;
typedef double db;
int n,p[103],c[103];
db pc[103],ps[103],fg=1,ans;
int main(){
	scanf("%d",&n),ans=n;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),pc[i]=(db)(100-p[i])/100;
	for(int i=1;i<=n;i++)c[i]=1,ps[i]=pc[i],fg*=(1-pc[i]);
	ans+=1-fg;
	for(int T=1;T<=3e5;T++){
		db res=0;int pos;
		for(int i=1;i<=n;i++){
			db mpro=1-ps[i]*pc[i],pro=1-ps[i];
			if(mpro/pro>res)res=mpro/pro,pos=i;
		}
		c[pos]++,ps[pos]=ps[pos]*pc[pos];
		fg*=res;
		if(fg>1)break;
		ans+=1-fg;
	}
	printf("%.10lf",ans);
}