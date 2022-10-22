#include<bits/stdc++.h>
const int N=2e5+3;
int n,a[N],b[N],ans;
signed main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	ans=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i),++b[a[i]];
	for(int i=n+n,s=0,c=0;i;i--){
	  if(b[i]){
		s+=b[i],++c;
		if(!b[i-1])ans+=c+(s>c);
	  }
	  else s=0,c=0;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)--b[a[i]];
	}return 0;
}