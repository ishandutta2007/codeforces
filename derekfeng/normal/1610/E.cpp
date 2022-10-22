#include<bits/stdc++.h>
using namespace std;
int n,T,a[200005];
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<=n;i++)if(i==1||a[i]!=a[i-1]){
		int fi=a[i],se=a[i],tmp=1,cur=i;
		for(;;){
			int pos=lower_bound(a+cur+1,a+n+1,2*se-fi)-a;
			if(pos>n)break;
			tmp++,se=a[pos],cur=pos;
		}
		ans=max(ans,tmp);
	}
	printf("%d\n",n-ans);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}