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
// cf IO: I64d
// atcoder IO: 
const int Maxn=100005;
const int Maxk=20;
int p[Maxk][Maxn];
bool vis[Maxn];
int t[Maxn];
int dep[Maxn];
int n,k;
vector<int> G[Maxn];
int cnt;
int nod[Maxn];
void dfs(int x,int d){
	vis[x]=true;
	t[x]=++cnt;
	dep[x]=d;
	nod[cnt]=x;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (vis[v]) continue;
		p[0][v]=x;
		dfs(v,d+1); 
	}
}
int dist(int u,int v){
	if (dep[u]>dep[v]) swap(u,v);
	int diff=dep[v]-dep[u];
	//cout<<dep[v]<<' '<<dep[u]<<endl;
	int ret=diff;
	for (int i=0;i<20;i++){
		if (diff & (1<<i)){
			v=p[i][v];
		}
	}
	
	if (u==v) return ret;
	for (int i=19;i>=0;i--){
		if (p[i][u]!=p[i][v]){
			u=p[i][u];
			v=p[i][v];
			ret+=(1<<(i+1));
		}
	}
	ret+=2;
	return ret;
}
set<int> s;
int cost(int x){
	if (x>n) return 1e9;
	if (s.empty()) return 1;
	int y=t[x];
	set<int> ::iterator l=s.lower_bound(y);
	set<int> ::iterator r=s.lower_bound(y);
	if (r==s.begin()) r=s.end();
	r--;
	if (l==s.end()) l=s.begin();
	int L=*l,R=*r;
	L=nod[L],R=nod[R];
	return (dist(x,L)+dist(x,R)-dist(L,R))/2;
}
int main(){
	scanf("%d %d",&n,&k);
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,1);
	p[0][1]=-1;
	for (int kk=1;kk<Maxk;kk++){
		for (int i=1;i<=n;i++){
			if (p[kk-1][i]==-1) p[kk][i]=-1;
			else p[kk][i]=p[kk-1][p[kk-1][i]];
		}
	}
	//cout<<dist(1,2)<<endl;
	//return 0;
	int r=1,now=0;
	int ans=0;
	for (int l=1;l<=n;l++){
		while (1){
			int c=cost(r);
			if (now+c<=k){
				s.insert(t[r]);
				r++;
				now+=c;
				c=cost(r);
			}
			else{
				break;
			}
		}
		//cout<<l<<r<<endl;
		ans=max(ans,r-l);
		s.erase(t[l]);
		now-=cost(l);
	}
	printf("%d\n",ans);
	return 0;
}