#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define rg register
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=600;
int N,M;
char G[MX][MX];

int mian()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%s",G[i]+1);
	for(int i=((N%3==1)?1:2);i<=N;i+=3)
	{
		Fr(j,1,M)G[i][j]='X';
		if(i>2)
		{
			if(G[i-2][2]=='X'||G[i-1][2]=='X')G[i-2][2]=G[i-1][2]='X';
			else G[i-2][1]=G[i-1][1]='X';
		}
	}//printf("ans:\n");
	Fr(i,1,N)puts(G[i]+1);//putchar('\n');
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}