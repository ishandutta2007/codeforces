#include<cstdio>
#include<vector>
using namespace std;
const int x[10][4]={{0,1,2,3},{0,1,2,3},{0,1,2,3},{0,1,2,3},{0,1,2,4},{0,1,3,5},{0,2,3,6},{0,2,3,6},{0,2,3,4},{0,2,3,4}};
const int y[10][4]={{7,6,5,4},{6,7,5,4},{5,6,7,4},{4,6,5,7},{3,6,5,7},{2,6,4,7},{1,5,4,7},{1,4,5,7},{1,7,6,5},{1,6,7,5}};
struct Edge{int v,p;Edge():v(0),p(0){}};
inline void ad(int U,int V,int&cnt,vector<int>&h,vector<Edge>&e){e[cnt].v=V;e[cnt].p=h[U];h[U]=cnt++;}
void dfs(int nw,vector<int>&h,vector<bool>&vis,vector<bool>&usd,vector<Edge>&e,vector<int>&ax,vector<int>&ay,const int&val){
	usd[nw]=1;
	int t;
	for(int&i=h[nw];i+1;i=(i<0?i:e[i].p)) if(!vis[i>>1])
		t=i,vis[i>>1]=1,dfs(e[i].v,h,vis,usd,e,ax,ay,val),ax.push_back(e[t].v+val),ay.push_back(nw);
}
void slv(vector<int>&ax,vector<int>&ay,int n,int k){
	if(n==8){
		for(int i=0;i<4;++i) ax.push_back(x[k][i]),ay.push_back(y[k][i]);
		return;
	}
	int cnt=0;vector<int> h(n/2,-1),vx,vy;vector<bool> vis(n/2,0),usd(n/2,0);vector<Edge> e(n);
	slv(vx,vy,n/2,k/2);
	for(int i=0;i<n/4;++i) ad(vx[i],vy[i],cnt,h,e),ad(vy[i],vx[i],cnt,h,e);
	vx.clear();vy.clear();slv(vx,vy,n/2,(k+1)/2);
	for(int i=0;i<n/4;++i) ad(vx[i],vy[i],cnt,h,e),ad(vy[i],vx[i],cnt,h,e);
	for(int i=0;i<n/2;++i) if(!usd[i]) dfs(i,h,vis,usd,e,ax,ay,n/2);
}
int T,n,k;vector<int> X,Y;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&k);
		if(n==4) if(!k) printf("0 3\n1 2\n");else if(k==1) printf("0 2\n1 3\n");else if(k==2) printf("0 1\n2 3\n");else printf("-1\n");
		else{
			X.clear();Y.clear();slv(X,Y,n,k);
			for(int i=0;i<n/2;++i) printf("%d %d\n",X[i],Y[i]);
		}
	}
	return 0;
}