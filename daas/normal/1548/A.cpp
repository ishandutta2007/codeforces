#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<set>
#define ll long long
using namespace std;
const int MAXN=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,pd[MAXN],ans,q;
multiset<int> T[MAXN];
multiset<int> :: iterator id;
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		T[u].insert(v);
		T[v].insert(u);
	}
	for(int i=1;i<=n;++i) if(!T[i].size() || (*(T[i].rbegin())<=i)) ++ans,pd[i]=1;
	q=read();
	while(q--)
	{
		int type=read();
		if(type==1)
		{
			int u=read(),v=read();
			if(pd[u]) --ans,pd[u]=0;
			if(pd[v]) --ans,pd[v]=0;
			T[u].insert(v);
			T[v].insert(u);
			if(!T[u].size() || (*(T[u].rbegin())<=u)) ++ans,pd[u]=1;
			if(!T[v].size() || (*(T[v].rbegin())<=v)) ++ans,pd[v]=1;
		}
		if(type==2)
		{
			int u=read(),v=read();
			if(pd[u]) --ans,pd[u]=0;
			if(pd[v]) --ans,pd[v]=0;
			T[u].erase(v);
			T[v].erase(u);
			if(!T[u].size() || (*(T[u].rbegin())<=u)) ++ans,pd[u]=1;
			if(!T[v].size() || (*(T[v].rbegin())<=v)) ++ans,pd[v]=1;
		}
		if(type==3) printf("%d\n",ans);
	}
	return 0;
}
//ore no turn,draw!