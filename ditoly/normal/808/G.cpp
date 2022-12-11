#include<cstdio>
#include<cstring>
#define MN 100000
char a[MN+5],b[MN+5];
int nx[MN+5],t[MN+5][26],f[2][MN+5];
inline void r(int&a,int b){if(b>a)a=b;}
int main()
{
	int n,i,j,k,p,q,ans=0;
	scanf("%s%s",a+1,b+1);n=strlen(b+1);
	for(i=2,j=0;b[i];++i)
	{
		while(j&&b[i]!=b[j+1])j=nx[j];
		if(b[i]==b[j+1])++j;
		nx[i]=j;
	}
	for(i=0;i<n;++i)for(j=0;j<26;++j)
		if(b[i+1]-'a'==j)t[i][j]=i+1;
		else t[i][j]=t[nx[i]][j];
	memset(f,200,sizeof(f));f[0][0]=0;
	for(i=1,p=1,q=0;a[i];++i,p^=1,q^=1)
	{
		memset(f[p],200,sizeof(f[p]));
		for(j=0;j<n;++j)if(f[q][j]>f[q][n])
		{
			for(k=a[i]=='?'?0:a[i]-'a';k<=(a[i]=='?'?25:a[i]-'a');++k)
				if(t[j][k]==n)r(f[p][nx[n]],f[q][j]+1);
				else r(f[p][t[j][k]],f[q][j]);
		}
	}
	for(j=0;j<n;++j)r(ans,f[q][j]);
	printf("%d",ans);
}