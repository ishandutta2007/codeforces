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

int N,K;
int Color(int i,int j)
{
	int c=0;
	while(i!=j)i/=K,j/=K,++c;
	return c;
}

int main()
{
	scanf("%d%d",&N,&K);
	int p=1,c=0;
	while(p<N)p*=K,++c;
	printf("%d\n",c);
	Fr(i,1,N)Fr(j,i+1,N)
		printf("%d ",Color(i-1,j-1));
	return 0;
}