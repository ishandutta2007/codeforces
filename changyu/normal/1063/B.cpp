#include<cstdio>
const int N=2002,M=4*N*N,Dx[4]={0,0,1,-1},Dy[4]={1,-1,0,0};
inline int Mod(int a){return(a%M+M)%M;}
char a[N][N];int n,m,sx,sy,g,h,d[N][N],qx[M],qy[M],qd[M],l,r,s;
int main()
{
	int x,y,xx,yy;
	scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&g,&h);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	d[sx][sy]=1;qx[0]=sx;qy[0]=sy;
	for(;l<=r;)
	{
	  x=qx[Mod(l)];y=qy[Mod(l)];
	  if(d[x][y]&&qd[Mod(l)]>d[x][y]){l++;continue;}
	  l++;
	  for(int k=0;k<4;k++)
	  {
		xx=x+Dx[k];yy=y+Dy[k];
		if(xx<=n&&xx&&yy&&yy<=m&&a[xx][yy]=='.'){
		  if(k&&(d[x][y]<d[xx][yy]||!d[xx][yy]))
			qd[Mod(--l)]=d[xx][yy]=d[x][y],qx[Mod(l)]=xx,qy[Mod(l)]=yy;
		  if(!k&&(d[x][y]+1<d[xx][yy]||!d[xx][yy]))
			qd[Mod(++r)]=d[xx][yy]=d[x][y]+1,qx[Mod(r)]=xx,qy[Mod(r)]=yy;
		}
	  }
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)if(a[i][j]=='.'&&d[i][j])
	 	d[i][j]--,s+=d[i][j]-j+sy<=g&&d[i][j]<=h;
	printf("%d",s);
	return 0;
}