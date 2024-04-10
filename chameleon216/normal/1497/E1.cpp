#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=220000,W=10005,U=10010000;

char isp[11005];
int P[10000],cnt;

void Eratos()
{
	Fill(isp,1),isp[0]=isp[1]=0;
	for(int i=2;i*i<=W;++i)if(isp[i])
		for(int j=i*i;j<=W;j+=i)isp[j]=0;
	Fr(i,2,W)if(isp[i])P[++cnt]=i;
}

int Change(int x)
{
	Fr(i,1,cnt)
	{
		int p2=P[i]*P[i];
		if(p2>x)break;
		while(x%p2==0)x/=p2;
	}
	return x;
}


int N,K;
int B[U],bcnt;
int mian()
{
	scanf("%d%d",&N,&K);
	int ans=1;++bcnt;
	Fr(i,1,N)
	{
		int a;
		scanf("%d",&a),a=Change(a);
		if(B[a]==bcnt)++ans,++bcnt;
		B[a]=bcnt;
	}
	printf("%d\n",ans);
	return 0;
}


int main()
{
	Eratos();
	int t;
	scanf("%d",&t);
	while(t--)mian();
	//printf("%d\n",Change(603000));
	return 0;
}