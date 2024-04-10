#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ll long long
#define mod(x) ((x)>=10?(x)-10:(x))
using namespace std;
const int N=2e3+3;
int a[N],m[N],b[N][N],v[10],id[N*10],nxt[N*10],sr[N*10][10],sl[N*10][10],dp[N][N];
vector<int> vec[N],vec2[N*10];
int main(){
//	freopen("digits.in","r",stdin);
//	freopen("digits.out","w",stdout);
	static char s[N],t[N]; int n;
	scanf("%s%d",s,&n); int l=strlen(s);
	rep(j,1,l) a[j]=s[l-j]=='?'?-1:s[l-j]-'0';
	while (l&&a[l]==0) --l;
	int lm=l;
	rep(i,1,n){
		scanf("%s",t); m[i]=strlen(t);
		rep(j,1,m[i]) b[i][j]=t[m[i]-j]-'0';
		while (m[i]&&b[i][m[i]]==0) --m[i];
		lm=max(lm,m[i]);
	}
	rep(i,0,9) scanf("%d",&v[i]);
	rep(i,1,n) vec[1].pb(i); int cnt=2;
	rep(i,0,lm+1) rep(j,1,n+1) dp[i][j]=-1e9;
	dp[0][1]=-1e9,dp[0][2]=0;
	rep(i,0,lm){
		rep(t,0,9) sr[cnt+1][t]=0;
		per(j,cnt,1){
			rep(t,0,9) sr[j][t]=sr[j+1][t];
			rep0(k,vec[j].size()){
				int p=vec[j][k];
				rep(t,0,9){
					if (i+1>max(l,m[p])+1) continue;
					int u=mod(b[p][i+1]+t+1);
					sr[j][t]+=i+1<=max(l,m[p])||u?v[u]:0;
				}
			}
		}
		rep(j,1,cnt){
			rep(t,0,9) sl[j][t]=sl[j-1][t];
			rep0(k,vec[j].size()){
				int p=vec[j][k];
				rep(t,0,9){
					if (i+1>max(l,m[p])+1) continue;
					int u=mod(b[p][i+1]+t);
					sl[j][t]+=i+1<=max(l,m[p])||u?v[u]:0;
				}
			}
		}
		rep(j,1,cnt*10) vec2[j].clear(),id[j]=0;
		rep(j,1,cnt)
			rep0(k,vec[j].size()){
				int p=vec[j][k];
				vec2[b[p][i+1]*cnt+j].pb(p);
			}
		int cnt2=0;
		rep(j,1,cnt*10) if (vec2[j].size()) id[j]=++cnt2;
		nxt[cnt*10+1]=cnt2+1;
		per(j,cnt*10,1)
			nxt[j]=vec2[j].size()?id[j]:nxt[j+1];
		rep(j,1,cnt){
			int b=0,e=9;
			if (i+1>l) b=e=0;
			else if (~a[i+1]) b=e=a[i+1];
			else if (i+1==l) b=1;
			rep(t,b,e){
				int &x=dp[i+1][nxt[cnt*(9-t)+j]];
				x=max(x,dp[i][j]+sr[j][t]+sl[j-1][t]);
			}
		}
		rep(j,1,cnt2+1) vec[j].clear();
		rep(j,1,cnt*10) if (id[j]) vec[id[j]]=vec2[j];
		cnt=cnt2+1;
	}
	int ans=0; rep(j,1,cnt) ans=max(ans,dp[lm+1][j]);
	printf("%d\n",ans);
	return 0;
}