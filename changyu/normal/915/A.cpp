#include<cstdio>
int n,m,a,mx;
int main(){
	scanf("%d%d",&n,&m);
	while(n--){scanf("%d",&a);if(m%a==0&&a>mx)mx=a;}
	printf("%d",m/mx);
}