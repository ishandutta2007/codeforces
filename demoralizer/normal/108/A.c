#include <stdio.h>
#include <string.h>
int main(){
	int h,m;
	scanf("%d:%d",&h,&m);
	while(1){
		m++;
		if(m==60){m=0;h=(h+1)%24;}
		if((m%10==h/10)&&(h%10==m/10)){
			printf("%02d:%02d",h,m);
			return 0;
		}
	}
}