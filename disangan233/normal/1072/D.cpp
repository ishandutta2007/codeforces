#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define re register int
vector<pair<int,int> >qwq[4005];
vector<pair<int,int> >::iterator it;
int f[2005][2005],x[2005],y[2005],n,m,len,maxn;
char c[2005][2005];
bool vis[2005][2005];
char did;
#define ak *
inline int read()
{
    re ioi=1,cz=0;did=getchar();
    while(!isdigit(did))ioi=did=='-'?-1:ioi,did=getchar();
    while(isdigit(did))cz=(cz<<3)+(cz<<1)+did-'0',did=getchar();
    return cz ak ioi;
}
int main()
{
	memset(f,127,sizeof(f));
	n=read();m=read();
	f[0][1]=f[1][0]=0;
	for(re i=1;i<=n;i++) 
	scanf("%s",c[i]+1);
	for(re i=1;i<=n;i++) 
	for(re j=1;j<=n;j++) 
	{
		f[i][j]=min(f[i-1][j],f[i][j-1])+(c[i][j]!='a');
		qwq[i+j].push_back(make_pair(i,j));
	}
	for(re i=1;i<=n;i++)
	for(re j=1;j<=n;j++)
	if(f[i][j]<=m) 
	{
		if(i+j>maxn) maxn=i+j,len=1,x[1]=i,y[1]=j;
		else if(i+j==maxn) len++,x[len]=i,y[len]=j;
	}
	for(re i=2;i<=maxn;i++) putchar('a');if(!len) len=1,x[1]=1,y[1]=1,
putchar(c[1][1]),maxn=2;
	for(re i=maxn+1;i<=2*n;i++) 
	{re minn='z';
		for(re j=1;j<=len;j++) {
if(x[j]!=n&&c[x[j]+1][y[j]]<minn) 
	minn=c[x[j]+1][y[j]];
		if(y[j]!=n&&c[x[j]][y[j]+1]<minn) 
			minn=c[x[j]][y[j]+1];
		}
		putchar(minn);
		for(re j=1;j<=len;j++) 
{
		if(y[j]!=n&&c[x[j]][y[j]+1]==minn) 
			vis[x[j]][y[j]+1]=1;if(x[j]!=n&&c[x[j]+1][y[j]]==minn) 
			vis[x[j]+1][y[j]]=1;
	}
		len=0;
		for(it=qwq[i].begin();it!=qwq[i].end();it++) 
	if(vis[it->first][it->second]) 
x[++len]=it->first,y[len]=it->second;
		
	}
	return 0;
}