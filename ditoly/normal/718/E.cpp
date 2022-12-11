#include<cstdio>
#include<algorithm>
using namespace std; 
#define MN 100000
char s[MN+5];
int d[8][MN+5],D[8][8],c[8][1<<8],DD[8][1<<8][8][1<<8],S[MN+5],q[MN+5],qn;
long long SS[16];
int main()
{
	int n,i,j,k,l,x;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;++i)s[i]-='a';
	for(i=0;i<8;++i)
	{
		for(qn=0,D[i][i]=j=1;j<=n;++j)if(s[j]==i)d[i][q[++qn]=j]=1;
		for(j=1;j<=qn;++j)
		{
			if(!D[i][s[x=q[j]]])
			{
				D[i][s[x]]=d[i][x];
				for(k=1;k<=n;++k)if(s[k]==s[x]&&!d[i][k])d[i][q[++qn]=k]=d[i][x]+1;
			}
			if(x>1&&!d[i][x-1])d[i][q[++qn]=x-1]=d[i][x]+1;
			if(x<n&&!d[i][x+1])d[i][q[++qn]=x+1]=d[i][x]+1;
		}
	}
	for(i=1;i<=n;++c[s[i]][S[i]],++i)
	for(j=0;j<8;++j)S[i]|=d[j][i]-D[j][s[i]]<<j;
	for(i=0;i<8;++i)for(j=0;j<1<<8;++j)if(c[i][j])for(k=0;k<8;++k)for(l=0;l<1<<8;++l)if(c[k][l])
	{
		DD[i][j][k][l]=1e9;
		for(x=0;x<8;++x)if(D[x][i]&&D[x][k])
			DD[i][j][k][l]=min(DD[i][j][k][l],(D[x][i]+((j>>x)&1))+(D[x][k]+((l>>x)&1))-1);
		SS[DD[i][j][k][l]]+=1LL*c[i][j]*c[k][l];
	}
	for(SS[i=1]-=n;i<16;++i)SS[i]>>=1;
	for(i=1;i<=n;++i)for(j=1;j<16&&i+j<=n;++j)
		if(j<DD[s[i]][S[i]][s[i+j]][S[i+j]])--SS[DD[s[i]][S[i]][s[i+j]][S[i+j]]],++SS[j];
	for(i=16;i--;)if(SS[i])break;
	printf("%d %lld\n",i,SS[i]);
}