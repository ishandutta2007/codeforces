//2022-04-25 17:27
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define add(x,y) E[x].push_back(y)
const int md=1e9+7;
int read()
{
	int x=0;bool f=0;char c=getchar();
	for(;!isdigit(c);c=getchar())f^=!(c-45);
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	if(f)x=-x;return x;
}
int tr[2005][26];
vector<int>E[2005];
struct sam
{
	struct node
	{
		int v[10],len,fa;
		int &operator[](int x){return v[x];}
	}t[2005];
	int la=1,cnt=1;
	void insert(char c)
	{
		int x=++cnt,p=la;
		t[x].len=t[p].len+1;
		for(;p&&!t[p][c];p=t[p].fa)t[p][c]=x;
		if(!p)t[x].fa=1;
		else
		{
			int q=t[p][c];
			if(t[q].len==t[p].len+1)t[x].fa=q;
			else
			{
				int o=++cnt;
				t[o]=t[q];
				t[o].len=t[p].len+1;
				for(;p&&t[p][c]==q;p=t[p].fa)t[p][c]=o;
				t[x].fa=t[q].fa=o;
			}
		}
		la=x;
	}
	void dfs(int x)
	{
		for(int c=0;c<10;c++)
			if(t[x][c])tr[x][c]=x;
			else tr[x][c]=(x==1?1:tr[t[x].fa][c]);
		for(auto y:E[x])
		{
			dfs(y);
		}
	}
}A;
char s[1005],a[55],b[55];
int m,st[55],d;
int dp[55][2005][2][55][2];
pair<int,int>walk(int u,int len,int c){
	if(!A.t[u][c])u=tr[u][c],len=A.t[u].len;
	if(A.t[u][c]){len++;u=A.t[u][c];}
	return make_pair(u,len);
}
int dfs(int x,int p,int l,int len,int f)
{
	if(x==m+1)return f;
	int &res=dp[x][p][l][len][f];
	if(~res)return res;
	res=0;
	int pp,lp;
	for(int i=0;i<=(l?st[x]:9);i++)
	{
		tie(pp,lp)=walk(p,len,i);
		res+=dfs(x+1,pp,l&&i==st[x],lp,f||lp>=d/2);
		res%=md;
	}
	return res;
}
int sol(char a[])
{
	m=strlen(a+1);
	for(int i=1;i<=m;i++)st[i]=a[i]-'0';
	memset(dp,-1,sizeof(dp));return dfs(1,1,1,0,0);
}
signed main()
{
	cin>>s+1;int n=strlen(s+1);
	for(int i=1;i<=n;i++)A.insert(s[i]-'0');
	for(int i=2;i<=A.cnt;i++)add(A.t[i].fa,i);
	A.dfs(1);cin>>a+1>>b+1;d=m=strlen(a+1);
	while(a[m]=='0')a[m]='9',m--;a[m]--;
	cout<<(sol(b)-sol(a)+md)%md;
}