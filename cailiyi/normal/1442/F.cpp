#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define N 1000
#define M 100000
using namespace std;
int n,m,T,q[N+5],d[N+5],s[N+5];
int node[1<<20|5];
char a[10];
vector<int> e[N+5],change;
vector<pair<int,int> > add_edge,sub_edge;
inline void topo_sort()
{
	queue<int> que;
	for(int i=1;i<=n;++i) if(!d[i]) que.push(i);
	while(!que.empty())
	{
		int x=que.front();q[++q[0]]=x,que.pop();
		for(int y:e[x]) if(!(--d[y])) que.push(y);
	}
}
inline int popbit(int x)
{
	int ret=0;
	while(x) x>>=1,++ret;
	return ret;
}
inline void read()
{
	scanf("%d %d %d",&n,&m,&T);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d %d",&u,&v),e[u].push_back(v),++d[v];
}
inline void init()
{
	change.push_back(0);
	for(int k=0,last=0,temp;temp=change.size(),k<3;last=temp,++k)
		for(int i=change.size()-1;i>=last;--i)
			for(int j=popbit(change[i]);j<20;++j)
				if(!((change[i]>>j)&1)) change.push_back(change[i]|(1<<j));
}
inline void print_edges()
{
	printf("%u\n",add_edge.size()+sub_edge.size());
	for(pair<int,int> edge:add_edge)
		printf("+ %d %d\n",edge.first,edge.second);
	for(pair<int,int> edge:sub_edge)
		printf("- %d %d\n",edge.first,edge.second);
	fflush(stdout);
}
inline void solve_small()
{
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(find(e[q[i]].begin(),e[q[i]].end(),q[j])==e[q[i]].end())
				add_edge.push_back(make_pair(q[i],q[j]));
	print_edges();
	while(T--)
		for(int i=1;i<=n;++i)
		{
			printf("? %d %d\n",1,i),fflush(stdout);
			if(scanf("%s",a),a[0]=='L')
			{
				printf("! %d\n",i),fflush(stdout);
				scanf("%s",a);break;
			}
		}
}
int main()
{
	read(),topo_sort();
	if(n<=20) return solve_small(),0;
	init();
	for(int i=1;i<=n;++i)
		for(int j=0;j<20;++j)
			s[i]|=(find(e[i].begin(),e[i].end(),q[n-j])!=e[i].end())<<j;
	for(int i=0;i<20;++i)
		for(int j=0;j<i;++j)
			if(!((s[q[n-i]]>>j)&1)) add_edge.push_back(make_pair(q[n-i],q[n-j]));
	for(int i=1,x;x=q[i],i<=n-20;++i)
		for(unsigned j=0;;++j) if(!node[s[x]^change[j]])
		{
			node[s[x]^change[j]]=x,add_edge.push_back(make_pair(x,x));
			for(int k=0;k<20;++k) if((change[j]>>k)&1)
				(s[x]>>k)&1?sub_edge.push_back(make_pair(x,q[n-k])):
					add_edge.push_back(make_pair(x,q[n-k]));
			break;
		}
	print_edges();
	while(T--)
	{
		int S=0,ans=0;
		for(int i=0;i<20;++i)
		{
			printf("? %d %d\n",1,q[n-i]),fflush(stdout);
			if(scanf("%s",a),a[0]=='L')
			{
				ans=q[n-i];break;
			}
			S|=(a[0]=='W')<<i;
		}
		if(!ans) ans=node[S];
		printf("! %d\n",ans),fflush(stdout);
		scanf("%s",a);
	}
	return 0;
}