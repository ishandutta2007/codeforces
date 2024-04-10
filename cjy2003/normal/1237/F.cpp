#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-mod:x;}
int h,w,n;
bool bh[4000],bl[4000];
int dph[4000][4000],dpl[4000][4000],C[4000][4000],cnth,cntl,ans,jc[4000];
int calc(int x,int y)
{
	return 1ll*dph[h][y]*C[cnth-2*y][x]%mod*dpl[w][x]%mod*C[cntl-2*x][y]%mod*jc[x]%mod*jc[y]%mod;
}
int main()
{
	jc[0]=1;
	for(int i=1;i<=3600;++i)jc[i]=1ll*jc[i-1]*i%mod;
	C[0][0]=1;
	for(int i=1;i<=3600;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=pl(C[i-1][j-1],C[i-1][j]);
	}
	scanf("%d %d %d",&h,&w,&n);
	int x,y,xx,yy;
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d %d %d",&x,&y,&xx,&yy);
		if(bh[x]||bh[xx]||bl[y]||bl[yy])
		{
			printf("0");
			return 0;
		}
		bh[x]=bh[xx]=bl[y]=bl[yy]=1;
	}
	dph[0][0]=1;
	for(int i=1;i<=h;++i)
	{
		memcpy(dph[i],dph[i-1],sizeof(dph[i-1]));
		if(i>1&&!bh[i]&&!bh[i-1])for(int j=1;j<=h;++j)add(dph[i][j],dph[i-2][j-1]);
		cnth+=!bh[i];
//		for(int j=0;j<=h;++j)printf("%d ",dph[i][j]);printf("\n");
	}
	dpl[0][0]=1;
	for(int i=1;i<=w;++i)
	{
		memcpy(dpl[i],dpl[i-1],sizeof(dpl[i-1]));
		if(i>1&&!bl[i]&&!bl[i-1])for(int j=1;j<=w;++j)add(dpl[i][j],dpl[i-2][j-1]);
		cntl+=!bl[i];
	}
//	for(int i=0;i<=h;++i)printf("%d ",dph[h][i]);printf("\n");
	for(int i=0;i<=cnth&&2*i<=cntl;++i)
		for(int j=0;j*2<=cnth&&j<=cntl;++j)
			add(ans,calc(i,j));
	printf("%d",ans);
	return 0;
}