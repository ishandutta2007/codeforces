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

const int MX=1000100;
int N,M,Q;
char S[2][MX];
int B[MX];


int main()
{
	scanf("%d%d",&N,&M);
	char *s=S[0],*t=S[1];
	Fr(i,1,N)
	{
		scanf("%s",t+1);
		Fo(j,1,M)if(s[j+1]=='X'&&t[j]=='X')
			B[j]=1;
		swap(s,t);
	}
//	Fo(i,1,M)printf("%d ",B[i]);putchar('\n');
	Fo(i,1,M)B[i]+=B[i-1];
	scanf("%d",&Q);
	Fr(i,1,Q)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int sum=B[r-1]-B[l-1];
		printf(!sum?"YES\n":"NO\n");
	}
	return 0;
}