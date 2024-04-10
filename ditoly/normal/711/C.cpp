#include<cstdio>
#include<cstring>
void read(int&x)
{
	x=0;char c;
	do c=getchar();while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
#include<iostream>
using namespace std;
#define MAX 100
#define ll long long
int c[MAX+5],p[MAX+5][MAX+5];
ll f[MAX+5][MAX+5][MAX+5];
void renew(ll&a,ll b){if(a<0||(b>=0&&b<a))a=b;};
int main()
{
	int n,m,k,i,j,t,mnp;ll mn,mnn,x;
	read(n);read(m);read(k);
	for(i=1;i<=n;i++)read(c[i]);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)read(p[i][j]);
	memset(f,-1,sizeof(f));
	if(c[1])f[1][1][c[1]]=0;
	else for(t=1;t<=m;t++)f[1][1][t]=p[1][t];
	for(i=2;i<=n;i++)for(j=1;j<=k;j++)
	{
		for(mn=mnn=-1,t=1;t<=m;t++)
		{
			x=f[i-1][j-1][t];
			if(x>=0&&(mn<0||x<mn)){mnn=mn;mn=x;mnp=t;}
			else renew(mnn,x);
		}
		if(c[i])
		{
			if(c[i]!=mnp)renew(f[i][j][c[i]],mn);
			else renew(f[i][j][c[i]],mnn);
			renew(f[i][j][c[i]],f[i-1][j][c[i]]);
		}
		else for(t=1;t<=m;t++)
		{
			if(t!=mnp){if(mn>=0)renew(f[i][j][t],mn+p[i][t]);}
			else{if(mnn>=0)renew(f[i][j][t],mnn+p[i][t]);}
			if(f[i-1][j][t]>=0)renew(f[i][j][t],f[i-1][j][t]+p[i][t]);
		}
	}
	for(mn=-1,t=1;t<=m;t++)renew(mn,f[n][k][t]);
	cout<<mn;
}