#include<bits/stdc++.h>
const int N=10003;
int n,a[N],ans;
signed main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	ans=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i),i>1&&a[i]<a[i-1]&&(ans=1);
	puts(ans?"YES":"NO");
	}
	return 0;
}