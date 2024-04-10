#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
#define MAXN 200010
int n,k,sums[MAXN],pre[MAXN],ans,st;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&sums[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&st);
		pre[i]=pre[i-1];
		if(st)ans+=sums[i];
		else pre[i]+=sums[i];
	}
	st=-1;
	for(int i=1;i<=n-k+1;++i)
		st=max(pre[i+k-1]-pre[i-1],st);
	printf("%d\n",st+ans);
	return 0;
}