#include<cstdio>
char a[12];int s=1;
int main(){
	scanf("%s",a);
	for(int i=0;a[i];i++)s=s+s+(a[i]>54);
	printf("%d",s-1);
	return 0;
}