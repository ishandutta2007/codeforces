#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <algorithm>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=120000;
int N,A[MX];

struct Pt
{
	int x,c;
	Pt(){}
	Pt(int x_,int c_){x=x_,c=c_;}
};
bool operator<(const Pt& a,const Pt& b){return a.c<b.c;}
bool Comp(int a,int b){return a>b;}

priority_queue<struct Pt> Q;
int Re[MX][3],rc;

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",&A[i]);
	sort(A+1,A+1+N);
	int cnt=0;
	Fr(i,1,N)
	{
		++cnt;
		if(A[i]!=A[i+1])Q.push(Pt(A[i],cnt)),cnt=0;
	}
	Pt p[3];
	while(Q.size()>=3)
	{
		++rc;
		Fo(i,0,3)p[i]=Q.top(),Q.pop(),Re[rc][i]=p[i].x,--p[i].c;
		sort(Re[rc],Re[rc]+3,Comp);
		Fo(i,0,3)if(p[i].c)Q.push(p[i]);
	}
	printf("%d\n",rc);
	Fr(i,1,rc){Fo(j,0,3)printf("%d ",Re[i][j]);putchar('\n');}
	return 0;
}