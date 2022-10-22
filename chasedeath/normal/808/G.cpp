#include<cstdio> 
#include<cstring> 
#include<cctype>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;


#define reg register
typedef long long ll;
typedef unsigned ui;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0;
	while(!isdigit(IO=getchar()));
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return s;
}


//const ll P=19260817,K=5567891;
//const ll P1=1e9+13,K1=6550879;
const int N=1e5+10;

int n,m;

char s[N],p[N];
int dp[2][N];
int nxt[N];
int Nxt[N][27];

#define chk(a,b) ((a<b)&&(a=b))

int main(){
	scanf("%s%s",s+1,p+1);
	n=strlen(s+1),m=strlen(p+1);
	rep(i,2,m) {
		int j=nxt[i-1];
		while(j && p[i]!=p[j+1] ) j=nxt[j];
		if(p[i]==p[j+1]) j++;
		nxt[i]=j;
	}
	int cnt=0;
	rep(i,1,n) if(s[i]=='?') cnt++;
	int cur=0;
	if(cnt>=10000) {
		rep(i,0,m) rep(t,0,25) {
			int j=i;
			while(j && (t+'a')!=p[j+1]) j=nxt[j];
			if(p[j+1]==(t+'a')) j++;
			Nxt[i][t]=j;
			//cout<<"#"<<i<<' '<<t<<' '<<Nxt[i][t]<<endl;
		}
		memset(dp,-10,sizeof dp);
		dp[!cur][0]=0;
		rep(i,1,n) {
			cur^=1;
			rep(j,0,m) dp[!cur][j]=-1e9;
			if(s[i]!='?'){
				rep(j,0,m-1) if(dp[cur][j]>=0) {
					reg int t=Nxt[j][s[i]-'a'];
					if(t==m) chk(dp[!cur][nxt[m]],dp[cur][j]+1);
					else {
						chk(dp[!cur][t],dp[cur][j]);
					}
					//cout<<i<<' '<<j<<' '<<dp[cur][j]<<endl;
				}
			} else {
				rep(j,0,m-1) if(dp[cur][j]>=0) {
					rep(k,0,25) {
						reg int t=Nxt[j][k];
						if(t==m) chk(dp[!cur][nxt[m]],dp[cur][j]+1);
						else {
							chk(dp[!cur][t],dp[cur][j]);
						}
					}
					//cout<<i<<' '<<j<<' '<<dp[cur][j]<<endl;
				}
			}
		}
	} else {

		memset(dp,-10,sizeof dp);
		dp[!cur][0]=0;
		rep(i,1,n) {
			cur^=1;
			rep(j,0,m) dp[!cur][j]=-1e9;
			if(s[i]!='?'){
				rep(j,0,m-1) if(dp[cur][j]>=0) {
					reg int t=j;
					while(t && s[i]!=p[t+1]) t=nxt[t];
					if(p[t+1]==s[i]) t++;
					if(t==m) chk(dp[!cur][nxt[m]],dp[cur][j]+1);
					else {
						chk(dp[!cur][t],dp[cur][j]);
					}
					//cout<<i<<' '<<j<<' '<<dp[cur][j]<<endl;
				}
			} else {
				rep(j,0,m-1) if(dp[cur][j]>=0) {
					rep(k,0,25) {
						reg int t=j;
						while(t && (k+'a')!=p[t+1]) t=nxt[t];
						if(p[t+1]==(k+'a')) t++;
						if(t==m) chk(dp[!cur][nxt[m]],dp[cur][j]+1);
						else {
							chk(dp[!cur][t],dp[cur][j]);
						}
					}
				}
			}
		}
	}

	int ans=0;
	rep(i,0,m) ans=max(ans,dp[!cur][i]);
	printf("%d\n",ans);
}