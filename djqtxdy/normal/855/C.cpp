//This disgusting code is wriiten by Juruo D0zingbear
//Please don't hack me! 0v0 <3
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;


// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=100005;
const int Maxk=15;
const long long mod=1e9+7;
long long dp[Maxn][Maxk][3],dpp[Maxn][Maxk][3];
vector<int> G[Maxn];
int n;
long long m;
bool vis[Maxn];
int k,mx;
long long qp(long long a,long long b){
	if (!b) return 1;
	if (b==1) return a;
	if (b%2==0){
		long long y=qp(a,b/2);
		return y*y%mod;
	}
	else{
		long long y=qp(a,b/2);
		return y*y%mod*a%mod;
	}
}
long long inv(long long x){
	return qp(x,mod-2);
}
void dfs(int x){
	vis[x]=true;
	vector<int> tmp;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!vis[v]) dfs(v),tmp.pb(v);
	}
	int p=tmp.size();
	for (int i=1;i<=p;i++){
		for (int j=0;j<=mx;j++){
			for (int k=0;k<3;k++) dpp[i][j][k]=0LL;
		}
	}
	dpp[0][1][0]=1;
	dpp[0][0][1]=k-1;
	dpp[0][0][2]=m-k;
	for (int i=1;i<=p;i++){
		for (int j=0;j<=mx;j++){
			for (int k=0;k<=j;k++){
				dpp[i][j][0]+=dpp[i-1][k][0]*(dp[tmp[i-1]][j-k][1]);
				dpp[i][j][0]%=mod;
				dpp[i][j][1]+=dpp[i-1][k][1]*(dp[tmp[i-1]][j-k][0]+dp[tmp[i-1]][j-k][1]+dp[tmp[i-1]][j-k][2]);
				dpp[i][j][1]%=mod;
				dpp[i][j][2]+=dpp[i-1][k][2]*(dp[tmp[i-1]][j-k][1]+dp[tmp[i-1]][j-k][2]);
				dpp[i][j][2]%=mod;
			}
			//cout<<dpp[i][j][0]<<' '<<dpp[i][j][1]<<' '<<dpp[i][j][2]<<endl;
		}
	}
	for (int i=0;i<=mx;i++){
		for(int k=0;k<3;k++){
			dp[x][i][k]=dpp[p][i][k];
		}
	}
}
int main(){
	scanf("%d %I64d",&n,&m);
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u); 
	}
	scanf("%d %d",&k,&mx);
	memset(vis,false,sizeof(vis));
	dfs(1);
	long long ans=0;
	for (int i=0;i<=mx;i++){
		ans+=dp[1][i][0];
		ans+=dp[1][i][1];
		ans+=dp[1][i][2];
		ans%=mod;
	}
	printf("%I64d\n",ans);
	return 0;
}