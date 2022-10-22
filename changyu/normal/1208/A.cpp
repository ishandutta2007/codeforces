#include<cstdio>
int a,b,n;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d%d",&a,&b,&n);
	printf("%d\n",n%3==0?a:(n%3==1?b:a^b));
	}return 0;
}