#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}

const int N = 305, inf = 0x3f3f3f3f;
int n,a[N],l[N];Pii s[N];int len,dp[2][N][N],pos[N][3];
bool cmp(Pii x, Pii y){return a[x.fi]+l[x.fi]*x.se<a[y.fi]+l[y.fi]*y.se;}
int main() {
	read(n);rep(i,1,n)read(a[i]),read(l[i]);
	rep(i,1,n)rep(j,-1,1)s[++len]=Pii(i,j);
	sort(s+1,s+len+1,cmp);
	rep(i,1,len)pos[s[i].fi][s[i].se+1]=i;
	rep(i,0,1)rep(j,0,len)rep(k,0,len)dp[i][j][k]=-inf;
	dp[1][0][len]=0;
	rep(t,1,len-1){
		int p=t&1,q=p^1,Len=a[s[t+1].fi]+l[s[t+1].fi]*s[t+1].se-(a[s[t].fi]+l[s[t].fi]*s[t].se);//p-->q
		rep(j,0,len)rep(k,0,len)dp[q][j][k]=-inf;
		rep(j,0,len)rep(k,0,len)if(dp[p][j][k]>=0){
			umax(dp[q][j][k],dp[p][j][k]+(j>=t+1||k<=t?Len:0));
			if(s[t].se==0)umax(dp[q][max(j,pos[s[t].fi][2])][k],dp[p][j][k]+(max(j,pos[s[t].fi][2])>=t+1||k<=t?Len:0));
			umax(dp[q][j][min(k,t)],dp[p][j][k]+Len);
			if(s[t].se==0&&pos[s[t].fi][0]<=k){
				umax(dp[q][j][len],dp[p][j][k]+(j>=t+1?Len:0));
				umax(dp[q][j][t],dp[p][j][k]+Len);
			}
		}
	}
	int res=0;rep(i,0,len)umax(res,dp[len&1][i][len]);cout<<res<<endl;
	return 0;
}