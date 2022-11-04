#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

namespace Flows{
	struct Edge{
		int to,cap,rev,whr;
		Edge(int to,int cap,int rev,int whr):to(to),cap(cap),rev(rev),whr(whr){}
	};
	vector<Edge> egs[5005];
	bool lgl[5005];
	int whr[5005][5005];
	void NewEdge(int u,int v,int cap,int Whr){
		whr[u][v]=egs[u].size();
		whr[v][u]=egs[v].size();
		egs[u].push_back(Edge(v,cap,egs[v].size(),Whr));
		egs[v].push_back(Edge(u,0,egs[u].size()-1,Whr));
	}
	int calc(int frm,int to,int cap){
		if(frm==to){
			//cerr<<cap<<endl;
			return cap;
		}
		lgl[frm]=1;
		for(int i=0;i<((int)egs[frm].size());i++){
			if(egs[frm][i].cap&&!lgl[egs[frm][i].to]){
				int ff=calc(egs[frm][i].to,to,min(cap,egs[frm][i].cap));
				if(ff){
					egs[frm][i].cap-=ff;
					egs[egs[frm][i].to][egs[frm][i].rev].cap+=ff;
					return ff;
				}
			}
		}
		return 0;
	}
	void init(){
		for(int i=0;i<5005;i++){
			egs[i].clear();
		}
	}
}

int n,m,k;
int deg[5005];
int mxdeg=1e9+7;
int used[5005];
int chs[5005][5005],cnt[5005];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		deg[u]++;
		deg[n+v]++;
		Flows::NewEdge(u,n+v,1,i+1);
		//val[u][n+v]=i+1;
	}
	for(int i=1;i<=n;i++){
		mxdeg=min(mxdeg,deg[i]);
	}
	for(int i=1;i<=m;i++){
		mxdeg=min(mxdeg,deg[n+i]);
	}
	for(int i=1;i<=n;i++){
		Flows::NewEdge(0,i,deg[i]-mxdeg,0);
	}
	for(int i=1;i<=m;i++){
		Flows::NewEdge(n+i,n+m+1,deg[n+i]-mxdeg,0);
	}
	int ans=0;
	for(int I=mxdeg;I>=0;I--){
		//cerr<<I<<endl;
		while(1){
			memset(Flows::lgl,0,sizeof(Flows::lgl));
			int FF=Flows::calc(0,n+m+1,1e9+7);
			if(!FF){
				break;
			}
			ans+=FF;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<((int)Flows::egs[i].size());j++){
				if(Flows::egs[i][j].to&&Flows::egs[i][j].cap){
					chs[I][Flows::egs[i][j].whr]=1;
					//cerr<<val[i][Flows::egs[i][j].to]<<' '<<i<<' '<<Flows::egs[i][j].to<<' '<<j<<endl;
					cnt[I]++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			Flows::egs[0][Flows::whr[0][i]].cap++;
		}
		for(int i=1;i<=m;i++){
			Flows::egs[n+i][Flows::whr[n+i][n+m+1]].cap++;
		}
	}
	for(int i=0;i<=mxdeg;i++){
		printf("%d",cnt[i]);
		for(int j=1;j<=k;j++){
			if(chs[i][j]){
				printf(" %d",j);
			}
		}
		puts("");
	}
	return 0;
}