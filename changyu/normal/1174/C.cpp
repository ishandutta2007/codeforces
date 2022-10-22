#include<cstdio>
const int N=1e5+3;
int n,ans[N],mx;
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
	  ans[i]=mx+1;
	  for(int j=2;j*j<=i;j++)
		if(i%j==0){ans[i]=ans[j];break;}
	  mx=ans[i]>mx?ans[i]:mx;
	  printf("%d ",ans[i]);
	}
	return 0;
}