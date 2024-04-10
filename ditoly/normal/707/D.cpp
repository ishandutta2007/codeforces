#include<cstdio>
void read(int&x)
{
	x=0;char c;
	do{c=getchar();}while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
#include<vector>
using namespace std;
#define MAX 1000
#define MAXQ 100000
int n,m,f[MAX+5][MAX+5],ans,sum[MAX+5];
int s[MAXQ+5][3],as[MAXQ+5];
vector<int> v[MAXQ+5];
void place(int x,int y)
{
	f[x][y]=!f[x][y];
	ans++;sum[x]++;
}
void remove(int x,int y)
{
	f[x][y]=!f[x][y];
	ans--;sum[x]--;
}
void invert(int x)
{
	f[x][0]=!f[x][0];
	ans-=sum[x];
	sum[x]=m-sum[x];
	ans+=sum[x];
}
void dfs(int k)
{
	int o=0,t,x,y,i;
	t=s[k][0];x=s[k][1];y=s[k][2];
	if(t==1)if(f[x][y]^f[x][0]^1)place(x,y);else o=1;
	if(t==2)if(f[x][y]^f[x][0])remove(x,y);else o=1;
	if(t==3)invert(x);
	as[k]=ans;
	for(i=0;i<v[k].size();i++)dfs(v[k][i]);
	if(o)return;
	if(t==1)remove(x,y);
	if(t==2)place(x,y);
	if(t==3)invert(x);
}
int main()
{
	int q,x,y,i;
	read(n);read(m);read(q);
	for(i=1;i<=q;i++)
	{
		read(s[i][0]);read(s[i][1]);
		if(s[i][0]<3)read(s[i][2]);
		if(s[i][0]<4)v[i-1].push_back(i);
		else v[s[i][1]].push_back(i);
	}
	dfs(0);
	for(i=1;i<=q;i++)printf("%d\n",as[i]);
}