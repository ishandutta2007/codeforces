#include<cstdio>
const int N=1001;
int b[N],n,m,a[N],k,c;
int main(){
	scanf("%d%d",&n,&m);k=n+1>>1;
	for(int i=1;i<=n;i++)scanf("%d",a+i),b[a[i]]++;
	for(int j=1;j<=m;j++){
	  for(;b[j]>=2;b[j]-=2)k--;
	  if(b[j])c++;
	}
	printf("%d",n-(c-k>0?c-k:0));
	return 0;
}