#include <stdio.h>
#include <string.h>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,s=-1,e=-1;
	scanf("%d\n",&n);
	char c;
	for(int i=1;e==-1;i++){
		scanf("%c",&c);
		if(s==-1){
			if(c!='.')s=i;
		}
		else if(c=='.')e=i;
		if(c=='L')e=i-1;
	}
	printf("%d %d",s,e);
}