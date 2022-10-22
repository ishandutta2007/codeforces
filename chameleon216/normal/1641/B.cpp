#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=500100;
int N,S[MX];
int ans[MX],ac,sum;
int P[MX],C[MX],pc;
void Do(int p,int c){P[++pc]=p,C[pc]=c;}

bool Solve()
{
	int r=0;
	Fr(i,2,N)if(S[i]==S[1]){r=i;break;}
	if(!r)return 1;
	// 1 .... r ....
	
//	printf("Solve r=%d\n",r);
	
	Fr(i,2,r-1)Do(sum+r+i-2,S[i]);
	ans[++ac]=(r-1)*2,sum+=(r-1)*2;
	reverse(S+2,S+r);
	move(S+2,S+r,S+1);
	move(S+r+1,S+N+1,S+r-1);
	N-=2;
	return 0;
}

void Work()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",&S[i]);
	while(N)if(Solve())
		{printf("-1\n");return;}
	printf("%d\n",pc);
	Fr(i,1,pc)printf("%d %d\n",P[i],C[i]);
	printf("%d\n",ac);
	Fr(i,1,ac)printf("%d ",ans[i]);
	putchar('\n');
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		Work();
		ac=sum=pc=0;
	}
	return 0;
}