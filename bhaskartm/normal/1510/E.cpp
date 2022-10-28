#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef double db;
typedef pair<int,int>pi;
const db eps=1e-7;
map<pi,int> f[325][19];
db xx,yy;
bool isint(db x){
	if (x<-eps) return 0;
	return abs(x-round(x))<eps;
}
int n;
void dfs1(int x,int mask,int h,int u,int v,int w){
    if (x==n/2){
		f[u][h][(pi){v,w}]=mask;
		return;
    }
    dfs1(x+1,mask,h+1,u+h*2+1,v+x*(h*2+1),w+h*(h+1));
    if (h>0)
	dfs1(x+1,mask|(1<<x),h-1,u+h*2-1,v+x*(h*2-1),w+h*(h-1));
}
void dfs2(int x,int mask,int h,int u,int v,int w){
    if (x==n/2){
        for (int i=n/2;i<=n*n/4;i++){
			if (i*2-u<0||i*2-u>n*n/4) continue;
			db X=(xx-0.5)*i*2;
			db Y=yy*i*2-1./3*n;
			if (!isint(X)||!isint(Y)) continue;
			int sumx=round(X);
			int sumy=round(Y);
			pi tmp=(pi){sumx-v,sumy-w};
            if (f[i*2-u][h].find(tmp)!=f[i*2-u][h].end()){
				int mask0=f[i*2-u][h][tmp];
                for (int i=0;i<n/2;i++) if (mask0&(1<<i)) printf(")"); else printf("(");
                for (int i=0;i<n/2;i++) if (mask&(1<<i)) printf(")"); else printf("("); puts("");
                exit(0);
            }
        }
        return;
    }
    if (h>0)
    dfs2(x-1,mask,h-1,u+h*2-1,v+(x-1)*(h*2-1),w+h*(h-1));
    dfs2(x-1,mask|(1<<(x-1-n/2)),h+1,u+h*2+1,v+(x-1)*(h*2+1),w+h*(h+1));
}
int main(){
	cin >> n >> xx >> yy;
    dfs1(0,0,0,0,0,0);
    dfs2(n,0,0,0,0,0);
    return 0;
}