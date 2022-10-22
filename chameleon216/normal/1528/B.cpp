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
const int MX=1200000,W=1000005;
const int Mod=998244353;


int N;
ll A[MX];
ll S[MX];


int main()
{
	scanf("%d",&N);
	Fr(i,1,N)for(int j=i;j<=N;j+=i)++A[j];
	Fr(i,1,N)A[i]+=S[i-1],A[i]%=Mod,S[i]=S[i-1]+A[i],S[i]%=Mod;
	printf("%lld\n",A[N]);
	return 0;
}