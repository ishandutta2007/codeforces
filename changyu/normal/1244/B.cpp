#include<cstdio>
inline int max(int a,int b){return a>b?a:b;}
const int N=1003;
int n,ans,l,r;char a[N];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%s",&n,a+1);
	ans=n;l=r=0;
	for(int i=1;i<=n;i++)if(a[i]=='1'){
	  ans=max(ans,max(n+1,max(i,n-i+1)*2));
	  l=l?l:i,r=i;
	}
	if(l)ans=max(ans,2*(r-l+1)+max(l-1,n-r));
	printf("%d\n",ans);
	}return 0;
}