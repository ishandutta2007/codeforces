#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=1e5+100;

int N;
char S[MX];
int A[MX],B[MX];

int mian()
{
	scanf("%d",&N);
	scanf("%s",S+1);
	Fr(i,1,N)A[i]=S[i]-'0';
	Fr(i,1,N)
	{
		B[i]=1;
		if(A[i-1]+B[i-1]==A[i]+B[i])B[i]=0;
	}
	Fr(i,1,N)printf("%d",B[i]);
	printf("\n");
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian(),Fill(B,0);
	return 0;
}