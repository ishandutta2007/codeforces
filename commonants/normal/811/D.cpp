#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int n,m;
const int MX=111;
char a[MX][MX];
int dr[4]={0,1,0,-1},dc[4]={1,0,-1,0};//R D L U
char op[4];
int x,y;
bool flg=true;
void GetLRUD(){
	if(a[1][1]=='F'){flg=false;return;}
	if(a[1][2]=='*'){
		puts("U");fflush(stdout);
		scanf("%d%d",&x,&y);
		if(x==2)op[1]='U',op[3]='D';else op[1]='D',op[3]='U';
		putchar(op[3]);puts("");fflush(stdout);scanf("%d%d",&x,&y);
		for(int i=2;i<=n;i++){
			if(a[i][1]=='*')break;
			if(a[i][1]=='F'){
				while(x<i){
					putchar(op[1]);puts("");fflush(stdout);scanf("%d%d",&x,&y);
				}
				flg=false;return;
			}
		}
		while(a[x][2]=='*'){putchar(op[1]);puts("");fflush(stdout);scanf("%d%d",&x,&y);}
		if(a[x][2]=='F'){
			puts("R");fflush(stdout);scanf("%d%d",&x,&y);if(a[x][y]=='F'){flg=false;return;}
			puts("L");fflush(stdout);scanf("%d%d",&x,&y);if(a[x][y]=='F'){flg=false;return;}
		}else{
			puts("L");fflush(stdout);
			scanf("%d%d",&x,&y);
			if(y==2)op[0]='L',op[2]='R';else op[0]='R',op[2]='L';
		}
	}else{
		puts("L");fflush(stdout);
		scanf("%d%d",&x,&y);
		if(y==2)op[0]='L',op[2]='R';else op[0]='R',op[2]='L';
		putchar(op[2]);puts("");fflush(stdout);scanf("%d%d",&x,&y);
		for(int i=2;i<=m;i++){
			if(a[1][i]=='*')break;
			if(a[1][i]=='F'){
				while(y<i){
					putchar(op[0]);puts("");fflush(stdout);scanf("%d%d",&x,&y);
				}
				flg=false;return;
			}
		}
		while(a[2][y]=='*'){putchar(op[0]);puts("");fflush(stdout);scanf("%d%d",&x,&y);}
		if(a[2][y]=='F'){
			puts("U");fflush(stdout);scanf("%d%d",&x,&y);if(a[x][y]=='F'){flg=false;return;}
			puts("D");fflush(stdout);scanf("%d%d",&x,&y);if(a[x][y]=='F'){flg=false;return;}
		}else{
			puts("U");fflush(stdout);
			scanf("%d%d",&x,&y);
			if(x==2)op[1]='U',op[3]='D';else op[1]='D',op[3]='U';
		}
	}
}
typedef pair<int,int> pii;
#define fr first
#define se second
#define mp make_pair
pii q[MX*MX],fa[MX][MX];int vis[MX][MX],frd[MX][MX];
char sq[MX*MX];int sqc;
void wk(){
	int h=0,T=0;
	q[++T]=mp(x,y);vis[x][y]=1;fa[x][y]=mp(0,0);
	while(h<T){
		pii r=q[++h];
		for(int i=0;i<4;i++){
			pii t=mp(r.fr+dr[i],r.se+dc[i]);
			if(t.fr>=1&&t.fr<=n&&t.se>=1&&t.se<=m&&!vis[t.fr][t.se]&&a[t.fr][t.se]!='*'){
				vis[t.fr][t.se]=1;q[++T]=t;fa[t.fr][t.se]=r;frd[t.fr][t.se]=i;
			}
		}
	}
	int fx=0,fy=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='F')fx=i,fy=j;
	while(fa[fx][fy].fr){
		sq[++sqc]=op[frd[fx][fy]];pii t=fa[fx][fy];fx=t.fr,fy=t.se;
	}
	for(int i=sqc;i;i--)putchar(sq[i]),puts(""),fflush(stdout),scanf("%d%d",&x,&y);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);x=y=1;
	GetLRUD();
	if(flg)wk();
	return 0;
}