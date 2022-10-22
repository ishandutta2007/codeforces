#include<cstdio>
#define N 110
using namespace std;
int a[N],b[N],f[N][N*N*2],T,ans,s,n,x,y,ANS;
const int inf=0x3f3f3f3f;
void getmin(int&a,int b){if(a>b)a=b;}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=s=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),ans+=a[i]*a[i]*(n-1);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]),ans+=b[i]*b[i]*(n-1);
		for(int i=1;i<=n;i++)
		{
			x=a[i],y=b[i];
			for(int j=0;j<=s+x+y;j++) f[i][j]=inf;
			for(int j=0;j<=s;j++)
				getmin(f[i][j+x],f[i-1][j]+j*x+(s-j)*y),
				getmin(f[i][j+y],f[i-1][j]+j*y+(s-j)*x);
			s+=x+y;
		}
		ANS=inf;
		for(int i=0;i<=s;i++) getmin(ANS,f[n][i]);
		printf("%d\n",ANS*2+ans);
	}
}