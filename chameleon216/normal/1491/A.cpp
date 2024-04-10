#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=110000;
int N,M;
int A[MX];
int X;

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%d",A+i),X+=A[i];
	int x,a;
	Fr(i,1,M)
	{
		scanf("%d%d",&x,&a);
		switch(x)
		{
		case 1:
			A[a]^=1;
			if(A[a])++X;
			else --X;
			break;
		case 2:
			printf("%d\n",a<=X);
		}
	}
	return 0;
}