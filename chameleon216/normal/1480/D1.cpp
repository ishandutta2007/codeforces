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
const int MX=410000;

int N,Ans=1;
int X[MX];

int H[MX],cnt;
int L;
int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",X+i);
	
	H[0]=-1;
	H[++cnt]=X[1];
	L=-1;
	Fr(j,2,N)
	{
		int x=X[j];
		if(H[cnt]!=x)H[++cnt]=x,++Ans;
		else if(L!=x)H[0]=L,L=H[cnt],cnt=0,H[++cnt]=x,++Ans;
		else
		{
			Fr(i,1,cnt-1)if(H[i]!=x)
			{
				int delta=
					(H[i]!=L)+(H[i-1]!=H[i+1])
					-(H[i]!=H[i-1])-(H[i]!=H[i+1]);
				if(delta>=0)
				{
					H[0]=L,L=H[cnt],cnt=0,H[++cnt]=x,Ans+=delta+1;
					goto Continue;
				}
			}
			H[++cnt]=x;
		}
		Continue:;
	//	Fr(i,0,cnt)printf("%d ",H[i]);
	//	printf("\n%d\nAns=%d\n",L,Ans);
	}
	
	printf("%d\n",Ans);
	return 0;
}