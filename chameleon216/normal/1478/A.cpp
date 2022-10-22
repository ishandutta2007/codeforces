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
const int MX=120;

int N;
int X[MX];
int C[MX],ccnt;



int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",X+i);
	Fr(i,1,N)
	{
		int x=X[i];
		int mx=0,y=0;
		Fr(j,1,ccnt)if(C[j]<x&&C[j]>mx)mx=C[j],y=j;
		if(y)C[y]=x;
		else C[++ccnt]=x;
		//Fr(k,1,ccnt)printf("%d ",C[k]);putchar('\n');
	}
	printf("%d\n",ccnt);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	Fr(i,1,t)
	{
		mian();
		Fill(X,0),Fill(C,0),ccnt=0;
	}
	return 0;
}