#include<bits/stdc++.h>
using namespace std;
int T ,n;
char s[105];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		for(int i=0;i<n;i++)
		{
			if(s[i]!='U'&&s[i]!='D')printf("%c",s[i]);
			else
			{
				if(s[i]=='U')printf("D");
				else printf("U");
			}
		}
		printf("\n");
	}
	return 0;
}