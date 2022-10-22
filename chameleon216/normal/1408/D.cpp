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

const int MX=2500,W=1000000,MY=1000100,Inf=0x3f3f3f3f;
int N,M;
struct Node{int x,y;}A[MX],B[MX];
int ans[MY];

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%d%d",&A[i].x,&A[i].y);
	Fr(i,1,M)scanf("%d%d",&B[i].x,&B[i].y);
	Fr(i,1,N)Fr(j,1,M)
	{
		if(A[i].x<=B[j].x&&A[i].y<=B[j].y)
		{
			int p=B[j].x-A[i].x,q=B[j].y-A[i].y;
			ans[q]=max(ans[q],p+1);
		}
	}
	Fl(i,W,0)ans[i]=max(ans[i],ans[i+1]);
	int res=Inf;
	Fr(i,0,W)res=min(res,i+ans[i]);
	printf("%d\n",res);
	return 0;
}