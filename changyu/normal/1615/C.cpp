#include<bits/stdc++.h>
const int N=1e5+3;
int n,c,ca,cb,ans;
char a[N],b[N];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%s%s",&n,a+1,b+1);
	c=ca=cb=0;
	for(int i=1;i<=n;i++)c+=(a[i]!=b[i]),ca+=a[i]=='1',cb+=b[i]=='1';
	ans=n+1;
	if(ca==cb){
		ans=std::min(ans,c);
	}
	if(ca+cb==n+1){
		ans=std::min(ans,n-c);
	}
	printf("%d\n",ans==n+1?-1:ans);
	}return 0;
}