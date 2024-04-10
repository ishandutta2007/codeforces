#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 100010
int n,pre[MAXN],suc[MAXN],sums[MAXN],ans=1;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&sums[i]);
	pre[1]=1;suc[n]=1;
	for(int i=2;i<=n;++i)
		if(sums[i]>sums[i-1])pre[i]=pre[i-1]+1;
		else pre[i]=1;
	for(int i=n-1;i;--i)
		if(sums[i+1]>sums[i])suc[i]=suc[i+1]+1;
		else suc[i]=1;
	for(int i=1;i<=n;++i)
		if(sums[i+1]-sums[i-1]>1)ans=max(ans,pre[i-1]+suc[i+1]+1);
		else ans=max(ans,max(pre[i-1],suc[i+1])+1);
	printf("%d\n",ans);
	return 0;
}