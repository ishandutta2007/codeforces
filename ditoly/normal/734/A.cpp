#include<cstdio>
char s[100005];
int main()
{
	int n,i,a=0,b=0;
	scanf("%d%s",&n,s);
	for(i=0;i<n;i++)if(s[i]=='A')a++;else b++;
	if(a>b)puts("Anton");else puts(a<b?"Danik":"Friendship");
}