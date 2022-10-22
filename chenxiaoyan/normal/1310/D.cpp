/*




D P 




 l l
*/
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf=0x3f3f3f3f;
int _rand(){return abs(rand()*rand()*rand()+rand());}
int rand0(int r){return _rand()%r;}
const int N=80,M=10;
int n,m;
int con[N+1][N+1];
int ans=inf;
int dp[M+1][N+1];
bool key[N+1];
void random(){
	vector<int> v[2];
	for(int i=1;i<=n;i++)v[key[i]=rand0(2)].pb(i);
	memset(dp,0x3f,sizeof(dp));
	dp[0][1]=0;
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++){
		vector<int> &v0=v[!key[j]];
		for(int k=0;k<v0.size();k++)dp[i][j]=min(dp[i][j],dp[i-1][v0[k]]+con[v0[k]][j]);
	}
	ans=min(ans,dp[m][1]);
}
int main(){
	srand(19260817);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>con[i][j];
	int cl=clock();
	while(clock()-cl<=2900)random();
	cout<<ans;
	return 0;
}
/*1
5 8
0 1 2 2 0
0 0 1 1 2
0 1 0 0 0
2 1 1 0 0
2 0 1 2 0
*/
/*2
3 2
0 1 1
2 0 1
2 2 0
*/