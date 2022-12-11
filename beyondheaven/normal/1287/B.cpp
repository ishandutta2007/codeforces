#include<cstdio>
#include<set>
#define MaxN 1523
typedef long long LL;
typedef char Vector[30];
int n,k;
Vector card[MaxN];
inline int idx(char ch)
{
	switch(ch)
	{
		case 'S':return 0;
		case 'E':return 1;
		case 'T':return 2;
	}
	return -1;
}
inline LL Hash(Vector u)
{
	LL res=0;
	for(int i=1;i<=k;++i)
	res=3*res+idx(u[i]);
	return res;
}
std::set<LL>hashtable;
inline void Init()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	scanf("%s",card[i]+1);
	for(int i=1;i<=n;++i)
	hashtable.insert(Hash(card[i]));
}
Vector goal;
inline void Fill(int u,int v)
{
	for(int i=1;i<=k;++i)
	if(card[u][i]==card[v][i])
	goal[i]=card[u][i];
	else goal[i]='S'+'E'+'T'-card[u][i]-card[v][i];
}
inline void Solve()
{
	int res=0;
	for(int i=1;i<=n;++i)
	for(int j=i+1;j<=n;++j)
	{
		Fill(i,j);
		if(hashtable.count(Hash(goal)))++res;
	}
	printf("%d\n",res/3);
}
int main()
{
	Init();
	Solve();
	return 0;
}