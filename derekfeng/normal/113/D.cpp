#include <bits/stdc++.h>
using namespace std;
typedef double db;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
int n,m,A,B,ID[23][23],tot,sz[23];
db mat[502][502],p[23];
vector<int>g[23];
int I(int x,int y){
	return ID[x][y];
}
void init(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ID[i][j]=++tot;
}
void Init(){
	mat[I(A,B)][tot+1]=-1.0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			mat[I(i,j)][I(i,j)]-=1.0;
			if (i!=j) mat[I(i,j)][I(i,j)]+=p[i]*p[j];
			for (int k=0;k<g[i].size();k++)
				for (int l=0;l<g[j].size();l++)
					if (g[i][k]!=g[j][l])
						mat[I(i,j)][I(g[i][k],g[j][l])]+=(1.0-p[g[i][k]])*(1.0-p[g[j][l]])/sz[g[i][k]]/sz[g[j][l]];
			for (int k=0;k<g[i].size();k++)
				if (g[i][k]!=j)
					mat[I(i,j)][I(g[i][k],j)]+=p[j]*(1.0-p[g[i][k]])/sz[g[i][k]];
			for (int k=0;k<g[j].size();k++)
				if (g[j][k]!=i)
					mat[I(i,j)][I(i,g[j][k])]+=p[i]*(1.0-p[g[j][k]])/sz[g[j][k]];
		}
}
void Gauss_Jordan(){
	for (int i=1;i<=tot;i++){
		int iter=i;
		for (int j=i+1;j<=tot;j++) if (fabs(mat[iter][i])<fabs(mat[j][i])) iter=j;
		swap(mat[i],mat[iter]);
		for (int j=tot+1;j>=i;j--) mat[i][j]/=mat[i][i];
		for (int j=1;j<=tot;j++) if (j!=i)
			for (int k=tot+1;k>=i;k--)
				mat[j][k]-=mat[i][k]*mat[j][i];
	}
}
int main(){
	read(n),read(m),read(A),read(B);
	for (int i=0;i<m;i++){
		int x,y;read(x),read(y),g[x].push_back(y),g[y].push_back(x); 
	}
	for (int i=1;i<=n;i++) scanf("%lf",&p[i]),sz[i]=g[i].size();
	init(),Init(),Gauss_Jordan();
	for (int i=1;i<=n;i++) printf("%.6lf ",mat[I(i,i)][tot+1]);
}