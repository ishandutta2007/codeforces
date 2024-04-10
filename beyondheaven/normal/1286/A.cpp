#include<cstdio>
#include<cstring>
#include<algorithm>
#define MaxN 123
using std::min;
int n,m;
int a[MaxN];
bool filled[MaxN];
int f[MaxN][MaxN][2];
inline void Init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(a[i])filled[i]=1;
		a[i]&=1;
	}
	m=(n+1)/2;
	for(int i=1;i<=n;++i)
	if(a[i])--m;
}
inline void DP()
{
	memset(f,0x3f,sizeof(f));
	f[1][m][0]=0;f[1][m][1]=0;
	for(int i=1;i<=n;++i)
	for(int j=0;j<=m;++j)
	for(int g=0;g<=1;++g)
	if(filled[i])
	f[i+1][j][a[i]]=min(f[i+1][j][a[i]],f[i][j][g]+(g^a[i]));
	else
	{
		f[i+1][j][0]=min(f[i+1][j][0],f[i][j][g]+g);
		if(j)
		f[i+1][j-1][1]=min(f[i+1][j-1][1],f[i][j][g]+(g^1));
	}
	printf("%d\n",min(f[n+1][0][0],f[n+1][0][1]));
}
int main()
{
	Init();
	DP();
	return 0;
}