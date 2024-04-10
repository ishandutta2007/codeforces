#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define rg register
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=110000;

ll N,K;
ll A[MX];

int mian()
{
	scanf("%lld%lld",&N,&K);
	int N_=N;
	Fr(i,1,N)scanf("%lld",A+i);
	sort(A+1,A+1+N),N=unique(A+1,A+1+N)-A-1;
	if(K==0){printf("%lld\n",N);return 0;}
	ll Max=A[N];
	
//	printf("%lld\n",N);
	if(Max+1==N)printf("%lld\n",N+K);
	else
	{
		ll Mex=0;
		if(A[1]!=0)Mex=0;
		else
		{
			Fr(i,1,N)if(A[i]+1!=A[i+1]){Mex=A[i]+1;break;}
		}
		ll tmp=(Mex+Max+1)>>1;
		Fr(i,1,N)if(A[i]==tmp){printf("%lld\n",N);return 0;}
		printf("%lld\n",N+1);
	}
	Fr(i,1,N_+1)A[i]=0;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}