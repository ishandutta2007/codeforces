#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
typedef pair<int,int> pii;
typedef pair<pii,pii> piiii;
#define fi first
#define se second
#define mkp make_pair
struct edge{
	int to,rev,cap,cost;
	edge(int a,int b,int c,int d):to(a),rev(b),cap(c),cost(d){}
};
vector<edge>g[80];
void addedge(int fr,int to,int cap,int cost){
	g[fr].push_back(edge(to,(int)g[to].size(),cap,cost));
	g[to].push_back(edge(fr,(int)g[fr].size()-1,0,-cost));
}
int n,K,b[103];
int dis[80],h[80];
int pe[80],pv[80],a[80];
bool ins[80];
pii MCMF(int s,int t){
	pii ret=mkp(0,0);
	while(1){
		queue<int>que;
		fill(dis,dis+n/2+28,INF);
		fill(ins,ins+n/2+28,0);
		dis[s]=0,que.push(s),a[s]=INF,ins[s]=1;
		while(!que.empty()){
			int x=que.front();que.pop(),ins[x]=0;
			int w=dis[x];
			for(int i=0;i<g[x].size();i++){
				edge e=g[x][i];
				int w1=w+e.cost+h[x]-h[e.to];
				if(e.cap>0&&dis[e.to]>w1){
					dis[e.to]=w1;
					pe[e.to]=i;
					pv[e.to]=x;
					a[e.to]=min(e.cap,a[x]);
					if(!ins[e.to])ins[e.to]=1,que.push(e.to);
				}
			}
		}
		if(dis[t]==INF)return ret;
		for(int i=0;i<=n/2+27;i++)h[i]=min(h[i]+dis[i],INF);
		int b=a[t];
		ret.fi+=b,ret.se+=b*h[t];
		for(int i=t;i!=s;){
			int pa=pv[i],pg=pe[i];
			edge &e=g[pa][pg];
			e.cap-=b;
			g[i][e.rev].cap+=b; 
			i=pa;
		}
	}
}
int num[26];
char c[103];
int main(){
	scanf("%d%s",&n,c+1);
	for(int i=1;i<=n;i++)num[c[i]-'a']++,scanf("%d",&b[i]);
	for(int i=0;i<26;i++){
		addedge(0,i+1,num[i],0);
		for(int j=1;j<=n/2;j++){
			int val=0;
			if(c[j]-'a'==i)val=b[j];
			if(c[n-j+1]-'a'==i)val=max(val,b[n-j+1]);
			addedge(i+1,j+26,1,-val);
		}
	}
	for(int i=1;i<=n/2;i++)addedge(i+26,n/2+27,2,0);
	printf("%d",-MCMF(0,n/2+27).se);
}