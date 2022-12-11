#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,a[51][51],b[51][51];
int dpa[51][51][51][51],dpb[51][51][51][51];
vector<pair<pair<int,int>,pair<int,int> > >p[110];
int main()
{
	scanf("%d",&n);
	int x;
	a[1][1]=1;
	for(int s=4;s<=2*n-2;s+=2)
		for(int i=1,j=s-i;i<=n;++i,--j)
			if(j>0&&j<=n)
			{
				if(i>2)printf("? %d %d %d %d\n",i-2,j,i,j),fflush(stdout),scanf("%d",&x),x^=1,a[i][j]=a[i-2][j]^x;
				else if(j>2)printf("? %d %d %d %d\n",i,j-2,i,j),fflush(stdout),scanf("%d",&x),x^=1,a[i][j]=a[i][j-2]^x;
				else printf("? %d %d %d %d\n",i-1,j-1,i,j),fflush(stdout),scanf("%d",&x),x^=1,a[i][j]=a[i-1][j-1]^x;
			}
	for(int i=4;i<=n;i+=2)printf("? %d %d %d %d\n",1,i-2,1,i),fflush(stdout),scanf("%d",&x),x^=1,a[1][i]=a[1][i-2]^x;
	printf("? %d %d %d %d\n",1,n-1,2,n),fflush(stdout),scanf("%d",&x),x^=1,a[2][n]=a[1][n-1]^x;
	for(int i=n-2;i>=1;i-=2)printf("? %d %d %d %d\n",2,i,2,i+2),fflush(stdout),scanf("%d",&x),x^=1,a[2][i]=a[2][i+2]^x;
	for(int i=3;i<=n;++i)
		for(int j=1;j<=n;++j)
			if((i+j)&1)
			{
				printf("? %d %d %d %d\n",i-2,j,i,j);fflush(stdout);
				scanf("%d",&x),x^=1;
				a[i][j]=a[i-2][j]^x;
			}
	memcpy(b,a,sizeof(a));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if((i+j)&1)b[i][j]^=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=i;k<=n;++k)
				for(int l=j;l<=n;++l)
					p[k+l-i-j].push_back(make_pair(make_pair(i,j),make_pair(k,l)));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dpa[i][j][i][j]=1;	
	for(auto u:p[1])dpa[u.first.first][u.first.second][u.second.first][u.second.second]=a[u.first.first][u.first.second]==a[u.second.first][u.second.second];
	for(int len=2;len<=2*n-2;++len)
		for(auto u:p[len])dpa[u.first.first][u.first.second][u.second.first][u.second.second]=a[u.first.first][u.first.second]==a[u.second.first][u.second.second]&&(dpa[u.first.first+1][u.first.second][u.second.first-1][u.second.second]||dpa[u.first.first][u.first.second+1][u.second.first-1][u.second.second]||dpa[u.first.first+1][u.first.second][u.second.first][u.second.second-1]||dpa[u.first.first][u.first.second+1][u.second.first][u.second.second-1]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dpb[i][j][i][j]=1;	
	for(auto u:p[1])dpb[u.first.first][u.first.second][u.second.first][u.second.second]=b[u.first.first][u.first.second]==b[u.second.first][u.second.second];
	for(int len=2;len<=2*n-2;++len)
		for(auto u:p[len])dpb[u.first.first][u.first.second][u.second.first][u.second.second]=b[u.first.first][u.first.second]==b[u.second.first][u.second.second]&&(dpb[u.first.first+1][u.first.second][u.second.first-1][u.second.second]||dpb[u.first.first][u.first.second+1][u.second.first-1][u.second.second]||dpb[u.first.first+1][u.first.second][u.second.first][u.second.second-1]||dpb[u.first.first][u.first.second+1][u.second.first][u.second.second-1]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=i;k<=n;++k)
				for(int l=j;l<=n;++l)
					if(k+l-i-j>=2&&dpa[i][j][k][l]!=dpb[i][j][k][l])
					{
						printf("? %d %d %d %d\n",i,j,k,l);fflush(stdout);
						scanf("%d",&x);
						printf("!\n");
						if(dpa[i][j][k][l]==x)
						{
							for(int ii=1;ii<=n;++ii)
							{
								for(int jj=1;jj<=n;++jj)
									printf("%d",a[ii][jj]);
								printf("\n");
							}		
						}
						else
						{
							for(int ii=1;ii<=n;++ii)
							{
								for(int jj=1;jj<=n;++jj)
									printf("%d",b[ii][jj]);
								printf("\n");
							}	
						}
						fflush(stdout);
						return 0;
					}
				
	return 0;
}