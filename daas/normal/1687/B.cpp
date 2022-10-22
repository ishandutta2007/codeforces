#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,all,val[600],ans,id[600];
char s[600];
int cmp(int x,int y) {return val[x]>val[y];}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;++i) s[i]='0';
	for(int i=1;i<=m;++i)
	{
		s[i]='1';
		printf("? %s\n",s+1);
		fflush(stdout);
		val[i]=read();
		s[i]='0';
	}
	for(int i=1;i<=m;++i) s[i]='1',id[i]=i;
	sort(id+1,id+m+1,cmp);
	printf("? %s\n",s+1);
	fflush(stdout);
	ans=read();
	for(int i=1;i<m;++i)
	{
		s[id[i]]='0';
		printf("? %s\n",s+1);
		fflush(stdout);
		int v=read();
		if(ans-v!=val[id[i]]) ans=v;
		else s[id[i]]='1';
	}
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}
//ore no turn,draw!