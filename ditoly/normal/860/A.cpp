#include<cstdio>
#define MN 3000
char s[MN+5];
int u[MN+5];
bool check(char c)
{
	return c>='a'&&c<='z'&&c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u';
}
int main()
{
	scanf("%s",s+1);
	for(int i=1;s[i];++i)
		if(check(s[i])&&check(s[i+1])&&check(s[i+2])
			&&(s[i]!=s[i+1]||s[i]!=s[i+2]||s[i+1]!=s[i+2]))u[++i]=1;
	for(int i=1;s[i];++i)putchar(s[i]),u[i]?putchar(' '):0;
}