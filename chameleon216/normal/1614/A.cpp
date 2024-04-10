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

const int MX=110;
int N,L,R,K;
int A[MX];

void Work()
{
	scanf("%d%d%d%d",&N,&L,&R,&K);
	int ac=0;
	Fr(i,1,N)
	{
		int x;
		scanf("%d",&x);
		if(L<=x&&x<=R)A[++ac]=x;
	}
	sort(A+1,A+ac+1);
	int c=0;
	Fr(i,1,ac)if(A[i]<=K)K-=A[i],++c;
	printf("%d\n",c);
}

int main()
{
	int t;
	scanf("%d",&t);
	Fr(i,1,t)Work();
	return 0;
}