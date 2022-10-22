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

int mian()
{
	int N,A[5]={0},B[5]={0};
	scanf("%d",&N);
	Fr(i,0,3)scanf("%d",A+i);
	for(B[0]=0;B[0]<=1;++B[0])
		for(B[1]=0;B[1]<=1;++B[1])
			for(B[2]=0;B[2]<=1;++B[2])
				for(B[3]=0;B[3]<=1;++B[3])
	{
		Fr(i,0,3)
		{
			int l=B[i],r=B[(i+1)%4];
			if(!(l+r<=A[i]&&A[i]<=l+r+N-2))goto G;
		}
		printf("YES\n");
		return 1;
	G:;
	}
	printf("NO\n");
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}