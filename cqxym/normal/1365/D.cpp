#include<stdio.h>
#define R register int
#define I inline void
char p[52][52];
bool v[51][51];
int n,m;
I Block(int x,int y){
	if(p[x][y]=='.'){
		p[x][y]='#';
	}
}
I DFS(int x,int y){
	if(x>n||x<1||y>m||y<1||p[x][y]=='#'||v[x][y]==true){
		return;
	}
	v[x][y]=true;
	DFS(x-1,y);
	DFS(x+1,y);
	DFS(x,y-1);
	DFS(x,y+1);
}
I Solve(){
	scanf("%d%d",&n,&m);
	for(R i=1;i<=n;i++){
		getchar();
		for(R j=1;j<=m;j++){
			v[i][j]=false;
			p[i][j]=getchar();
		}
	}
	for(R i=1;i<=n;i++){
		for(R j=1;j<=m;j++){
			if(p[i][j]=='B'){
				Block(i-1,j);
				Block(i+1,j);
				Block(i,j-1);
				Block(i,j+1);
			}
		}
	}
	DFS(n,m);
	for(R i=1;i<=n;i++){
		for(R j=1;j<=m;j++){
			if((p[i][j]=='G'&&v[i][j]==false)||(p[i][j]=='B'&&v[i][j]==true)){
				puts("no");
				return;
			}
		}
	}
	puts("Yes");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}