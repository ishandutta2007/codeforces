#include<bits/stdc++.h>
const int N=10003;
int n,a[N],ans;
signed main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	ans=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)ans+=((a[i]==0)+1)*(i)*(n-i+1);
	printf("%d\n",ans);
	}return 0;
}