#include<cstdio>
#include<cstring>
char a[102];int l,s;
int main(){
	scanf("%s",a+1);l=strlen(a+1);
	if(a[1]==0)return 0*puts("0");
	for(int i=1;i<=l;i++)s+=a[i]=='1';
	printf("%d",(l+(s>1))/2);
	return 0;
}