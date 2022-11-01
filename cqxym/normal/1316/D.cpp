#include<stdio.h>
#define R register int
#define I inline
int x[1002][1002],y[1002][1002];
bool vis[1001][1001];
char ans[1001][1001];
I bool Com(int a,int b,int c,int d){
	return a==c&&b==d;
}
I void DFS(int a,int b,char c){
	if(vis[a][b]==true){
		return;
	}
	ans[a][b]=c;
	vis[a][b]=true;
	if(Com(x[a-1][b],y[a-1][b],x[a][b],y[a][b])==true){
		DFS(a-1,b,'D');
	}
	if(Com(x[a+1][b],y[a+1][b],x[a][b],y[a][b])==true){
		DFS(a+1,b,'U');
	}
	if(Com(x[a][b-1],y[a][b-1],x[a][b],y[a][b])==true){
		DFS(a,b-1,'R');
	}
	if(Com(x[a][b+1],y[a][b+1],x[a][b],y[a][b])==true){
		DFS(a,b+1,'L');
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		for(R j=1;j<=n;j++){
			scanf("%d%d",&x[i][j],&y[i][j]);
		}
	}
	for(R i=1;i<=n;i++){
		for(R j=1;j<=n;j++){
			if(x[i][j]==i&&y[i][j]==j){
				DFS(i,j,'X');
			}
		}
	}
	for(R i=1;i<=n;i++){
		for(R j=1;j<=n;j++){
			if(x[i][j]!=-1){
				if(vis[i][j]==false){
					printf("INVALID");
					return 0;
				}
			}else{
				char T;
				if(x[i-1][j]==-1){
					T='U';
				}else if(x[i+1][j]==-1){
					T='D';
				}else if(x[i][j-1]==-1){
					T='L';
				}else if(x[i][j+1]==-1){
					T='R';
				}else{
					printf("INVALID");
					return 0;
				}
				DFS(i,j,T);
			}
		}
	}
	printf("VALID");
	for(R i=1;i<=n;i++){
		puts("");
		for(R j=1;j<=n;j++){
			putchar(ans[i][j]);
		}
	}
	return 0;
}