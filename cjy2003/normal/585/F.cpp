#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int mod=1000000007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
char s[1010],a[100],b[100];
int n,d;
int ch[25050][10],tot=1,tag[25050],fail[25050];
void ins(int st,int len)
{
	int u=1,c;
	for(int i=1;i<=len;++i)
	{
		c=s[st+i]-'0';
		if(!ch[u][c])ch[u][c]=++tot;
		u=ch[u][c];
	}
	tag[u]=1;
}
void build()
{
	queue<int>q;
	q.push(1);
	for(int i=0;i<10;++i)ch[0][i]=1;
	int x;
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(int i=0;i<10;++i)
			if(ch[x][i])fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
			else ch[x][i]=ch[fail[x]][i];
	}
}
int dp[51][25050][2];
int dfs(char c[],int w,bool lim,int p,bool ok)
{
	if(!w)return ok;
	if(!lim&&~dp[w][p][ok])return dp[w][p][ok];
	int mx=lim?c[w]:9,sum=0;
	for(int i=0;i<=mx;++i)add(sum,dfs(c,w-1,lim&&i==mx,ch[p][i],ok|tag[ch[p][i]]));
	if(!lim)dp[w][p][ok]=sum;
	return sum;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%s",a+1);
	scanf("%s",b+1);
	d=strlen(a+1);
	for(int i=1;i<=n-d/2+1;++i)ins(i-1,d/2);
	build();
	reverse(a+1,a+1+d);
	reverse(b+1,b+1+d);
	for(int i=1;i<=d;++i)a[i]-='0',b[i]-='0';
	--a[1];
	for(int i=1;i<=d;++i)if(a[i]<0)a[i]+=10,--a[i+1];
	memset(dp,-1,sizeof(dp));
	int ans=dfs(b,d,1,1,0)+mod-dfs(a,d,1,1,0);
	printf("%d",ans%mod);
	return 0;
}