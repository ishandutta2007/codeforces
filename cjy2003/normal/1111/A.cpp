#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[1010],b[1010];
int la,lb;
bool check(char *f,int x)
{
	return f[x]=='a'||f[x]=='e'||f[x]=='i'||f[x]=='o'||f[x]=='u';
}
int main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	la=strlen(a+1);
	lb=strlen(b+1);
	if(la!=lb)
	{
		printf("No\n");
		return 0;
	}
	for(int i=1;i<=la;++i)
		if(check(a,i)^check(b,i))
		{
			printf("No\n");
			return 0;
		}
	printf("Yes");
	return 0;
}