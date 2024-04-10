#include <bits/stdc++.h>
using namespace std;
int n,K,ans[100004];
int lowb(int x){return x&-x;}
int main(){
	scanf("%d%d",&n,&K);
	if(n%2==0)return puts("NO"),0;
	if(max(0,(n-3)/2)<K)return puts("NO"),0;
	if(n==9&&K==2)return puts("NO"),0;
	if(lowb(n+1)==n+1&&K==1)return puts("NO"),0;
	if(lowb(n+1)!=n+1&&K<1)return puts("NO"),0;
	puts("YES");
	int base=2*max(0,K-1);
	for(int i=1;i<base;i+=2)ans[i]=max(0,i-2),ans[i+1]=i;
	for(int i=1;i<=n-base;i++){
		if(i==1)ans[i+base]=max(0,base-1);
		else ans[i+base]=i/2+base;
	}
	if(lowb(n-base+1)==n-base+1&&K)ans[n-1]=ans[n]=2;
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}