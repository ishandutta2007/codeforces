#include<cstdio>
int a,b,c,d,e;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	(a+c-1)/c+(b+d-1)/d<=e?printf("%d %d\n",(a+c-1)/c,(b+d-1)/d):puts("-1");
	}return 0;
}