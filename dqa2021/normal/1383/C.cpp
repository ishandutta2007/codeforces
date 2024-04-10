#include<cstdio>
#include<algorithm>
using namespace std;

int n; char s[100010],t[100010];
int f[30]; int find(int x){return f[x]?f[x]=find(f[x]):x;}
int S[30];
bool dp[1<<20];
void init(){}
void solve(){
	for (int i=1;i<=20;i++) f[i]=0,S[i]=0;
	for (int i=0;i<1048576;i++) dp[i]=0;
	scanf("%d%s%s",&n,s+1,t+1);
	for (int i=1;i<=n;i++){
		int u=s[i]-'a'+1,v=t[i]-'a'+1;
		if (u==v) continue;
		S[u]|=1<<v-1;
		int x=find(u),y=find(v);
		if (x^y) f[y]=x;
	}
	dp[0]=1;
	int res=0;
	for (int i=1;i<(1<<20);i++){
		for (int j=0;j<20;j++)
			if (i>>j&1){
				int nxt=i^(1<<j);
				if (!(S[j+1]&nxt)&&dp[nxt]){dp[i]=1; break;}
			}
		if (!dp[i]) continue;
		int tot=0;
		for (int j=0;j<20;j++) tot+=i>>j&1;
		res=max(res,tot);
	}
	for (int i=1;i<=20;i++) res+=find(i)==i;
	printf("%d\n",40-res);
}
int main()
{
	int T; scanf("%d",&T);
	while (T--) init(),solve();
	return 0;
}