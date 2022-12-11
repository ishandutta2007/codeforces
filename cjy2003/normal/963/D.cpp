#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
char s[100010],a[100010];
int n,k[100010],l[100010];
int ch[100010][26],tot=1,p[100010],fail[100010],up[100010];
vector<int>pos[100010];
void ins(int len,int id)
{
	int u=1,c;
	for(int i=1;i<=len;++i)
	{
		c=a[i]-'a';
		if(!ch[u][c])ch[u][c]=++tot;
		u=ch[u][c];
	}
	p[u]=id;
}
void build()
{
	queue<int>q;
	q.push(1);
	for(int i=0;i<26;++i)ch[0][i]=1;
	int x;
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(int i=0;i<26;++i)
			if(ch[x][i])
			{
				fail[ch[x][i]]=ch[fail[x]][i];
				if(p[fail[ch[x][i]]])up[ch[x][i]]=fail[ch[x][i]];
				else up[ch[x][i]]=up[fail[ch[x][i]]];
				q.push(ch[x][i]);
			}
			else ch[x][i]=ch[fail[x]][i];
	}
}
int main()
{
	scanf("%s %d",s+1,&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %s",&k[i],a+1);
		ins(l[i]=strlen(a+1),i);
	}
	build();
	int lens=strlen(s+1);
	for(int i=1,u=1,c;i<=lens;++i)
	{
		c=s[i]-'a';
		u=ch[u][c];
		for(int x=p[u]?u:up[u];x;x=up[x])pos[p[x]].emplace_back(i);
	}
	for(int i=1;i<=n;++i)
	{
		int siz=pos[i].size(),mi=0x3f3f3f3f;
		for(int j=0;j<=siz-k[i];++j)mi=min(mi,pos[i][j+k[i]-1]-pos[i][j]);
		if(mi==0x3f3f3f3f)printf("-1\n");
		else printf("%d\n",mi+l[i]);
	}
	return 0;
}