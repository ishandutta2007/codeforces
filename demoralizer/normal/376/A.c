#include <stdio.h>
#include <string.h>
int main(){
	char c;long long int p,w=0,t=0,i;
	for(i=0;scanf("%c",&c)>0;i++){
		if(c=='^')p=i;
		if(c>='1'&&c<='9'){
			w+=c-'0';
			t+=(c-'0')*i;
		}
	}
	t-=w*p;
	if(t>0)printf("right");
	else if(t) printf("left");
	else printf("balance");
}