#include<cstdio>
#define MN 50
#define MK 100000
char s[MN+5][MN+5];
int n,m,x[MK+5],y[MK+5],xn,cnt,t,k[256];
void solve()
{
	int i,j;
	for(i=k[t]=0;i<n;++i)
	{
		scanf("%s",s[i]);
		for(j=0;j<m;++j)++k[s[i][j]];
	}
	while(k[t])
	{
		for(i=0;i<n;++i)for(j=0;j<m;++j)if(s[i][j]=='U'&&s[i][j+1]=='U')
			x[++cnt]=i+1,y[cnt]=j+1,s[i][j]=s[i+1][j]='L',s[i][j+1]='R',k['U']-=2,k['L']+=2;
		if(!k[t])return;
		for(i=0;i<n;++i)for(j=0;j<m;++j)if(s[i][j]=='L'&&s[i+1][j]=='L')
			x[++cnt]=i+1,y[cnt]=j+1,s[i][j]=s[i][j+1]='U',s[i+1][j]='D',k['U']+=2,k['L']-=2;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	t=n&1?'U':'L';
	solve();xn=cnt;
	solve();printf("%d\n",cnt);
	for(int i=1;i<=xn;++i)printf("%d %d\n",x[i],y[i]);
	for(int i=cnt;i>xn;--i)printf("%d %d\n",x[i],y[i]);
}