#include<cstdio>
#include<cstring>
int T,l;char a[100];
int main(){ 
	scanf("%d",&T);while(T--){
	scanf("%s",a);l=strlen(a);
	if(l<=10)printf("%s\n",a);else printf("%c%d%c\n",a[0],l-2,a[l-1]);
	}return 0;
}