#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<assert.h>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define ok(dx,dy,x,y) tab[dx+2][dy+2][x][y]

int n,m,K,T,W;
char getnext(){
	static char str[3];
	scanf("%s",str);
	return str[0];
}
char mp[210][210],w[1000010];
struct Rec{
	int t,x,y;
}rec[25];
bool operator<(Rec x,Rec y){return x.t>y.t;}
int dp[2][210][210]; bool C;
int SX,SY,TX,TY;
bool tab[5][5][210][210];  //dx+2, dy+2
inline void check(int &x,int &y){if (y>x) x=y;}
int main()
{
	n=read(),m=read(),K=read(),W=read(),T=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			mp[i][j]=getnext();
			if (mp[i][j]=='M') SX=i,SY=j,mp[i][j]='S';
			else if (mp[i][j]=='P') TX=i,TY=j,mp[i][j]='S';
		}
		
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (mp[i][j]=='L') continue;
			ok(0,0,i,j)=1;
			ok(0,1,i,j)=j+1<=m&&mp[i][j+1]!='L';
			ok(0,2,i,j)=j+2<=m&&mp[i][j+1]!='L'&&mp[i][j+2]!='L';
			ok(0,-1,i,j)=j-1>=1&&mp[i][j-1]!='L';
			ok(0,-2,i,j)=j-2>=1&&mp[i][j-1]!='L'&&mp[i][j-2]!='L';
			ok(1,0,i,j)=i+1<=n&&mp[i+1][j]!='L';
			ok(2,0,i,j)=i+2<=n&&mp[i+1][j]!='L'&&mp[i+2][j]!='L';
			ok(-1,0,i,j)=i-1>=1&&mp[i-1][j]!='L';
			ok(-2,0,i,j)=i-2>=1&&mp[i-1][j]!='L'&&mp[i-2][j]!='L';
			ok(-1,1,i,j)=i-1>=1&&j+1<=m&&(mp[i-1][j]!='L'||mp[i][j+1]!='L')&&mp[i-1][j+1]!='L';
			ok(-1,-1,i,j)=i-1>=1&&j-1>=1&&(mp[i-1][j]!='L'||mp[i][j-1]!='L')&&mp[i-1][j-1]!='L';
			ok(1,1,i,j)=i+1<=n&&j+1<=m&&(mp[i+1][j]!='L'||mp[i][j+1]!='L')&&mp[i+1][j+1]!='L';
			ok(1,-1,i,j)=i+1<=n&&j-1>=1&&(mp[i+1][j]!='L'||mp[i][j-1]!='L')&&mp[i+1][j-1]!='L';
		}
		
	for (int i=1;i<=T;i++) w[i]=getnext();
	for (int i=1;i<=W;i++) rec[i].x=read()+1,rec[i].y=read()+1,rec[i].t=read();
	//puts("test");
	int lim=(W+1)*K;
	sort(rec+1,rec+W+1); while (W&&rec[W].t==0) W--;
	memset(dp[C],-1,sizeof dp[C]); dp[C][SX][SY]=K;
	for (int t=1;t<=T&&t<=lim;t++){
		C^=1; memset(dp[C],-1,sizeof dp[C]);
		int dx,dy;
		if (w[t]=='C') dx=dy=0;
		else if (w[t]=='N') dx=-1,dy=0;
		else if (w[t]=='S') dx=1,dy=0;
		else if (w[t]=='W') dx=0,dy=-1;
		else if (w[t]=='E') dx=0,dy=1;
		else assert(0);
		//printf("test %d %d  %c\n",dx,dy,w[t]);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				if (dp[C^1][i][j]<1) continue;
				int s=dp[C^1][i][j]-1;
				if (ok(dx,dy,i,j)) check(dp[C][i+dx][j+dy],s);
				if (ok(dx+1,dy,i,j)) check(dp[C][i+dx+1][j+dy],s);
				if (ok(dx-1,dy,i,j)) check(dp[C][i+dx-1][j+dy],s);
				if (ok(dx,dy+1,i,j)) check(dp[C][i+dx][j+dy+1],s);
				if (ok(dx,dy-1,i,j)) check(dp[C][i+dx][j+dy-1],s);
				/*printf("%d %d -> %d %d: %d\n",i,j,i+dx,j+dy,ok(dx,dy,i,j));
				printf("%d %d -> %d %d: %d\n",i,j,i+dx+1,j+dy,ok(dx+1,dy,i,j));
				printf("%d %d -> %d %d: %d\n",i,j,i+dx-1,j+dy,ok(dx-1,dy,i,j));
				printf("%d %d -> %d %d: %d\n",i,j,i+dx,j+dy+1,ok(dx,dy+1,i,j));
				printf("%d %d -> %d %d: %d\n",i,j,i+dx,j+dy-1,ok(dx,dy-1,i,j));*/
			}
		while (W&&rec[W].t==t){
			int x=rec[W].x,y=rec[W].y;
			if (~dp[C][x][y]) dp[C][x][y]=K;
			W--;
		}
		/*printf("done %d\n",t);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				printf("%d%c",dp[C][i][j]," \n"[j==m]);*/
		if (~dp[C][TX][TY]) return printf("%d\n",t),0;
	}
	puts("-1");
	return 0;
}