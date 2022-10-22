#include<cstdio>
int a;
int main(){
	int T;scanf("%d",&T);while(T--){
	scanf("%d",&a);
	puts(360%(180-a)?"NO":"YES");
	}return 0;
}