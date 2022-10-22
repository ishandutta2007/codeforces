#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int Inf=0x3f3f3f3f;
int N,A,B,H[12];
int cnt[12],res[12],ans=Inf;

void dfs(int i,int c)
{
	if(c>=ans)return;
	if(i==N)
	{
		if(c<ans)ans=c,memcpy(res,cnt,sizeof(res));
		return;
	}
	int l=H[i-1],m=H[i],r=H[i+1];
	while(1)
	{
		if(H[i-1]<0&&(i<N-1||(H[i]<0&&H[i+1]<0)))dfs(i+1,c);
		if(H[i-1]<0&&H[i]<0&&(i<N-1||H[i+1]<0))break;
		++cnt[i],++c;
		H[i-1]-=B,H[i]-=A,H[i+1]-=B;
	}
	H[i-1]=l,H[i]=m,H[i+1]=r,cnt[i]=0;
}

int main()
{
	scanf("%d%d%d",&N,&A,&B);
	Fr(i,1,N)scanf("%d",&H[i]);
	dfs(2,0);
	printf("%d\n",ans);
	Fr(i,1,N)Fr(j,1,res[i])
		printf("%d ",i);
	putchar('\n');
	return 0;
}