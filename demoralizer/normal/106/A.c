#include <stdio.h>
#include <string.h>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	char a,b,c,d,e;int k=0;
scanf("%c\n%c%c %c%c",&a,&b,&c,&d,&e);
	if(b=='A')b='Z';
	if(b=='T')b='A';
	if(b=='K')b='Y';
	if(d=='A')d='Z';
	if(d=='T')d='A';
	if(d=='K')d='Y';
	if((a==c)&&(a!=e)) k=1;
	if((c==e)&&(b>d))k=1;
	
	printf(k?"YES":"NO");
}