#include<cstdio>
const int Dx[8]={1,1,1,0,0,-1,-1,-1},Dy[8]={1,0,-1,1,-1,1,0,-1};
const int N=1002;
int n,m;char a[N][N];
inline bool In(int a,int b){return a&&a<=n&&b&&b<=m;}
int main()
{
	int f;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
	  int ii,jj,iii,jjj;
	  if(a[i][j]=='#')
		for(int k=0;k<8;k++)
		{
		  f=1;
		  ii=i+Dx[k];jj=j+Dy[k];
		  if(In(ii,jj))for(int l=0;l<8;l++){
			iii=ii+Dx[l];jjj=jj+Dy[l];
			if(!In(iii,jjj)||a[iii][jjj]=='.')
			  {f=0;break;}
		  }else f=0;
		  if(f)break;
		}
	  if(!f)return 0*puts("NO");
	}return 0*puts("YES");
}