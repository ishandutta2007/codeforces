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
const int MX=120000;
int Abs(int x){return x>=0?x:-x;}
int N,M;
int A[MX];
int cnt[MX];

int mian()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%d",A+i),A[i]%=M,cnt[A[i]]++;
	int x=(M-1)/2,ans=0;
	Fr(i,1,x)
	{
		int a=cnt[i],b=cnt[M-i];
		if(!a&&!b)continue;
		else if(a==b)++ans;
		else ans+=Abs(a-b);
	}
	if(cnt[0])++ans;
	if(M%2==0&&cnt[M/2])++ans;
	printf("%d\n",ans);
	Fr(i,1,N)cnt[A[i]]=0,A[i]=0;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}