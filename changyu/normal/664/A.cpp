#include<cstdio>
#include<cstring>
char a[137],b[137];
int main(){
	scanf("%s%s",a,b);
	puts(strcmp(a,b)?"1":a);
	return 0;
}