#include<cstdio>
int a,c;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&a);
	c=0;
	for(;a;a&=a-1)c++;
	printf("%d\n",1<<c);
	}return 0;
}