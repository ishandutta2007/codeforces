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

const int MX=10100;
int N,A[MX];
void Move(int i,int j,int x)
{
	printf("%d %d %d\n",i,j,x);
}

int mian()
{
	scanf("%d",&N);
	int s=0;
	Fr(i,1,N)scanf("%d",&A[i]),s+=A[i];
	if(s%N){puts("-1");return 0;}
	s/=N;
	printf("%d\n",3*(N-1));
	Fr(i,2,N)
	{
		int x=(i-A[i]%i)%i;
		Move(1,i,x);
		Move(i,1,(A[i]+x)/i);
	}
	Fr(i,2,N)Move(1,i,s);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		mian();
	}
	return 0;
}