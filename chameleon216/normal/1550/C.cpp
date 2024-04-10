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

const int MX=200100;
int N,A[MX];
inline bool Check(int i,int j,int k)
{
	return (A[i]<=A[j]&&A[j]<=A[k])||(A[i]>=A[j]&&A[j]>=A[k]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(i,1,N)scanf("%d",&A[i]);
		int ans=0;
		Fr(l,1,N)
		{
			Fr(r,l,N)
			{
				Fr(i,l,r-1)Fr(j,i+1,r-1)
					if(Check(i,j,r))goto Break;
				++ans;
			}
			Break:;
		}
		printf("%d\n",ans);
	}
	return 0;
}