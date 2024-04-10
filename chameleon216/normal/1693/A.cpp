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

const int MX=200100;
int N,A[MX];

bool Solve()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",&A[i]);
	if(A[1]==0)
	{
		Fr(i,2,N)if(A[i]!=0)return 0;
		return 1;
	}
	ll s=0,f=0;
	Fl(i,N,2)
	{
		s+=A[i];
		if(s<0)f=1;
		if(s>0)return 0;
		if(f&&s==0)return 0;
	}
	s+=A[1];
	if(s!=0)return 0;
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	Fr(i,1,t)
	{
		puts(Solve()?"Yes":"No");
	}
	return 0;
}