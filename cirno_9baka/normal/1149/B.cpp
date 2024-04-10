#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353;
typedef long long ll;
int n,f[255][255][255],a,b,c,p[26][100005],i,j,k,u,sa[100005],sb[100005],sc[100005],q;
char s[100005],t,h;
int main(){
	scanf("%d %d",&n,&q);
	scanf("%s",s+1);
	for(i=0;i<26;i++)
	{
		p[i][n+1]=n+1;
		p[i][n+2]=n+1;
	}
	for(i=n;i>=1;i--)
	{
		for(j=0;j<26;j++)
			p[j][i]=p[j][i+1];
		p[s[i]-'a'][i]=i;
	}
	scanf("\n");
	while(q--)
	{
		scanf("%c",&t);
		if(t=='+')
		{
			scanf("%d %c",&u,&h);
			h-='a';
			if(u==1)
			{
				a++;
				sa[a]=h;
				for(i=0;i<=b;i++)
					for(j=0;j<=c;j++)
					{
						f[a][i][j]=p[h][f[a-1][i][j]+1];
						if(i!=0)
							f[a][i][j]=min(f[a][i][j],p[sb[i]][f[a][i-1][j]+1]);
						if(j!=0)
							f[a][i][j]=min(f[a][i][j],p[sc[j]][f[a][i][j-1]+1]);
					}
			}
			if(u==2)
			{
				b++;
				sb[b]=h;
				for(i=0;i<=a;i++)
					for(j=0;j<=c;j++)
					{
						f[i][b][j]=p[h][f[i][b-1][j]+1];
						if(i!=0)
							f[i][b][j]=min(f[i][b][j],p[sa[i]][f[i-1][b][j]+1]);
						if(j!=0)
							f[i][b][j]=min(f[i][b][j],p[sc[j]][f[i][b][j-1]+1]);
					}
			}
			if(u==3)
			{
				c++;
				sc[c]=h;
				for(i=0;i<=a;i++)
					for(j=0;j<=b;j++)
					{
						f[i][j][c]=p[h][f[i][j][c-1]+1];
						if(i!=0)
							f[i][j][c]=min(f[i][j][c],p[sa[i]][f[i-1][j][c]+1]);
						if(j!=0)
							f[i][j][c]=min(f[i][j][c],p[sb[j]][f[i][j-1][c]+1]);
					}
			}
		}
		else
		{
			scanf("%d",&u);
			if(u==1)
				a--;
			if(u==2)
				b--;
			if(u==3)
				c--;
		}
		if(f[a][b][c]!=n+1&&f[a][b][c]!=n+1)
			printf("YES\n");
		else
			printf("NO\n");
		scanf("\n");
	}
}