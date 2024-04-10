#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;

int p,k;
char str[1010]; int len;
int s[1010],t[3400]; int n;
int work(){
	while (len>=0&&!s[len]) len--;
	if (len<0) return -1;
	static int r[1010];
	for (int i=0;i<=len;i++) r[i]=0;
	ll res=0;
	for (int i=len;i>=0;i--){
		res=res*10+s[i];
		if (res>=p) r[i]=res/p,res%=p;
	}
	for (int i=0;i<=len;i++) s[i]=r[i];
	return res;
}
int dp[3400][3400][2][2];  //MLE?
inline void add(int &x,int y){x=(x+y)%Mod;}
inline void add(int &x,ll y){x=(x+y)%Mod;}
void solve1(int i,int j,int up,int k,bool flg){  //[0,up)
	add(dp[i-1][j][0][0],1LL*up*(up-1)/2%Mod*k);
	add(dp[i-1][j][0][flg],1LL*up*k);
	if (up>1) add(dp[i-1][j+1][1][0],1LL*(up-1)*(up-2)/2%Mod*k);
	if (up>1) add(dp[i-1][j+1][1][flg],1LL*(up-1)*k);
}
int getsum(int l,int r){return 1LL*(l+r)*(r-l+1)/2%Mod;}  //caution ll
void solve2(int i,int j,int up,int k,bool flg){  //[p,p+up)
	add(dp[i-1][j][0][0],1LL*getsum(p+1-up,p-1)*k);
	add(dp[i-1][j][0][flg],1LL*(p-up)*k);
	add(dp[i-1][j+1][1][0],1LL*getsum(p+2-up,p)*k);
	add(dp[i-1][j+1][1][flg],1LL*(p-up+1)*k);
}
int main()
{
	scanf("%d%d%s",&p,&k,str); len=strlen(str)-1;
	//if (k>3325) return puts("0"),0;
	if (len==0&&str[0]=='0') return puts("0"),0;
	for (int i=0;i<=len;i++) s[i]=str[len-i]-'0';
	for (int tp;~(tp=work());t[n++]=tp); n--;
	//printf("t: "); for (int i=n;~i;i--) printf("%d ",t[i]); puts("");
	
	dp[n+1][0][0][1]=1;
	for (int i=n+1;i>0;i--)
		for (int j=0;j<=n+1-i;j++)
			for (int u=0;u<2;u++)
				for (int v=0;v<2;v++){
					if (!dp[i][j][u][v]) continue;
					int up=v?t[i-1]+1:p;
					if (u) solve2(i,j,up,dp[i][j][u][v],v);
					else solve1(i,j,up,dp[i][j][u][v],v);
				}
	int ans=0;
	for (int i=k;i<=n;i++) add(ans,0LL+dp[0][i][0][0]+dp[0][i][0][1]);
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}