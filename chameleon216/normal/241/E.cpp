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
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=5e3+100;
struct Edge{int y,w,nx;}E[MX<<2];
int H[MX],ec;
void Add(int x,int y,int w)
{
	E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;
}

int N,M;
int X[MX],Y[MX];

template<typename T>
struct Queue
{
	T L[MX],R[MX];
	int l,r;
	char empty(){return !l&&!r;}
	void rev(){while(r)L[++l]=R[r--];}
	T front()
	{
		if(!l)rev();
		return L[l];
	}
	void push(T x){R[++r]=x;}
	void pop()
	{
		if(!l)rev();
		--l;
	}
};

#define y E[i].y
#define w E[i].w
char B[MX];
int D[MX],cnt[MX];
Queue<int> Q;
int Spfa(int s)
{
	Fill(D,0x3f);
	Q.push(s),D[s]=0;
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop(),B[x]=0;
		Fe(i,x)if(D[y]>D[x]+w)
		{
			D[y]=D[x]+w,cnt[y]=cnt[x]+1;
			if(!B[y])Q.push(y),B[y]=1;
			if(cnt[y]>=N)return 1;
		}
	}
	return 0;
}

char V[MX];
void dfs1(int x)
{
	if(x==N)V[x]=1;
	B[x]=1;
	Fe(i,x)
	{
		if(!B[y])dfs1(y);
		if(V[y])V[x]=1;
	}
}
#undef y
#undef w


int main()
{
	scanf("%d%d",&N,&M);
	int x,y;
	Fr(i,1,M)
	{
		scanf("%d%d",&x,&y);
		X[i]=x,Y[i]=y;
		Add(x,y,1);
	}
	dfs1(1);
//	Fr(i,1,N)printf("%d ",V[i]);
	
	Fill(B,0);
	Fill(H,0),ec=0; // 
	Fr(i,1,M)
	{
		x=X[i],y=Y[i];
		if(V[x]&&V[y])Add(y,x,-1),Add(x,y,2);
	}
	
	int res=Spfa(1);
	if(res||!V[N]){printf("No");return 0;}
//	Fr(i,1,N)printf("%d ",D[i]);
	printf("Yes\n");
	
	Fr(i,1,M)
	{
		x=X[i],y=Y[i];
		int w=1;
		if(V[x]&&V[y])w=D[y]-D[x];
		printf("%d\n",w);
	}
	return 0;
}