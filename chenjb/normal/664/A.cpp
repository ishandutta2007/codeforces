#include<cstdio>
#include<cstring>
using namespace std;
char s1[2000],s2[2000];
int main()
{
	while (scanf("%s%s",s1,s2)!=EOF)
	{
		if (strcmp(s1,s2)==0) printf("%s\n",s1);
		else printf("1\n");
	}
	return 0;
}