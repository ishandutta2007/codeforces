#include <stdio.h>
#include <string.h>
int main(){/*
	char s[1000];
	gets(s);
	int n=strlen(s)*/
	int c=0;char s;
	int a[26];
	for(int i=0;i<26;i++)
	a[i]=0;
	for(int i=0;i<1000;i++){
	scanf("%c",&s);
	if(s>='a'&&s<='z')
	a[(s-'a')]=1;
	if(s=='}')break;
	}
	for(int i=0;i<26;i++)
	if(a[i])c++;
	printf("%d",c);
}