#include<cstdio>
#include<algorithm>
const int N=1e5+8;
int n,x,y,a[N];
int main(){
	int f;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++){
	  f=1;
	  for(int j=std::max(1,i-x);j<=std::min(n,i+y);j++)
		if(j!=i&&a[j]<=a[i])f=0;
	  if(f)return 0*printf("%d",i);
	}
}