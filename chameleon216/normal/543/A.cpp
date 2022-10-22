#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=600;
template<typename T,int U>
void PutMat(T a[][U],int n,int m)
{
	Fr(i,1,n){Fr(j,1,m)cout<<a[i][j]<<' ';cout<<'\n';}
	cout<<'\n';
}
#define DMat(a,n,m) (printf(#a"[%d][%d]:\n",n,m),PutMat(a,n,m))


int N,M,V;
int v[MX];
ll dp[MX][MX],Mod;

int main()
{
	scanf("%d%d%d%lld",&N,&M,&V,&Mod);
	Fr(i,1,N)scanf("%d",v+i);
	dp[0][0]=1;
	Fr(i,1,N)
	{
		Fr(j,1,M)Fr(k,v[i],V)
			dp[j][k]+=dp[j-1][k-v[i]],dp[j][k]%=Mod;
		//DMat(dp,M,V);
	}
	ll sum=0;
	Fr(k,0,V)sum+=dp[M][k];
	printf("%lld\n",sum%Mod);
	return 0;
}