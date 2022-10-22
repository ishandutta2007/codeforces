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
const int MX=200100,Inf=0x3f3f3f3f;
const char* P[6]={"abc","acb","bac","bca","cab","cba"};

int N,M;
char S[MX];
int A[MX][6];

int main()
{
	scanf("%d%d%s",&N,&M,S+1);
	Fr(i,1,N)Fo(k,0,6)
		A[i][k]=A[i-1][k]+(S[i]!=P[k][i%3]);
	Fr(i,1,M)
	{
		int l,r,ans=Inf;
		scanf("%d%d",&l,&r);
		Fo(k,0,6)ans=min(ans,A[r][k]-A[l-1][k]);
		printf("%d\n",ans);
	}
	return 0;
}