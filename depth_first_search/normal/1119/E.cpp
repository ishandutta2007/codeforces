#include<bits/stdc++.h>
using namespace std;
int n,a[300010];
long long num,ans,tmp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)tmp=min(num,a[i]/2ll),ans+=tmp,num-=tmp,a[i]-=tmp*2,ans+=a[i]/3,num+=a[i]%3;
	printf("%I64d",ans);
	return 0;
}