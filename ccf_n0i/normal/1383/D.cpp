#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,j,a[255][255],r[255],c[255],f[62555],g[62555],b[255][255],col[255][255],sn,sm,vv[255][255];
vector<pair<int,int> > v;
/*void incsn(){
	sn++;
	int i;
	rep(i,sm) v.push_back(make_pair(sn,i));
}
void incsm(){
	sm++;
	int i;
	rep(i,sn) v.push_back(make_pair(i,sm));
}*/
void dfs(int x,int y){
	if(b[x][y]) return;
	if(col[x][y]) return;
	col[x][y]=1;
	dfs(x-1,y);dfs(x,y+1);
}
void gzz(int x,int y){
	if(b[x][y]||vv[x][y])return;
	if(col[x][y]&&b[x-1][y]&&b[x][y+1]){
		vv[x][y]=1;
		v.push_back(make_pair(x,y));
	}
	if(!col[x][y]&&b[x+1][y]&&b[x][y-1]){
		vv[x][y]=1;
		v.push_back(make_pair(x,y));
	}
}
void gz(int x,int y){
	if(x>1)gzz(x-1,y);
	if(x<n)gzz(x+1,y);
	if(y>1)gzz(x,y-1);
	if(y<m)gzz(x,y+1);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n){
		rep(j,m){
			scanf("%d",&a[i][j]);
			r[i]=max(r[i],a[i][j]);
			c[j]=max(c[j],a[i][j]);
		}
	}
	rep(i,n) f[r[i]]=1;
	rep(i,m) g[c[i]]=1;
	for(i=n*m;i;i--){
		if(f[i]&&g[i]){
			sn++;sm++;
			b[sn][sm]=i;
			continue;
		}
		if(f[i]){
			sn++;
			b[sn][sm]=i;
			continue;
		}
		if(g[i]){
			sm++;
			b[sn][sm]=i;
			continue;
		}
	}
	if(!b[n][1]){
		dfs(n,1);
	}
	memset(b,0,sizeof(b));
	sn=sm=0;
	for(i=n*m;i;i--){
		if(f[i]&&g[i]){
			sn++;sm++;
			b[sn][sm]=i;
			gz(sn,sm);
			continue;
		}
		if(f[i]){
			sn++;
			b[sn][sm]=i;
			gz(sn,sm);
			continue;
		}
		if(g[i]){
			sm++;
			b[sn][sm]=i;
			gz(sn,sm);
			continue;
		}
		int tx,ty;
		b[tx=v.back().first][ty=v.back().second]=i;
		v.pop_back();
		gz(tx,ty);
	}
	rep(i,n){
		rep(j,m){
			printf("%d%c",b[i][j],(j==m?'\n':' '));
		}
	}
	return 0;
}