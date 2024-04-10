#include <stdio.h>
#include <string.h>
int main(){
	char s[200];
	scanf("%s",s);
	int n=strlen(s),a=0,b=0;
	for(int i=0;i<n;i++){	if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B'){
		a=1;
		i+=2;
	}
	else{
		if(a&&b)printf(" ");
		b=1;a=0;
		printf("%c",s[i]);
	}
	}
}