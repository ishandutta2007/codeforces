#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
ll g[200][200];
string a,b;
int lena,lenb;
ll n,ans;
char str[100005];
ll dis[200][200];
void floyd()
{
	int i,j,k;
	for(i='a';i<='z';i++)
	{
		for(j='a';j<='z';j++)
		{
			if(i==j) dis[i][j]=0;
			else dis[i][j]=g[i][j];
		}
	}
	for(k='a';k<='z';k++)
	{
		for(i='a';i<='z';i++)
		     for(j='a';j<='z';j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	return;
}
int main()
{
	cin>>a>>b;
	lena=a.length();lenb=b.length();
	if(lena!=lenb) 
	{
		cout<<-1;
		return 0;
	}
	cin>>n;
	int i,j;
	memset(g,0x3f,sizeof(g));
	for(i=1;i<=n;i++)
	{
		char x,y;
		ll z;
		cin>>x>>y>>z;
		g[x][y]=min(g[x][y],z);
	}
	floyd();
	for(i=0;i<lena;i++)
	{
		ll tmp=inf;
		char mn='\0';
		char x=a[i],y=b[i];
		for(j='a';j<='z';j++) 
		{
			if(tmp>dis[x][j]+dis[y][j])
			{
				mn=j;
				tmp=dis[x][j]+dis[y][j];
			}			
		}
		str[i]=mn;
		if(tmp==inf) 
		{
			cout<<-1;
			return 0;
		}
		ans+=tmp;
	}
	cout<<ans<<endl;
	for(i=0;i<lena;i++) cout<<str[i];
	return 0;
}