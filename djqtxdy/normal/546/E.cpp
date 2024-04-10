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
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxn=500;
struct edge{
	int to,cap,rev;
	bool ff;
	void _init(int a,int b,int c,bool d){
		to=a,cap=b,rev=c;
		ff=d;
	}
};
vector<edge> G[Maxn]; 
bool vis[Maxn];
void add_edge(int u,int v,int c){
	edge a,b;
	a._init(v,c,G[v].size(),false);
	b._init(u,0,G[u].size(),true);
	G[u].push_back(a);
	G[v].push_back(b);
}
int dfs(int x,int e,int fl){
	if (x==e) return fl;
	vis[x]=true;
	for (int i=0;i<G[x].size();i++){
		edge &ee=G[x][i];
		if (ee.cap==0 || vis[ee.to]){
			continue;
		}
		int d=dfs(ee.to,e,min(ee.cap,fl));
		if (d){
			ee.cap-=d;
			G[ee.to][ee.rev].cap+=d;
			return d;
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int ans=0;
	while (1){
		for (int i=0;i<Maxn;i++){
			vis[i]=false;
		}
		int f=dfs(s,t,INF);
		if (!f) break;
		ans+=f;
	}
	return ans;
}
int a[Maxn],b[Maxn];
int ans[Maxn][Maxn];
int ori[Maxn][Maxn];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int sa=0,sb=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sa+=a[i];
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		sb+=b[i];
	}
	if (sa!=sb){
		printf("NO\n");
		return 0;
	}
	while (m--){
		int x,y;
		scanf("%d %d",&x,&y);
		add_edge(x,y+n,a[x]);
		ori[x][y]=a[x];
		ori[y][x]=a[y];
		add_edge(y,x+n,a[y]);
	}
	for (int i=1;i<=n;i++){
		add_edge(i,i+n,a[i]);
		ori[i][i]=a[i];
	}
	int s=499,t=500;
	for (int i=1;i<=n;i++){
		add_edge(s,i,a[i]);
		add_edge(i+n,t,b[i]);
	}
	if (max_flow(s,t)==sa){
		printf("YES\n");
		for (int i=1;i<=n;i++){
			for (int j=0;j<G[i].size();j++){
				if (G[i][j].ff) continue;
				int v=G[i][j].to-n;
				ans[i][v]=ori[i][v]-G[i][j].cap;
			}
		} 
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				printf("%d ",ans[i][j]);
			}
			printf("\n");
		}
	}
	else{
		printf("NO\n");
	}
	return 0; 
}