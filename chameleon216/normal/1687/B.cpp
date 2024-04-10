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

const int MX=505;
int N,M,W[MX],id[MX],ans;
bool cmp(int i,int j){return W[i]<W[j];}

char S[MX];
int Query()
{
	printf("? ");
	Fr(i,1,M)putchar(S[i]+'0');
	putchar('\n');
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
void Ans(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}


int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,M)id[i]=i,S[i]=1,W[i]=Query(),S[i]=0;
	sort(id+1,id+M+1,cmp);
	Fr(i_,1,M)
	{
		int i=id[i_];
		S[i]=1;
		int w=Query();
		if(w==ans+W[i])ans=w;
		else S[i]=0;
	}
	Ans(ans);
	return 0;
}