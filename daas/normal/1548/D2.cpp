#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,C[4][4][4],B[6010][6010],X[6010],Y[6010];
ll ans1,ans2;
int gcd(int x,int y)
{
	int z=x%y;
	while(z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) X[i]=read(),Y[i]=read();
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			if(X[i]==X[j]) B[i][j]=B[j][i]=abs(Y[i]-Y[j]);
			else if(Y[i]==Y[j]) B[i][j]=B[j][i]=abs(X[i]-X[j]);
			else B[i][j]=B[j][i]=gcd(abs(X[i]-X[j]),abs(Y[i]-Y[j]));
		}
	for(int p=1;p<=n;++p)
	{
		memset(C,0,sizeof(C));
		for(int i=1;i<=n;++i) if(p!=i) ++C[X[i]%4][Y[i]%4][B[p][i]%4];
		int x=X[p]%4,y=Y[p]%4;
		//0
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
			{
				for(int k=0;k<4;++k)
				{
					if(k%2==0) ans2+=(ll)C[i][j][k]*(C[i][j][k]-1)/2;
					for(int w=k+1;w<4;++w) if((w+k)%4==0)
					{
						if(w%2==0 && k%2==0) ans2+=(ll)C[i][j][k]*C[i][j][w];
						else ans1+=(ll)C[i][j][k]*C[i][j][w];
					}
				}
			}
		//2
		for(int ax=0;ax<4;++ax)
			for(int ay=0;ay<4;++ay)
				for(int bx=ax;bx<4;++bx)
					for(int by=(ax==bx?ay:0);by<4;++by) if(ax%2==bx%2 && ay%2==by%2 && !(ax==bx && ay==by))
					{
						int adx=(ax-x+4)%4,ady=(ay-y+4)%4;
						int bdx=(bx-x+4)%4,bdy=(by-y+4)%4;
						int S=abs(adx*bdy-ady*bdx)%4;
						if(S%2==0)
						{
							for(int i=0;i<4;++i)
								for(int j=0;j<4;++j) if((i+j+2)%4==S)
								{
									if(i%2==0 && j%2==0) ans2+=(ll)C[ax][ay][i]*C[bx][by][j];
									else ans1+=(ll)C[ax][ay][i]*C[bx][by][j];
								}
						}
					}
	}
	printf("%lld\n",ans1+ans2/3);
	return 0;
}
//ore no turn,draw!