#include<cstdio>
const int N=1003,P[11]={2,3,5,7,11,13,17,19,23,29,31};
int n,a[N],t,r[N];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),r[i]=0;
	t=0;
	for(int k=0,f;k<11;k++){
	  f=0;
	  for(int i=1;i<=n;i++)if(!r[i]&&a[i]%P[k]==0)
		r[i]=f?t:(f=1,++t);
	}
	printf("%d\n",t);
	for(int i=1;i<=n;i++)printf("%d ",r[i]);puts("");
	}return 0;
}