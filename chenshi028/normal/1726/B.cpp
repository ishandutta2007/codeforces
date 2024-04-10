#include<cstdio>
using namespace std;
int T,n,m;
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d%d",&n,&m);
		if(n>m){printf("No");continue;}
		if(m%n==0){printf("Yes\n");for(int i=1;i<=n;++i) printf("%d ",m/n);continue;}
		if(n%2){
			printf("Yes\n");
			for(int i=1;i<n;++i) printf("1 "),--m;
			printf("%d",m);
			continue;
		}
		if(m%2){printf("No\n");continue;}
		printf("Yes\n");n/=2;m/=2;
		for(int i=1;i<n;++i) printf("1 1 ");
		printf("%d %d",m-n+1,m-n+1);
	}
	return 0;
}