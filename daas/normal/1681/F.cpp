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
const int MAXN=5e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,father[MAXN],size[MAXN],id[MAXN],num[MAXN];
vector<pair<int,int> > mem[MAXN];
ll ans;
int cmp(int x,int y) {return num[x]<num[y];}
int z[MAXN][2],top;
int find(int k)
{
	if(father[k]!=k) return find(father[k]);
	return k;
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(size[x]>size[y]) swap(x,y);
	father[x]=y,size[y]+=size[x];
	z[++top][0]=x,z[top][1]=y;
}
void del(int k)
{
	while(top!=k)
	{
		int x=z[top][0],y=z[top][1];
		--top;
		father[x]=x;
		size[y]-=size[x];
	}
}
void insert(int l,int r)
{
	for(int i=l;i<=r;++i)
		for(int j=0;j<(int)mem[id[i]].size();++j)
			merge(mem[id[i]][j].first,mem[id[i]][j].second);
}
int dep;
void solve(int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<(int)mem[id[l]].size();++i)
		{
			int x=mem[id[l]][i].first,y=mem[id[l]][i].second;
			ans+=(ll)size[find(x)]*size[find(y)];
		}
		return;
	}
	int mid=(l+r)>>1;
	int tmp=top;
	insert(mid+1,r);
	solve(l,mid);
	del(tmp);
	//---------------
	insert(l,mid);
	solve(mid+1,r);
	del(tmp);
}
int main()
{
	n=read();
	//n=5e5;
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read(),c=read();
		//int u=i,v=i+1,c=i/300+1;
		mem[c].push_back(make_pair(u,v));
		++num[c];
	}
	for(int i=1;i<=n;++i) id[i]=father[i]=i,size[i]=1;
	int st=1; while(!id[st]) ++st;
	solve(st,n);
	printf("%lld\n",ans);
	return 0;
}
//ore no turn,draw!