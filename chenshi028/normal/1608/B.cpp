#include<cstdio>
using namespace std;
int T,n,a,b;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&n,&a,&b);
		if(a+b>n-2||a>b+1||b>a+1){printf("-1\n");continue;}
		if(a==b+1){
			printf("1 ");
			for(int i=1;i<a;++i) printf("%d %d ",n-i+1,i+1);
			for(int i=a+2;i<=n-b;++i) printf("%d ",i);
			printf("%d\n",a+1);
		}
		else if(a==b-1){
			printf("%d ",n);
			for(int i=1;i<b;++i) printf("%d %d ",i,n-i);
			for(int i=b+2;i<=n-a;++i) printf("%d ",n-i+1);
			printf("%d\n",n-b);
		}
		else{
			printf("1 ");
			for(int i=1;i<=a;++i) printf("%d %d ",n-i+1,i+1);
			for(int i=a+2;i<=n-a;++i) printf("%d ",i);
			putchar('\n');
		}
	}
	return 0;
}