#include<bits/stdc++.h>
#define MaxN 500123
inline int idx(char c){return c-'a';}
int n,m;
char s[MaxN];
struct Query
{
	int b,id;
	std::vector<int>save;
	Query(int _b=0,int _id=0):
		b(_b),id(_id),save(26,0){}
};
std::vector<Query>cmd[MaxN];
std::vector<int>cnt[MaxN];
std::vector<int>G[MaxN];
int ans[MaxN];
inline void Init()
{
	scanf("%d%d",&n,&m);
	for(int i=2,f;i<=n;++i)
	{
		scanf("%d",&f);
		G[f].emplace_back(i);
	}
	scanf("%s",s+1);
	for(int i=1,a,b;i<=m;++i)
	{
		scanf("%d%d",&a,&b);
		cmd[a].emplace_back(Query(b,i));
	}
	
	for(int i=1;i<=n;++i)
	cnt[i].resize(26);
}

inline int Check(std::vector<int>&save,std::vector<int>&now)
{
	int res=0;
	for(int i=0;i<26;++i)
	res+=(now[i]-save[i])%2;
	return res<=1?1:0;
}

int dep[MaxN];
inline void Dfs(int u,int f)
{
	dep[u]=dep[f]+1;
	for(auto&q:cmd[u])
	q.save=cnt[q.b];
	
	++cnt[dep[u]][idx(s[u])];
	
	for(int v:G[u])Dfs(v,u);
	
	for(auto&q:cmd[u])
	ans[q.id]=Check(q.save,cnt[q.b]);
}

int main()
{
	Init();
	Dfs(1,0);
	for(int i=1;i<=m;++i)
	printf("%s\n",ans[i]?"Yes":"No");
	return 0;
}