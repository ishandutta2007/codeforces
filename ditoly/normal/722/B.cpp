#include<cstdio>
#define MAX 100
int p[MAX+5];
int main()
{
	int n,i,j,k;char c;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&p[i]);
	c=getchar();
	for(i=0;i<n;i++)
	{
		for(k=0,c=getchar();c!='\n';c=getchar())
			if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')k++;
		if(k!=p[i])return 0*puts("NO");
	}
	puts("YES");
}