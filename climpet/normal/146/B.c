#include <stdio.h>
int main(void){
	int a,i,ms=0,ms2;
	char s[10];
	scanf("%d %s",&a,s);
	for(i=0;s[i];i++){
		if(s[i]=='4'||s[i]=='7'){
			ms=ms*10+s[i]-'0';
		}
	}
	for(;;){
		sprintf(s,"%d",++a);
		ms2=0;
		for(i=0;s[i];i++){
			if(s[i]=='4'||s[i]=='7'){
				ms2=ms2*10+s[i]-'0';
			}
		}
		if(ms==ms2){
			printf("%d\n",a);return 0;
		}
	}
	return 0;
}