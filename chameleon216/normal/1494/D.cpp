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
const int MX=1200,Inf=0x3f3f3f3f;
int N;
int A[MX][MX];
int C[MX];

int F[MX],nc;

int main()
{
	scanf("%d",&N);
	nc=N;
	Fr(i,1,N)Fr(j,1,N)
		scanf("%d",&A[i][j]);
	Fr(i,1,N)C[i]=A[i][i];
	C[0]=Inf;
	Fr(j,2,N)
	{
		int mn=Inf,x=0;
		Fr(i,1,j-1)
			if(A[i][j]<mn)x=i,mn=A[i][j];
		int i=x;
		while(A[i][j]>C[F[x]])x=F[x];
		if(C[F[x]]==A[i][j])F[j]=F[x];
		else
		{
			int y=++nc;
			C[y]=A[i][j];
			F[y]=F[x];
			F[x]=F[j]=y;
		}
	}
	printf("%d\n",nc);
	Fr(i,1,nc)printf("%d ",C[i]);putchar('\n');
	int r=0;
	Fr(i,1,nc)if(F[i]==0)r=i;
	printf("%d\n",r);
	Fr(i,1,nc)if(F[i]!=0)printf("%d %d\n",i,F[i]);
	//Fr(i,1,nc)printf("%d ",C[i]);putchar('\n');
	//Fr(i,1,nc)printf("%d ",F[i]);putchar('\n');
	return 0;
}