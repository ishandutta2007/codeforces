#include<stdio.h>
#define R register int
int a[4001],pos[4001],len[4001],ct,n;
bool f[2001][2001];
inline void DFS(int x,int y,int k,bool&tag){
	if(f[x][y]==true||tag==true){
		return;
	}
	if(x==n&&y==n){
		tag=true;
		return;
	}
	f[x][y]=true;
	if(x+len[k]<=n){
		DFS(x+len[k],y,k+1,tag);
	}
	if(y+len[k]<=n){
		DFS(x,y+len[k],k+1,tag);
	}
}
inline void Solve(){
	scanf("%d",&n);
	int m=n<<1;
	for(R i=1;i<=m;i++){
		scanf("%d",a+i);
		pos[a[i]]=i;
	}
	for(R i=0;i<=n;i++){
		for(R j=0;j<=n;j++){
			f[i][j]=false;
		}
	}
	int lt=m+1;
	ct=0;
	for(R i=m;i!=0;i--){
		if(pos[i]<lt){
			len[ct]=lt-pos[i];
			ct++;
			lt=pos[i];
		}
	}
	bool tag=false;
	DFS(0,0,0,tag);
	if(tag==true){
		puts("YES");
	}else{
		puts("NO");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}