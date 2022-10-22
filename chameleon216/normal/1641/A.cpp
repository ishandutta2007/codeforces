#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <map>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=200100;
int N,X,A[MX];

void Work()
{
	scanf("%d%d",&N,&X);
	Fr(i,1,N)scanf("%d",&A[i]);
	sort(A+1,A+N+1);
	map<int,int> mp;
	int sz=0;
	Fr(i,1,N)
	{
		if(A[i]%X==0&&mp[A[i]/X])--mp[A[i]/X],--sz;
		else ++mp[A[i]],++sz;
	}
	printf("%d\n",sz);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		Work();
	}
	return 0;
}