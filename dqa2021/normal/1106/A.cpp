#include<cstdio>
#include<algorithm>
using namespace std;

int n;
char s[510][510];
int tot;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=2;i<n;i++)
		for (int j=2;j<=n;j++)
			if (s[i][j]=='X'&&s[i-1][j-1]=='X'&&s[i-1][j+1]=='X'&&s[i+1][j+1]=='X'&&s[i+1][j-1]=='X')
				tot++;
	printf("%d\n",tot);
	return 0;
}