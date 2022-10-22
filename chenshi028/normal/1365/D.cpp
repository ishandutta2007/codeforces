#include<cstdio>
#include<cstring>
using namespace std;
template<class T>inline void read(T&a){
	char c=getchar();int f=1;a=0;
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') a=(a<<1)+(a<<3)+c-48,c=getchar();
	a*=f; 
}
template<class T>void write(T a){
	if(a<0) putchar('-'),a=-a;
	if(a>9) write(a/10);
	putchar(a%10+48);
}
void readc(char&c){c=getchar();while(c-'.'&&c-'#'&&c-'G'&&c-'B') c=getchar();}
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int T,m,n,qx[10000],qy[10000],hd,tl,tx,ty;char mz[100][100];bool vis[100][100],vg[100][100];
inline bool chk(int x,int y){for(int i=0;i<4;++i) if(mz[x+dx[i]][y+dy[i]]=='B') return false;return true;}
inline void slv(){
	read(m);read(n);
	memset(mz,0,sizeof mz);
	for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) readc(mz[i][j]);
	memset(vis,0,sizeof vis);
	if(chk(m,n)){vis[m][n]=1;qx[hd=tl=1]=m;qy[1]=n;
		while(tl>=hd){
			for(int k=0;k<4;++k){
				tx=qx[hd]+dx[k];ty=qy[hd]+dy[k];
				if(!vis[tx][ty]&&tx&&ty&&tx<=m&&ty<=n&&mz[tx][ty]-'#'&&mz[tx][ty]-'B'&&chk(tx,ty)) vis[tx][ty]=1,qx[++tl]=tx,qy[tl]=ty;
			}
			++hd;
		}
	}
	for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) if(mz[i][j]=='G'&&!vis[i][j]){printf("No\n");return;}
	printf("Yes\n");
}
int main(){read(T);while(T--) slv();return 0;}