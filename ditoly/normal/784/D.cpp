#include<cstdio>
#include<cstring>
const int f[10]={8,-1,-1,3,6,9,4,7,0,5};
char s[15];
int main()
{
	int i,l;
	scanf("%s",s);l=strlen(s)-1;
	for(i=0;i<=l;++i)if(s[l-i]-'0'!=f[s[i]-'0'])break;
	puts(i>l?"Yes":"No");
}