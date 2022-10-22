#include<cstdio>
char s[3],t[3];
int main()
{
	scanf("%s",s);
	for(int i=1;i<=5;i++){
	  scanf("%s",t);
	  if(s[0]==t[0]||s[1]==t[1])return 0*puts("YES");
	}puts("NO");
	return 0; 
}