#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=160000;
const ll oo=0x3f3f3f3f3f3f3f3f;
int N[4];
ll A[4][MX];
vector<int> V[MX];
ll Dp[MX],Ep[MX];

struct St
{
	ll v[22][MX];
	int lg[MX];
	void init(ll* a,int n)
	{
		lg[0]=-1;
		Fr(i,1,n)v[0][i]=a[i],lg[i]=lg[i>>1]+1;
		Fr(i,1,lg[n])for(int j=1;j+(1<<i)-1<=n;++j)
			v[i][j]=min(v[i-1][j],v[i-1][j+(1<<(i-1))]);
	}
	ll ask(int l,int r)
	{
		int i=lg[r-l+1];
		return min(v[i][l],v[i][r-(1<<i)+1]);
	}
}st;

void Solve()
{
	int M,x,y;
	
	Fr(i,1,N[0])Dp[i]=A[0][i];
	
	Fr(k,1,3)
	{
		st.init(Dp,N[k-1]);
		//Fr(i,1,N[0]){Fr(j,i,N[0])printf("%d ",st.ask(i,j));putchar('\n');}
		scanf("%d",&M);
		Fr(i,1,M)scanf("%d%d",&x,&y),V[y].push_back(x);
	//	printf("DP: ");
		Fr(i,1,N[k])
		{
			V[i].push_back(0),V[i].push_back(N[k-1]+1);
			sort(V[i].begin(),V[i].end());
			int sz=V[i].size();
			Ep[i]=oo;
			Fo(j,1,sz)
			{
				int l=V[i][j-1]+1,r=V[i][j]-1;
				if(r>=l)Ep[i]=min(Ep[i],st.ask(l,r));//printf("%d %d\n",l,r);
			}
			Ep[i]+=A[k][i];
	//		printf("%lld ",Ep[i]);
		}
	//	puts("");
		Fr(i,1,N[k])Dp[i]=Ep[i];
		Fr(i,1,N[k])V[i].clear();
	}
	ll res=*min_element(Dp+1,Dp+1+N[3]);
	printf("%lld\n",res>=oo?-1:res);
}

int main()
{
	Fo(i,0,4)scanf("%d",N+i);
	Fo(i,0,4)Fr(j,1,N[i])scanf("%lld",A[i]+j);
	Solve();
}