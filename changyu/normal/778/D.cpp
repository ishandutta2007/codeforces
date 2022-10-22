#include<bits/stdc++.h>
const int N=53,S=1e5+3;
int n,m,ansxa[S],ansya[S],ka,ansxb[S],ansyb[S],kb,f;
char sc[N][N],a[N][N],b[N][N];
inline void Rotatea(int x,int y){
	if(a[x][y]=='L')
		a[x][y]='U',a[x][y+1]='U',a[x+1][y]='D',a[x+1][y+1]='D';
	else
		a[x][y]='L',a[x][y+1]='R',a[x+1][y]='L',a[x+1][y+1]='R';
	++ka,ansxa[ka]=x,ansya[ka]=y;
}
void Constructa(int x,int y,char l){
	int xx,yy;
	xx=x,yy=y;
	l=='L'?++xx:++yy;
	if(a[xx][yy]!=l)Constructa(xx,yy,a[xx][yy]);
	Rotatea(x,y);
}
inline void Rotateb(int x,int y){
	if(b[x][y]=='L')
		b[x][y]='U',b[x][y+1]='U',b[x+1][y]='D',b[x+1][y+1]='D';
	else
		b[x][y]='L',b[x][y+1]='R',b[x+1][y]='L',b[x+1][y+1]='R';
	++kb,ansxb[kb]=x,ansyb[kb]=y;
}
void Constructb(int x,int y,char l){
	int xx,yy;
	xx=x,yy=y;
	l=='L'?++xx:++yy;
	if(b[xx][yy]!=l)Constructb(xx,yy,b[xx][yy]);
	Rotateb(x,y);
}
signed main(){
	scanf("%d%d",&n,&m);
	f=n&1;
	for(int i=1;i<=n;i++){
		scanf("%s",sc[i]+1);
		for(int j=1;j<=m;j++)
			if(f){
				if(sc[i][j]=='L')a[j][i]='U';
				if(sc[i][j]=='R')a[j][i]='D';
				if(sc[i][j]=='U')a[j][i]='L';
				if(sc[i][j]=='D')a[j][i]='R';
			}
			else
				a[i][j]=sc[i][j];
	}
	for(int i=1;i<=n;i++){
		scanf("%s",sc[i]+1);
		for(int j=1;j<=m;j++)
			if(f){
				if(sc[i][j]=='L')b[j][i]='U';
				if(sc[i][j]=='R')b[j][i]='D';
				if(sc[i][j]=='U')b[j][i]='L';
				if(sc[i][j]=='D')b[j][i]='R';
			}
			else
				b[i][j]=sc[i][j];
	}
	if(f)std::swap(n,m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(a[i][j]=='L')
			Constructa(i,j,'L');
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(b[i][j]=='L')
			Constructb(i,j,'L');
	printf("%d\n",ka+kb);
	for(int i=1;i<=ka;i++)f?printf("%d %d\n",ansya[i],ansxa[i]):printf("%d %d\n",ansxa[i],ansya[i]);
	for(int i=kb;i>=1;i--)f?printf("%d %d\n",ansyb[i],ansxb[i]):printf("%d %d\n",ansxb[i],ansyb[i]);
	return 0;
}