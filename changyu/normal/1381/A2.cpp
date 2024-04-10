#include<cstdio>
const int N=1e5+3;
int n,f,l,r,ans[N+N],k;char a[N],b[N];
inline char A(int i){return a[f?r-i+1:l+i-1]^f;}
inline void Flip1(){a[f?r:l]^=1;}
inline void Flip(int k){
	if(f)l=r-k+1,f=0;
	else r=l+k-1,f=1;
}
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%s%s",&n,a+1,b+1);
	f=0,l=1,r=n,k=0;
	for(int i=n;i;i--)if(A(i)!=b[i]){
	  if(A(1)==b[i])Flip1(),ans[++k]=1;
	  Flip(i),ans[++k]=i;
	}
	printf("%d",k);for(int i=1;i<=k;i++)printf(" %d",ans[i]);puts("");
	}return 0;
}