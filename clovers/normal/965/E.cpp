#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int trie[N*5][26],n,bl[N*5],ans=0,cnt=0;
priority_queue<int> Q[N*5];
char s[N];

int insert(char s[],int len)
{
	int now=0;
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'a';
		if(!trie[now][c]) 
		{
			trie[now][c]=++cnt;
		}
		now=trie[now][c];
	}
	Q[now].push(len);
	bl[now]=1;
}

void dfs(int u,int dep)
{
	for(int i=0;i<26;i++)
	{
		int to=trie[u][i];
		if(!to) continue;
		dfs(to,dep+1);
		while(!Q[to].empty())
		{
			Q[u].push(Q[to].top());
			Q[to].pop();
		}
	}
	if(!bl[u]&&u)
	{
		ans=ans-Q[u].top()+dep;
		Q[u].pop();
		Q[u].push(dep);
	}
}

int main() 
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		insert(s,strlen(s));
		ans+=strlen(s);
	}
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}