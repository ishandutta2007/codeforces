#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int a[1002][1002],ans=0;
int b[1000002],tot=0,n,m;
bool vis[1002][1002];
bool chk(int x,int y){
	return x>=1&&y>=1&&x<=n&&y<=m&&!vis[x][y];
}
void DFS(int x,int y){
	if(!(a[x][y]&8)){
		if(chk(x-1,y)){
			++ans;
			vis[x-1][y]=1;
			DFS(x-1,y);
		}
	}
	if(!(a[x][y]&4)){
		if(chk(x,y+1)){
			++ans;
			vis[x][y+1]=1;
			DFS(x,y+1);
		}
	}
	if(!(a[x][y]&2)){
		if(chk(x+1,y)){
			++ans;
			vis[x+1][y]=1;
			DFS(x+1,y); 
		}
	}
	if(!(a[x][y]&1)){
		if(chk(x,y-1)){
			++ans;
			vis[x][y-1]=1;
			DFS(x,y-1);
		}
	}
}
int main(){
	int i,j;
	read(n);read(m);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)read(a[i][j]);
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(!vis[i][j]){
				ans=1;
				vis[i][j]=1;
				DFS(i,j);
				b[++tot]=ans;
			}
		}
	}
	sort(b+1,b+1+tot);
	for(i=tot;i>=1;--i)printf("%d ",b[i]);
	return 0;
}