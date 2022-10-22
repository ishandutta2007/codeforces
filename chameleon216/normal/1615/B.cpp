#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;

const int MX=200100,N=200000,Inf=0x3f3f3f3f;
int M,S[MX][20];

int main()
{
	Fr(i,1,N)Fr(j,0,19)S[i][j]=S[i-1][j]+!(i>>j&1);
	scanf("%d",&M);
	Fr(i,1,M)
	{
		int l,r,res=Inf;
		scanf("%d%d",&l,&r);
		Fr(j,0,19)res=min(res,S[r][j]-S[l-1][j]);
		printf("%d\n",res);
	}
	return 0;
}