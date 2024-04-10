// Problem: CF1163D Mysterious Code
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1163D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
const int N=1e3+100;
int n;char c[N];
char s[N];
int ch[N][26],fail[N],tot=1,sum[N];
queue<int>q;vector<int>arr;int dp[N][N];
signed main(){
	scanf("%s",c+1);n=strlen(c+1);
	{
		scanf("%s",s);
		int u=1;
		for(int j=0;s[j];j++){
			if(!ch[u][s[j]-'a'])ch[u][s[j]-'a']=++tot;
			u=ch[u][s[j]-'a'];
		}
		sum[u]++;
	}
	{
		scanf("%s",s);
		int u=1;
		for(int j=0;s[j];j++){
			if(!ch[u][s[j]-'a'])ch[u][s[j]-'a']=++tot;
			u=ch[u][s[j]-'a'];
		}
		sum[u]--;
	}
	for(int i=0;i<26;i++)ch[0][i]=1;q.push(1);
	while(q.size()){
		int u=q.front();arr.pb(u);q.pop();
		for(int i=0;i<26;i++)
			if(ch[u][i])
				fail[ch[u][i]]=ch[fail[u]][i],
				q.push(ch[u][i]);
			else ch[u][i]=ch[fail[u]][i];
	}
	for(auto x:arr)sum[x]+=sum[fail[x]];
	memset(dp,-0x3f,sizeof dp);
	dp[0][1]=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=tot;j++){
			if(dp[i][j]< -1e8)continue;
			for(int k=0;k<26;k++){
				if(c[i+1]!=k+'a'&&c[i+1]!='*')continue;
				int to=ch[j][k];
				chkmx(dp[i+1][to],dp[i][j]+sum[to]);
			}
		}
	}
	int ans=-0x3f3f3f3f;
	for(int i=1;i<=tot;i++)chkmx(ans,dp[n][i]);
	write(ans);
}