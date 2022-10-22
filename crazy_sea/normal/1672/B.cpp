#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,T,s;
char str[1000010];
bool chk()
{
	s=0;
	if(n==1||str[n-1]=='A') return 0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='A') s++;
		else s--;
		if(s<0) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);
		n=strlen(str);
		printf("%s\n",chk()?"Yes":"No");
	}
}