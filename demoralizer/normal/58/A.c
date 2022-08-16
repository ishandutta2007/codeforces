#include <stdio.h>
#include <string.h>
int main(){
	char s[100];
	scanf("%s",s);
	int n=strlen(s),c=0;
	for(int i=0;i<n;i++){
		if(c==0&&s[i]=='h')c++;
		if(c==1&&s[i]=='e')c++;
		if(c==2&&s[i]=='l'){c++;continue;}
		if(c==3&&s[i]=='l')c++;
		if(c==4&&s[i]=='o')c++;
		if(c==5){printf("YES");return 0;}
	}
	printf("NO");
}