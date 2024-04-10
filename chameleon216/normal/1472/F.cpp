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
const int MX=1e6+100;

int N;
int X[MX][2];

bool tanxin()
{
	Fr(i,1,N)Fr(j,0,1)if(X[i][j]==0)
	{
		int j2=j^1;
		if(X[i][j2]==0)X[i][j]=X[i][j2]=2;
		else if(i+1<=N&&X[i+1][j]==0)X[i][j]=X[i+1][j]=3;
		else return 0;
	}
	return 1;
}
/*
int mian2()
{
	int M;
	scanf("%d%d",&N,&M);
	int x,y;
	Fr(i,1,M)scanf("%d%d",&x,&y),X[y][x-1]=1;
	tanxin();
	Fr(j,0,1){Fr(i,1,N)printf("%d",X[i][j]);printf("\n");}
	Fr(i,1,N)Fr(j,0,1)X[i][j]=0;
	return 0;
}
*/

struct B{int x,y;}b[MX];
bool operator<(B a,B b){return a.x<b.x;}
int tx[MX];
int mian()
{
	int n,M;
	scanf("%d%d",&n,&M);
	Fr(i,1,M)scanf("%d%d",&b[i].y,&b[i].x);
	sort(b+1,b+1+M);
	Fr(i,1,M)
	{
		int len=b[i].x-b[i-1].x;
		len%=2;
		if(len==0&&b[i].x!=b[i-1].x)len+=2;
//		printf("%d\n",len);
		tx[i]=tx[i-1]+len;
		X[tx[i]][b[i].y-1]=1;
	}
	int len=n-b[M].x;
	len%=2;
//	if(len==0)len+=2;
	N=tx[M]+len;
	
//	Fr(i,1,M)printf("%d ",tx[i]);printf("%d\n",N);
	int res=tanxin();
	printf(res?"YES\n":"NO\n");
//	Fr(j,0,1){Fr(i,1,N)printf("%d",X[i][j]);printf("\n");}
	Fr(i,1,N)Fr(j,0,1)X[i][j]=0;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}