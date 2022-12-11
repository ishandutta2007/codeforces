#include <stdio.h>
#include <string.h>
char str[1010];
int n,len;
int main(){
	scanf("%d",&n);
	gets(str);
	for(int i=1;i<=n;i++){
		gets(str);
		len=strlen(str);
		if(len>10)printf("%c%d%c\n",str[0],len-2,str[len-1]);
		else puts(str);
	}
	return 0;
}