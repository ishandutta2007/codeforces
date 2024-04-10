#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1010];
int st[1010][2],tp,s[1010][1010];
int st1[1010][2],tp1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	st[tp=1][0]=1,st[1][1]=n+1;
	for(int i=1;i<=n;++i)
	{
		int res=a[i];
		s[st[1][0]][i]=1;--res;
		for(int j=1;j<=n+1;++j)
			if((j<st[1][0]||j>st[1][1])&&res)s[j][i]=1,--res;
		int cnt=res+1;
		for(int j=st[1][0]+1;res;++j)s[j][i]=1,--res;
	//	printf("%d\n",cnt);
		tp1=0;
		for(int j=2;j<=tp;++j)st1[++tp1][0]=st[j][0],st1[tp1][1]=st[j][1];
		if(cnt>1)st1[++tp1][0]=st[1][0],st1[tp1][1]=st[1][0]+cnt-1;
		cnt=st[1][1]-st[1][0]+1-cnt;
		if(cnt>1)st1[++tp1][0]=st[1][1]-cnt+1,st1[tp1][1]=st[1][1];
		for(int j=1;j<=tp1;++j)st[j][0]=st1[j][0],st[j][1]=st1[j][1];
		tp=tp1;
	}
	printf("%d\n",n+1);
	for(int i=1;i<=n+1;++i)
	{
		for(int j=1;j<=n;++j)printf("%d",s[i][j]);
		printf("\n");
	}
	return 0;
}