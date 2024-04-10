#include<cstdio>
int n,m;
char map[110][110];
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={1,0,-1,1,-1,1,0,-1};
int main()
{
	int tmp;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%s",map[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (map[i][j]=='.'||map[i][j]<='8'&&map[i][j]>='1')
			{
				tmp=0;
				for (int k=0;k<8;k++)
				{
					int ii=i+dx[k],jj=j+dy[k];
					if (ii>0&&ii<=n&&jj>0&&jj<=m&&map[ii][jj]=='*')
						tmp++;
				}
				if (map[i][j]=='.'&&tmp||map[i][j]<='8'&&map[i][j]>='1'&&tmp!=map[i][j]-48)
				{
					puts("NO");
					return 0;
				}
			}
	puts("YES");
	return 0;
}