#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int MX=1000100;

int N,K,A[MX];
int cnt[MX];

int main()
{
	scanf("%d%d",&N,&K);
	Fr(i,1,N)scanf("%d",&A[i]);
	int l=1,k=0,al=1,ar=1,mx=0;
	Fr(r,1,N)
	{
		k+=!cnt[A[r]]++;
		while(k>K)k-=!--cnt[A[l++]];
		if(r-l+1>mx)mx=r-l+1,al=l,ar=r;
	}
	printf("%d %d\n",al,ar);
	return 0;
}