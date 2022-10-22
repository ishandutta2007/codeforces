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
const int MX=310000;

int N;
char S[MX];
int X[MX],Y[MX],A[MX],B[MX];
int stk[MX],tp;

void solve()
{
	tp=0;
	Fr(i,0,N)
	{
		stk[++tp]=i;
		if(!Y[i+1])
		{
			Fr(j,1,tp)A[stk[j]]=tp;
			tp=0;
		}
	}
}

int mian()
{
	scanf("%d",&N);
	scanf("%s",S+1);
	Fr(i,1,N)X[i]=(S[i]=='R');
	
	Fr(i,1,N)Y[i]=((i+1)&1)^X[i];
//	Fr(i,1,N)printf("%d",Y[i]);putchar('\n');
	solve();
//	Fr(i,0,N)printf("%d",A[i]);putchar('\n');
	Fr(i,0,N)if((i+1)&1)B[i]=A[i];
	
	Fr(i,1,N)Y[i]=((i)&1)^X[i];
//	Fr(i,1,N)printf("%d",Y[i]);putchar('\n');
	solve();
//	Fr(i,0,N)printf("%d",A[i]);putchar('\n');
	Fr(i,0,N)if(i&1)B[i]=A[i];
	
	Fr(i,0,N)printf("%d ",B[i]);
	putchar('\n');
	return 0;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		mian();
		Fr(i,0,N+1)X[i]=Y[i]=A[i]=B[i]=0;
	}
}