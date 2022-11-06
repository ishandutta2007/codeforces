#include<cstdio>
#include<cstring>

int n,m;
int g[16][16],ass[16][16],mxs;

const int dx[4][5]={
 0, 0, 1, 2, 0,
 0, 0,-1, 1, 0,
 0, 0,-1,-2, 0,
 1, 2, 1, 1, 0
};
const int dy[4][5]={
 1, 2, 1, 1, 0,
 1, 2, 2, 2, 0,
 1, 2, 1, 1, 0,
 0, 0, 1, 2, 0
};

inline bool chk(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m&&!g[x][y];
}
bool chkT(int x,int y,int tp){
	for(int i=0;i<5;i++){
		if(!chk(x+dx[tp][i],y+dy[tp][i]))return 0;
	}
	return 1;
}
void set(int x,int y,int tp,int val){
	for(int i=0;i<5;i++){
		g[x+dx[tp][i]][y+dy[tp][i]]=val;
	}
}
void dfs(int x,int y,int tot){
	if(tot+( n*m-(n*y-n+x) )/6<=mxs)return;
	//failsafe
	if(x<1||x>n||y<1||y>m)return;
	//end failsafe
	if(tot>mxs){
		mxs=tot;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ass[i][j]=g[i][j];
	}
	int tx,ty;
	tx= x==n?1:x+1;
	ty= x==n?y+1:y;
	for(int i=0;i<4;i++){
		if(chkT(x,y,i)){
			set(x,y,i,tot+1);
			dfs(tx,ty,tot+1);
			set(x,y,i,0);
		}
	}
	dfs(tx,ty,tot);
}

int main(){
	scanf("%d%d",&n,&m);
	dfs(1,1,0);
	printf("%d\n",mxs);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ass[i][j])putchar('A'+ass[i][j]-1);
			else putchar('.');
		}
		putchar('\n');
	}
	return 0;
}