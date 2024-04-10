#include<cstdio>
#include<cstring>
char a[100001];int f,c,c1,p;
int main(){
	scanf("%s",a);
	p=strlen(a)+1;
	for(int i=0;a[i];i++){
	  if(!f&&a[i]==48)c++;
	  if(a[i]==50&&!f)f=1,p=i;
	  if(a[i]==49)c1++;
	}
	for(;c--;)putchar(48);
	for(;c1--;)putchar(49);
	for(int i=p;a[i];i++)if(a[i]!=49)putchar(a[i]);
	return 0;
}