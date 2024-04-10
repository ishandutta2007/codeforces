#include<cstdio>
const int Key[26]={0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int a,t;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&a);
	t=32-__builtin_clz(a);
	printf("%d\n",a==(1<<t)-1?Key[t]:(1<<t)-1);
	}return 0;
}