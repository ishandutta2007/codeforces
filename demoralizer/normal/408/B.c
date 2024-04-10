#include <stdio.h>
int c[26],d[26],e=0;
int main(){
	char a[1002],b[1002];
	scanf("%s\n%s",a,b);
	for(int i=0;i<strlen(a);i++)
		c[a[i]-'a']++;
	for(int i=0;i<strlen(b);i++)
		d[b[i]-'a']++;
	for(int i=0;i<26;i++)
		if(d[i]==0)continue;
		else if(c[i]==0)goto no;
		else e+=(c[i]>d[i])?d[i]:c[i];
	printf("%d",e);
	return 0;
	no: printf("-1");
}