#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
const int M=800;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void readc(char &c){
	char ch=getchar();
	for (;ch==' '||ch=='\n';ch=getchar());
	c=ch;
}
int n,m,q,dir[3][2]={{-1,0},{0,-1},{0,1}},go[100004][10][2],vis[100004][10],has[100004][10];
bool v[100004][10];
map<char,int>mp;
char c[100004][12],oper;
void init(){
	mp['^']=0,mp['<']=1,mp['>']=2;
}
void recovery(int x,int y,int now){
	if (x<0 || y<1 || x>=n || y>m){
		write(x+1),putchar(' '),write(y),puts("");
		return;
	}
	if (vis[x][y]==now){
		puts("-1 -1");
		return;
	}
	if (go[x][y][1]==-1){
		puts("-1 -1");
		return;
	}
	vis[x][y]=now;
	recovery(go[x][y][0],go[x][y][1],now);
}
pii dfs(int x,int y,int a,int b,int cnt){
	if (x<a || x>b || y<1 || y>m) return mkp(x,y);
	if (has[x][y]==cnt){
		go[x][y][1]=-1;
		return mkp(0,-1);
	}
	if (v[x][y]) return mkp(go[x][y][0],go[x][y][1]);
	v[x][y]=1;
	has[x][y]=cnt;
	pii val=dfs(x+dir[mp[c[x][y]]][0],y+dir[mp[c[x][y]]][1],a,b,cnt);
	go[x][y][0]=val.fi,go[x][y][1]=val.se;
	return mkp(go[x][y][0],go[x][y][1]);
}
int cnt;
void upd(int l,int r){
	for (int i=l;i<=r;i++) for (int j=1;j<=m;j++)v[i][j]=0;
	for (int i=l;i<=r;i++) for (int j=1;j<=m;j++)if(!v[i][j]) dfs(i,j,i/M*M,min(i/M*M+M-1,n-1),++cnt);
}
int main(){
	init();
	read(n),read(m),read(q);
	for (int i=0;i<n;i++)
		for (int j=1;j<=m;j++)
			readc(c[i][j]);
	upd(0,n-1);
	while (q--){
		int x,y;readc(oper),read(x),read(y),x--;
		if (oper=='A'){
			recovery(x,y,q+1);
			continue;
		}
		readc(oper);
		c[x][y]=oper;
		upd(x/M*M,min(n-1,x/M*M+M-1));
	}
}