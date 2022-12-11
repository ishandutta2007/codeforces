#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

char c[1010],s[60],t[60];
struct Node{
	int val;
	int nxt[26],fil;
}node[110];
int idtot;
void ins(char *s,int val)
{
	int len=strlen(s+1),cur=0;
	for (int i=1;i<=len;i++)
	{
		int id=s[i]-'a';
		if (!node[cur].nxt[id]) node[cur].nxt[id]=++idtot;
		cur=node[cur].nxt[id];
	}
	node[cur].val+=val;
}
int que[110],hd,tl;
void getfail()
{
	for (int i=0;i<26;i++) if (node[0].nxt[i]) que[++tl]=node[0].nxt[i];
	while (hd<tl)
	{
		int u=que[++hd];
		for (int i=0;i<26;i++)
			if (!node[u].nxt[i]) node[u].nxt[i]=node[node[u].fil].nxt[i];
			else
			{
				node[node[u].nxt[i]].fil=node[node[u].fil].nxt[i];
				que[++tl]=node[u].nxt[i];
			}
	}
}
int dp[110][1010];
int main()
{
	memset(dp,-0x7f/2,sizeof dp);
	scanf("%s%s%s",c+1,s+1,t+1);
	ins(s,1); ins(t,-1);
	getfail(); for (int i=1;i<=tl;i++) node[i].val+=node[node[i].fil].val;  //i<-i+i.fil
	int n=strlen(c+1);
	dp[0][0]=0;
	for (int j=0;j<n;j++)
	{
		for (int i=0;i<=idtot;i++)
		{
			if (dp[i][j]==-1044266559) continue;
			if (c[j+1]=='*')   //if
			{
				for (int u=0;u<26;u++) dp[node[i].nxt[u]][j+1]=max(dp[node[i].nxt[u]][j+1],dp[i][j]+node[node[i].nxt[u]].val);   //+node[].val
			}
			else dp[node[i].nxt[c[j+1]-'a']][j+1]=max(dp[node[i].nxt[c[j+1]-'a']][j+1],dp[i][j]+node[node[i].nxt[c[j+1]-'a']].val);
		}
	}
	int ans=-0x7fffffff;
	for (int i=0;i<=idtot;i++) ans=max(ans,dp[i][n]);
	printf("%d\n",ans);
	return 0;
}