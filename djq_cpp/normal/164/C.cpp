#define CF_164C
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=2e9+7;
namespace MCF{
	int n;
	struct edge{
		int to,cap,cost,rev,id;
		edge(int t=-1,int ca=INF,int co=0,int r=-1,int i=-1){
			to=t;cap=ca;cost=co;rev=r;id=i;
		}
	};
	vector<edge> G[2005];
	int h[2005];
	bool vis[2005];
	int dist[2005];
	int pv[2005],pe[2005];
	void add_edge(int from,int to,int cap,int cost,int id){
		G[from].push_back(edge(to,cap,cost,G[to].size(),id));
		G[to].push_back(edge(from,0,-cost,G[from].size()-1,id));
	}
	int min_cost_flow(int s,int t,int f){
		rep(k,n)h[k]=0;
#ifdef CF_164C
		rep(i,n)rep(j,G[i].size())
		if(G[i][j].cost>=0)h[i]=min(h[i],h[G[i][j].to]-G[i][j].cost);
#endif
		int ans=0;
		while(f>0){
			priority_queue<pii> que;
			rep(k,n)dist[k]=INF;
			rep(k,n)vis[k]=false;
			dist[s]=0;
			que.push(MP(0,s));
			while(!que.empty()){
				pii cur=que.top();que.pop();
				int v=cur.second;
				if(vis[v])continue;
				vis[v]=true;
				rep(k,G[v].size()){
					edge ce=G[v][k];
					int u=ce.to,cl=ce.cost+h[v]-h[u];
					if(ce.cap>0&&dist[u]>dist[v]+cl){
						dist[u]=dist[v]+cl;
						pv[u]=v;
						pe[u]=k;
						que.push(MP(-dist[u],u));
					}
				}
			}
			if(dist[t]==INF)return -1;
			rep(k,n)h[k]+=dist[k];
			int d=f;
			for(int k=t;k!=s;k=pv[k])d=min(d,G[pv[k]][pe[k]].cap);
			f-=d;
			ans+=d*h[t];
			for(int k=t;k!=s;k=pv[k]){
				G[pv[k]][pe[k]].cap-=d;
				G[k][G[pv[k]][pe[k]].rev].cap+=d;
			}
		}
		return ans;
	}
}
int n,m,st[1005],fi[1005],co[1005],v;
int ans[1005];
map<int,int> id;
int main(){
	scanf("%d%d",&n,&m);
	rep(k,n){
		scanf("%d%d%d",&st[k],&fi[k],&co[k]);
		fi[k]+=st[k];
		id[st[k]]=id[fi[k]]=-1;
	}
	id[0]=id[INF]=-1;
	for(map<int,int>::iterator it=id.begin();it!=id.end();it++)it->second=v++;
	MCF::n=v;
	for(int k=1;k<v;k++)MCF::add_edge(k-1,k,INF,0,-1);
	rep(k,n)MCF::add_edge(id[st[k]],id[fi[k]],1,-co[k],k);
	MCF::min_cost_flow(0,v-1,m);
	rep(i,v)rep(j,MCF::G[i].size())
	if(MCF::G[i][j].id!=-1)ans[MCF::G[i][j].id]=MCF::G[i][j].cap;
	rep(k,n)printf("%d ",ans[k]);
	return 0;
}