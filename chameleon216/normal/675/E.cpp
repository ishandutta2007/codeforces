#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int MX=120000,Inf=0x3f3f3f3f;
int N,A[MX],C[MX];


struct SparseTable
{
	int v[17][MX],lg[MX];
	int max_(int i,int j){return A[i]>A[j]?i:j;}
	void build()
	{
		lg[0]=-1;
		Fr(i,1,N)v[0][i]=i,lg[i]=lg[i>>1]+1;
		Fr(i,1,lg[N])for(int j=1;j+(1<<i)-1<=N;++j)
			v[i][j]=max_(v[i-1][j],v[i-1][j+(1<<(i-1))]);
	}
	int ask(int l,int r)
	{
		int i=lg[r-l+1];
		return max_(v[i][l],v[i][r-(1<<i)+1]);
	}
}st;

ll D[MX];



int main()
{
	scanf("%d",&N);
	Fo(i,1,N)scanf("%d",A+i);
	A[N]=N;
	st.build();
	ll sum=0;
	Fl(i,N-1,1)
	{
		int j=st.ask(i+1,A[i]);
		sum+=D[i]=D[j]+(j-i)+(N-A[i]);
	}
	printf("%lld\n",sum);
	return 0;
}