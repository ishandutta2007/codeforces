#include <stdio.h>
#include <string.h>
int main(){
	char s[100];
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]<96)s[i]+=32;
		switch(s[i]){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'y':
			continue;
		}
		printf(".%c",s[i]);
	}
}