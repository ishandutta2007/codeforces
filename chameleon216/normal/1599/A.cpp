#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],q[1000005][2];
char s[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%s",s+1);
	sort(a+1,a+n+1);
	int l=1,r=0,las=0,lasr=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='L')
		{
			if(lasr==-1)
			{
				l--;
				q[i][0]=l;
				q[i][1]=-las;
				las=-las;
			}
			else
			{
				r++;
				q[i][0]=r;
				q[i][1]=-1;
				lasr=-1;
			}
		}
		else
		{
			if(lasr==1)
			{
				l--;
				q[i][0]=l;
				q[i][1]=-las;
				las=-las;
			}
			else
			{
				r++;
				q[i][0]=r;
				q[i][1]=1;
				lasr=1;
			}
		}
		if(l==r) las=q[i][1];
	}
	for(int i=1;i<=n;i++)
		printf("%d %c\n",a[q[i][0]-l+1],q[i][1]==-1?'L':'R');
	return 0;
}