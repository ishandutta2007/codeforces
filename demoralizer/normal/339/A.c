#include <stdio.h>
#include <string.h>
int main(){
	int a[3]={0,0,0};
	char s[100];
	scanf("%s",&s);
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]=='1')a[0]++;
		if(s[i]=='2')a[1]++;
		if(s[i]=='3')a[2]++;
	}
	for(int i=0;i<a[0];i++){
		if(i<(a[0]-1)||a[1]!=0||a[2]!=0)
		printf("1+");
		else printf("1");
	}
	for(int i=0;i<a[1];i++){
		if(i<(a[1]-1)||a[2]!=0)
		printf("2+");
		else printf("2");
	}
	for(int i=0;i<a[2];i++){
		if(i<(a[2]-1))
		printf("3+");
		else printf("3");
	}
}