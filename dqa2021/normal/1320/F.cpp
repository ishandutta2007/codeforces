#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
void print(int x){
	if (x>9) print(x/10); putchar((x%10)^48);
}
#undef G

int n,m,k;
vector<int> a[200010],b[200010],c[200010],d[200010],e[200010],f[200010];
int L[4000010],R[4000010],D[4000010],U[4000010],F[4000010],B[4000010];  //91mb
int gethash(int x,int y,int z){
	return x*(m+2)*(k+2)+y*(k+2)+z;
}
void getid(int cur,int &x,int &y,int &z){
	z=cur%(k+2);
	y=cur/(k+2)%(m+2);
	x=cur/(k+2)/(m+2);
}
bool is_bound(int cur){
	int z=cur%(k+2);
	int y=cur/(k+2)%(m+2);
	int x=cur/(k+2)/(m+2);
	return !x||x>n||!y||y>m||!z||z>k;
}
bool mrk[4000010];
void dfs(int x,int y,int z){
	if (!x||x>n||!y||y>m||!z||z>k) return;
	int cur=gethash(x,y,z); if (mrk[cur]) return;
	int tmp=-1;
	if (is_bound(L[cur])){
		if (!a[y][z]) goto DEL;
		if (tmp==-1) tmp=a[y][z];
		else if (tmp^a[y][z]) goto DEL;
	}
	if (is_bound(R[cur])){
		if (!b[y][z]) goto DEL;
		if (tmp==-1) tmp=b[y][z];
		else if (tmp^b[y][z]) goto DEL;
	}
	if (is_bound(D[cur])){
		if (!c[x][z]) goto DEL;
		if (tmp==-1) tmp=c[x][z];
		else if (tmp^c[x][z]) goto DEL;
	}
	if (is_bound(U[cur])){
		if (!d[x][z]) goto DEL;
		if (tmp==-1) tmp=d[x][z];
		else if (tmp^d[x][z]) goto DEL;
	}
	if (is_bound(F[cur])){
		if (!e[x][y]) goto DEL;
		if (tmp==-1) tmp=e[x][y];
		else if (tmp^e[x][y]) goto DEL;
	}
	if (is_bound(B[cur])){
		if (!f[x][y]) goto DEL;
		if (tmp==-1) tmp=f[x][y];
		else if (tmp^f[x][y]) goto DEL;
	}
	return;
DEL:
	mrk[cur]=1;
	R[L[cur]]=R[cur]; L[R[cur]]=L[cur];
	U[D[cur]]=U[cur]; D[U[cur]]=D[cur];
	F[B[cur]]=F[cur]; B[F[cur]]=B[cur];
	int a,b,c;
	getid(L[cur],a,b,c); dfs(a,b,c);
	getid(R[cur],a,b,c); dfs(a,b,c);
	getid(D[cur],a,b,c); dfs(a,b,c);
	getid(U[cur],a,b,c); dfs(a,b,c);
	getid(F[cur],a,b,c); dfs(a,b,c);
	getid(B[cur],a,b,c); dfs(a,b,c);
}
int col[4000010];
int main()
{
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++){
		a[i].resize(k+1);
		for (int j=1;j<=k;j++) a[i][j]=read();
	}
	for (int i=1;i<=m;i++){
		b[i].resize(k+1);
		for (int j=1;j<=k;j++) b[i][j]=read();
	}
	for (int i=1;i<=n;i++){
		c[i].resize(k+1);
		for (int j=1;j<=k;j++) c[i][j]=read();
	}
	for (int i=1;i<=n;i++){
		d[i].resize(k+1);
		for (int j=1;j<=k;j++) d[i][j]=read();
	}
	for (int i=1;i<=n;i++){
		e[i].resize(m+1);
		for (int j=1;j<=m;j++) e[i][j]=read();
	}
	for (int i=1;i<=n;i++){
		f[i].resize(m+1);
		for (int j=1;j<=m;j++) f[i][j]=read();
	}
	for (int i=0;i<=n+1;i++)
		for (int j=0;j<=m+1;j++)
			for (int u=0;u<=k+1;u++){  //caution u
				int x=gethash(i,j,u);
				if (i) L[x]=gethash(i-1,j,u);
				if (i<=n) R[x]=gethash(i+1,j,u);
				if (j) D[x]=gethash(i,j-1,u);
				if (j<=m) U[x]=gethash(i,j+1,u);
				if (u) F[x]=gethash(i,j,u-1);
				if (u<=k) B[x]=gethash(i,j,u+1);
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			dfs(i,j,1),dfs(i,j,k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++)
			dfs(i,1,j),dfs(i,m,j);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=k;j++)
			dfs(1,i,j),dfs(n,i,j);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=k;j++){
			int x=gethash(0,i,j),y=gethash(n+1,i,j);
			if (a[i][j]){
				if (R[x]==y) return puts("-1"),0;
				col[R[x]]=a[i][j];
			}
			if (b[i][j]){
				if (L[y]==x) return puts("-1"),0;
				col[L[y]]=b[i][j];
			}
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++){
			int x=gethash(i,0,j),y=gethash(i,m+1,j);
			if (c[i][j]){
				if (U[x]==y) return puts("-1"),0;
				col[U[x]]=c[i][j];
			}
			if (d[i][j]){
				if (D[y]==x) return puts("-1"),0;
				col[D[y]]=d[i][j];
			}
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			int x=gethash(i,j,0),y=gethash(i,j,k+1);
			if (e[i][j]){
				if (B[x]==y) return puts("-1"),0;
				col[B[x]]=e[i][j];
			}
			if (f[i][j]){
				if (F[y]==x) return puts("-1"),0;
				col[F[y]]=f[i][j];
			}
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int u=1;u<=k;u++)
				print(col[gethash(i,j,u)]),putchar(' ');
	puts("");
	return 0;
}