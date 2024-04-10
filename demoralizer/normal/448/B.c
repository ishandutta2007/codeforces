#include <stdio.h>
#include <string.h>
int c[26],d[26],x=0,y=0;
int main()
{
	char a[102],b[102];
	scanf("%s\n%s",a,b);
	for(int i=0;i<strlen(a);i++) c[a[i]-'a']++;
	for(int i=0;i<strlen(b);i++) d[b[i]-'a']++;
	for(int i=0;i<26;i++)
		if(c[i]<d[i])goto fail;
		else if(c[i]>d[i]) x=1;
	for(int i=0;i<strlen(a);i++)
		if(a[i]==b[y])y++;
	if(x){
		if(y==strlen(b)) printf("automaton");
		else printf("both");
	}
	else printf("array");
	return 0;
	fail:
	printf("need tree");
}