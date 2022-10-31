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
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxn=4005;
const int Maxk=105;
int a[Maxk];
struct edge{
	int v,c,r;
};
vector<edge> G[Maxn];
bool vis[Maxn];
void add_edge(int u,int v,int c){
	G[u].push_back((edge){v,c,G[v].size()});
	G[v].push_back((edge){u,0,G[u].size()-1}); 
} 
int dfs(int now,int tar,int f){
	vis[now]=true;
	if (now==tar) return f;
	for (int i=0;i<G[now].size();i++){
		if (vis[G[now][i].v] || !G[now][i].c) continue;
		edge &buff=G[now][i];
		int d=dfs(buff.v,tar,min(f,buff.c));
		if (d>0){
			buff.c-=d;
			G[buff.v][buff.r].c+=d;
			return d;
		} 
	}
	return 0;
}
int max_flow(int s,int t){
	int ans=0;
	while (1){
		for (int i=0;i<Maxn;i++) vis[i]=false;
		int fl=dfs(s,t,INF);
		if (!fl) break;
		ans+=fl;
	} 
	return ans;
} 
set<int> p;
pii ee[202];
int val[202];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int temp=a[i];
		for (int j=2;j*j<=temp;j++){
			if (temp%j==0){
				p.insert(j);
				while (temp%j==0){
					temp/=j;
				}
			}
		}
		if (temp>1) p.insert(temp);
	}
	for (int i=0;i<m;i++){
		scanf("%d %d",&ee[i].first,&ee[i].second);
	}
	int res=0;
	for (set<int>::iterator i=p.begin();i!=p.end();i++){
		int now=*i;
	//	cout<<now<<endl;
		for (int j=0;j<Maxn;j++){
			G[j].clear();
		}
		for (int j=1;j<=n;j++){
			val[j]=0;
			int temp=a[j];
			while (temp%now==0){
				temp/=now;
				val[j]++;
			}
		}
		int s=3999,t=4000;
		for (int j=1;j<=n;j++){
			if (j%2==0)add_edge(s,j,val[j]);
			else add_edge(j,t,val[j]);
		}
		for (int j=0;j<m;j++){
			if (ee[j].first%2==0)add_edge(ee[j].first,ee[j].second,200);
			else add_edge(ee[j].second,ee[j].first,200);
		}
		res+=max_flow(s,t);
	} 
	printf("%d\n",res);
	return 0;
}