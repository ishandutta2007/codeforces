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
const int mod=1e9+7;
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,trie[500010][10],fail[500010],dl[500010],h,t,pd[500010],f[2][2],dp[2][500010][2],half,pcnt;
char s[1010],X[55],Y[55];
void insert(int st)
{
	int x=0;
	for(int i=0;i<half;++i)
	{
		int c=s[st+i]-'0';
		if(!trie[x][c]) trie[x][c]=++pcnt;
		x=trie[x][c];
	}
	pd[x]=1;
}
int calc(char S[])
{
	int len=strlen(S+1);
	memset(dp,0,sizeof(dp));
	memset(f,0,sizeof(f));
	int st=1,bj=0;
	while(S[st]=='0') ++st;
	for(int i=st;i<=len;++i,bj^=1)
	{
		memset(dp[bj],0,sizeof(dp[bj]));
		memset(f[bj],0,sizeof(f[bj]));
		int c=S[i]-'0';
		for(int j=0;j<=pcnt;++j) if(!pd[j])
		{
			int x=trie[j][c];
			if(pd[x]) f[bj][0]=MOD(f[bj][0]+dp[bj^1][j][0]-mod);
			else dp[bj][x][0]=MOD(dp[bj][x][0]+dp[bj^1][j][0]-mod);
			for(int k=0;k<c;++k)
			{
				x=trie[j][k];
				if(pd[x]) f[bj][1]=MOD(f[bj][1]+dp[bj^1][j][0]-mod);
				else dp[bj][x][1]=MOD(dp[bj][x][1]+dp[bj^1][j][0]-mod);
			}
			for(int k=0;k<10;++k)
			{
				x=trie[j][k];
				if(pd[x]) f[bj][1]=MOD(f[bj][1]+dp[bj^1][j][1]-mod);
				else dp[bj][x][1]=MOD(dp[bj][x][1]+dp[bj^1][j][1]-mod);
			}
		}
		f[bj][0]=MOD(f[bj][0]+f[bj^1][0]-mod);
		f[bj][1]=MOD(f[bj][1]+(ll)c*f[bj^1][0]%mod-mod);
		f[bj][1]=MOD(f[bj][1]+(ll)f[bj^1][1]*10%mod-mod);
		if(i==st)
		{
			int x=trie[0][c];
			if(pd[x]) f[bj][0]=MOD(f[bj][0]+1-mod);
			else dp[bj][x][0]=MOD(dp[bj][x][0]+1-mod);
			for(int j=1;j<c;++j)
			{
				int x=trie[0][j];
				if(pd[x]) f[bj][1]=MOD(f[bj][1]+1-mod);
				else dp[bj][x][1]=MOD(dp[bj][x][1]+1-mod);
			}
		}
		else
		{
			for(int j=1;j<10;++j)
			{
				int x=trie[0][j];
				if(pd[x]) f[bj][1]=MOD(f[bj][1]+1-mod);
				else dp[bj][x][1]=MOD(dp[bj][x][1]+1-mod);
			}
		}
	}
	return MOD(f[bj^1][0]+f[bj^1][1]-mod);
}
int main()
{
	scanf("%s",s+1);
	scanf("%s%s",X+1,Y+1);
	int n=strlen(s+1);
	half=strlen(X+1)/2;
	//cout<<half<<endl;
	for(int i=1;i+half-1<=n;++i) insert(i);
	for(int i=0;i<10;++i) if(trie[0][i]) dl[++t]=trie[0][i];
	while(h!=t)
	{
		int u=dl[++h];
		for(int i=0;i<10;++i) if(trie[u][i])
		{
			fail[trie[u][i]]=trie[fail[u]][i];
			dl[++t]=trie[u][i];
		}
		else trie[u][i]=trie[fail[u]][i];
	}
	//cout<<pcnt<<endl;
	int cur=strlen(X+1);
	while(X[cur]=='0') X[cur]='9',--cur;
	--X[cur];
	/*cout<<Y+1<<" "<<X+1<<endl;
	cout<<calc(Y)<<" "<<calc(X)<<endl;*/
	printf("%d\n",MOD(calc(Y)-calc(X)));
	return 0;
}
//ore no turn,draw!