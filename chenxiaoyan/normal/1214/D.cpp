/*









 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
const int N=1000000;
int n,m;
string a[N+1];
const int mod1=1000000007,mod2=998244353;
vector<pair<int,int> > dp1[N+1],dp2[N+1];
pair<int,int> operator+(pair<int,int> a,pair<int,int> b){return mp((a.X+b.X)%mod1,(a.Y+b.Y)%mod2);}
void operator+=(pair<int,int> &a,pair<int,int> b){a=a+b;}
pair<int,int> operator*(pair<int,int> a,pair<int,int> b){return mp((int)(1ll*a.X*b.X%mod1),(int)(1ll*a.Y*b.Y%mod2));}
signed main(){
//	freopen("C:\\Users\\chenx\\OneDrive\\\\txt.txt","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]=(string)" "+a[i];
	if(n==1||m==1){
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]=='#')return puts("0"),0;
		return puts("1"),0;
	}
	for(int i=1;i<=n;i++)dp1[i].resize(m+1),dp2[i].resize(m+1);
	dp1[1][1]=mp(1,1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(i!=1||j!=1){
		dp1[i][j]=mp(0,0);
		if(a[i][j]=='#')continue;
		if(i>1)dp1[i][j]+=dp1[i-1][j];
		if(j>1)dp1[i][j]+=dp1[i][j-1];
	}
	dp2[n][m]=mp(1,1);
	for(int i=n;i;i--)for(int j=m;j;j--)if(i!=n||j!=m){
		dp2[i][j]=mp(0,0);
		if(a[i][j]=='#')continue;
		if(i<n)dp2[i][j]+=dp2[i+1][j];
		if(j<m)dp2[i][j]+=dp2[i][j+1];
	}
	if(dp1[n][m]==mp(0,0))return puts("0"),0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(i==1&&j==1||i==n&&j==m||a[i][j]=='#')continue;
		if(dp1[i][j]*dp2[i][j]==dp1[n][m])return puts("1"),0;
	}
	puts("2");
	return 0;
}