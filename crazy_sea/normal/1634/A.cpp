#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[110];
int n,k,T;
bool check()
{
	for(int i=1;i<=n;i++)
		if(s[i]!=s[n-i+1]) return false;
	return true;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%s",&n,&k,s+1);
		if(k==0||check()) printf("1\n");
		else printf("2\n");
	}
	return 0;
}