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
const int Maxn=200005;
const int Maxm=20;
vector<pair<int,LL> > G[Maxn];
int p[Maxm][Maxn],dep[Maxn];
int par[Maxn];
LL dist[Maxn];
bool vis[Maxn];
int n,q;
void _init(){
	for (int i=0;i<Maxn;i++) par[i]=i; 
}
int findset(int x){
	return par[x]=(par[x]==x)?x:findset(par[x]);
}
void Union(int x,int y){
	x=findset(x);
	y=findset(y);
	par[y]=x;
}
void dfs(int x){
	vis[x]=true;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i].first;
		if (!vis[v]){
			p[0][v]=x;
			dist[v]=G[x][i].second;
			dep[v]=dep[x]+1;
			dfs(v);
		}
	}
}
int lca(int x,int y){
	if (dep[x]>dep[y]) swap(x,y);
	int diff=dep[y]-dep[x];
	for (int i=0;i<20;i++){
		if (diff & (1<<i)) y=p[i][y];
	}
	if (x==y) return x;
	for (int i=19;i>=0;i--){
		if (p[i][x]!=p[i][y]){
			x=p[i][x];
			y=p[i][y];
		}
	}
	return p[0][x];
}
LL solve(int now,int tar,LL val){
	if (val==0LL) return 0LL; 
	LL ret=val;
	while (1){
		if (findset(now)==findset(tar)){
			return ret;
		}
		else{
			now=findset(now);
			ret/=dist[now];
			if (ret==0LL) return 0LL;
			now=p[0][now];
		}
	}
}
vector<pair<pair<int,int>,LL> > e;
int main(){
	_init();
	scanf("%d %d",&n,&q);
	for (int i=0;i<n-1;i++){
		int u,v;
		LL c;
		scanf("%d %d %I64d",&u,&v,&c);
		G[u].pb(mp(v,c));
		G[v].pb(mp(u,c));
		e.push_back(mp(mp(u,v),c));
	}
	dfs(1);
	p[0][1]=-1;
	for (int i=1;i<20;i++){
		for (int j=1;j<=n;j++){
			if (p[i-1][j]==-1) p[i][j]=-1;
			else {
				p[i][j]=p[i-1][p[i-1][j]];
			} 
		}
	}
	for (int i=0;i<e.size();i++){
		int u=e[i].first.first,v=e[i].first.second;
		if (dep[u]>dep[v]) swap(e[i].first.first,e[i].first.second);
		if (e[i].second==1LL){
			if (dep[u]>dep[v]) swap(u,v);
			Union(u,v);
		}
	}
	for (int i=0;i<q;i++){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int u,v;
			scanf("%d %d",&u,&v);
			LL y;
			scanf("%I64d",&y);
			int k=lca(u,v);
			LL ans=solve(u,k,y);
			ans=solve(v,k,ans);
			printf("%I64d\n",ans);
		}
		else{
			int num;
			LL val;
			scanf("%d %I64d",&num,&val);
			num--;
			if (val==1LL){
				int u=e[num].first.first,v=e[num].first.second;
				Union(u,v);
			}
			else{
				int u=e[num].first.first,v=e[num].first.second;
				dist[v]=val;
			}
		}
	}
	return 0;
}
/*
2 5
2 1 5
1 1 2 22
1 2 2 18
2 1 2
1 2 1 22
1 1 1 10
*/
/*
4
18
11
10
*/