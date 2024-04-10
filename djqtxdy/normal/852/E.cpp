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
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}

// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=1e5+5;
const long long mod=1e9+7;
vector<int> G[Maxn];
long long dp[Maxn][2];
bool vis[Maxn];
bool isle[Maxn];
long long qp(long long x,long long y){
	if (!y) return 1;
	if (y==1) return x;
	if (y%2==0){
		LL z=qp(x,y/2);
		return z*z%mod;
	}
	else{
		LL z=qp(x,y/2);
		return z*z%mod*x%mod;
	}
}
long long inv(long long x){
	return qp(x,mod-2);
}
void dfs(int x){
	vis[x]=true;
	bool flag=true;
	dp[x][0]=dp[x][1]=1;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!vis[v]){
			dfs(v);
			flag=false;
			dp[x][0]*=dp[v][1];
			dp[x][1]*=dp[v][0];
			dp[x][0]%=mod;
			dp[x][1]%=mod;
		}
	}
	if (!flag){
		dp[x][0]*=2;
		dp[x][1]*=2;
		dp[x][0]%=mod;
		dp[x][1]%=mod;
	}
	else{
		isle[x]=true;
	}
}
long long ans=0;
void dfs2(int x,int p,long long pre0,long long pre1){
	LL del0=dp[x][0],del1=dp[x][1];
	if (p==1 && G[1].size()==1){
		del0=pre0,del1=pre1;
	}
//	cout<<del0<<del1<<endl;
	pre0*=inv(del0);
	pre1*=inv(del1);
	if (isle[x]) pre0*=2,pre1*=2;
	pre0%=mod;
	pre1%=mod;
	pre0*=dp[x][0];
	pre1*=dp[x][1];
	pre0%=mod;
	pre1%=mod;
	ans+=pre0;
	ans%=mod;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (v!=p){
			dfs2(v,x,pre0,pre1);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1);

	ans+=dp[1][0];
	for (int i=0;i<G[1].size();i++){
		dfs2(G[1][i],1,dp[1][0],dp[1][1]);
	}
	printf("%I64d\n",ans); 
	return 0;
}