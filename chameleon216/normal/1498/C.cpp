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
const int MX=1050,Mod=1e9+7;
int N,K;

ll dp[MX][MX][2];
int B[MX][MX][2],bcnt;
ll dfs(int i,int k,int f)
{
	if(k==0)return 0;
	if(i<1||i>N)return 1;
	ll &res=dp[i][k][f>0];
	if(B[i][k][f>0]==bcnt)return res;
	B[i][k][f>0]=bcnt;
	res=(dfs(i+f,k,f)+dfs(i-f,k-1,-f))%Mod;
	return res;
}

int mian()
{
	scanf("%d%d",&N,&K);
	++bcnt;
	ll res=dfs(1,K,1);
	printf("%lld\n",res);
	return 0;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)mian();
}