#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
namespace ZBK{
const int N=2e5+50;
int k1,k2,k3,p[N],n,d1,d2,mn,ans=1e9;
void main(){
	scanf("%d%d%d",&k1,&k2,&k3);n=k1+k2+k3;
	for(int i=1,x;i<=k1;i++)scanf("%d",&x),p[x]=1;
	for(int i=1,x;i<=k2;i++)scanf("%d",&x),p[x]=2;
	for(int i=1,x;i<=k3;i++)scanf("%d",&x),p[x]=3,d1++;
	d1=n-d1;ans=min(ans,d1+mn);
	for(int i=1;i<=n;i++){
		if(p[i]==1)d2--;
		if(p[i]==2)d1--,d2++;
		if(p[i]==3)d1++;
		mn=min(mn,d2);
		ans=min(ans,d1+mn);
	}
	printf("%d\n",ans);
}
}
int main(){ZBK::main();return 0;}