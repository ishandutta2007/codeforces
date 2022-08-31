#include <stdio.h>
#include <string.h>
int main(){
	char c,t;
	while(scanf("%c",&t)>0)
		if(t>='a'&&t<='z')c=t;
	else if(t>='A'&&t<='Z')c=t+32;
	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
		printf("YES");break;
		default:
		printf("NO");
	}
}