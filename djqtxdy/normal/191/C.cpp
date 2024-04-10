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
const int Maxn=100005;
vector<pair<int,int> > G[Maxn];
int cnt[Maxn];
int p[20][Maxn];
int st[Maxn],ed[Maxn];
int depth[Maxn];
int up[Maxn];
bool vis[Maxn];
int cur;
void dfs(int x,int dep){
	st[x]=cur++;
	depth[x]=dep;
	vis[x]=true;
	for (int i=0;i<G[x].size();i++){
		if (!vis[G[x][i].first]){
			p[0][G[x][i].first]=x;
			up[G[x][i].first]=G[x][i].second;
			dfs(G[x][i].first,dep+1);
		}
	}
	ed[x]=cur;
}
int tmp[Maxn];
void dfs2(int x){
	vis[x]=true;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i].first;
		if (!vis[v]){
			dfs2(v);
			cnt[G[x][i].second]+=tmp[v];
			tmp[x]+=cnt[G[x][i].second];
		}
	}
}
bool isanc(int u,int v){
	if (u==-1) return true;
	return st[u]<=st[v] && ed[v]<=ed[u];
}
int lca(int u,int v){
	for (int i=19;i>=0;i--){
		if (!isanc(p[i][u],v)){
			u=p[i][u];
		}
	}
//	cout<<u<<' '<<v<<endl;
	if (isanc(u,v)) return u;
	return p[0][u];
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(mp(v,i+1));
		G[v].pb(mp(u,i+1));
	}
	dfs(1,0);
	p[0][1]=-1;
	for (int i=1;i<20;i++){
		for (int j=1;j<=n;j++){
			if (p[i-1][j]==-1) p[i][j]=-1; else p[i][j]=p[i-1][p[i-1][j]];
		}
	}
//	cout<<p[0][2]<<' '<<p[2][2]<<endl;
	int k;
	scanf("%d",&k);
	for (int i=0;i<k;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		cnt[up[u]]++;
		cnt[up[v]]++;
		int x=lca(u,v);
	//	cout<<x<<endl;
		if (x!=1){
			cnt[up[x]]-=2;
		}
	}
	memset(vis,false,sizeof(vis));
	dfs2(1);
	for (int i=1;i<=n-1;i++){
		printf("%d ",cnt[i]);
	}
	printf("\n");
	return 0;
}