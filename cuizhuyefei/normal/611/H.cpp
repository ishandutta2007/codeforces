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
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666;
int n,cnt[7][7],sz[7],bel[N],mi[7],fa[N];Vi dot[7];Pii ans[N];int len;
void GG(){puts("-1");exit(0);}
inline bool ck(){
	rep(s,0,63){
		int cnt0=0;rep(i,1,6)if(s>>i-1&1)cnt0+=sz[i];//SZ(dot[i]);
		int cnt1=0;rep(i,1,5)rep(j,i+1,6)if((s>>i-1&1)||(s>>j-1&1))cnt1+=cnt[i][j];
		if(cnt0>cnt1)return 0;
	}
	return 1;
}
int main() {
	read(n);rep(i,1,n-1){
		char s[8];scanf("%s",s);int u=strlen(s);
		scanf("%s",s);int v=strlen(s);
		if(u>v)swap(u,v);cnt[u][v]++;
	}
	mi[0]=1;rep(i,1,6)mi[i]=mi[i-1]*10;
	for(int i=1,j=1;i<=n;i++){if(i==mi[j])j++;dot[j].pb(i);bel[i]=j;}
	rep(i,1,6)if(cnt[i][i]){
		if(cnt[i][i]>=SZ(dot[i]))GG();
		while(cnt[i][i]--){
			int x=dot[i].back();dot[i].pop_back();
			ans[++len]=Pii(x,dot[i].back());
		}
	}
	Pii a[50];int tot=0;rep(i,1,6)rep(j,i+1,6)if(cnt[i][j])a[++tot]=Pii(i,j);
	int rt=dot[1].back();dot[1].pop_back();
	rep(i,1,6)sz[i]=SZ(dot[i]);
//	rep(i,1,6)cerr<<sz[i]<<' ';cerr<<endl;
//	rep(i,1,6)rep(j,i+1,6)if(cnt[i][j])cerr<<i<<' '<<j<<' '<<cnt[i][j]<<endl;
	if(!ck())GG();
	int sum=0;rep(i,1,6)rep(j,i+1,6)sum+=cnt[i][j];
	rep(t,1,sum){
		while(1){
			while(!cnt[a[tot].fi][a[tot].se])tot--;
			cnt[a[tot].fi][a[tot].se]--;
			rep(i,1,6)sz[i]=SZ(dot[i]);
			if(sz[a[tot].fi]){
				sz[a[tot].fi]--;
				if(ck()){fa[dot[a[tot].fi].back()]=a[tot].se;dot[a[tot].fi].pop_back();break;}
			}
		//	rep(i,1,6)sz[i]=SZ(dot[i]);sz[a[tot].se]--;
			fa[dot[a[tot].se].back()]=a[tot].fi;dot[a[tot].se].pop_back();break;
		}
	}
	static int q[N];int f=0,r=1;
//	static bool vis[N];vis[rt]=1;
	q[f]=rt;bool vis[8]={0};
	while(f!=r){
		int u=q[f++];
		if(!vis[bel[u]]){
			vis[bel[u]]=1;
			rep(i,1,n)if(fa[i]&&fa[i]==bel[u])q[r++]=i,ans[++len]=Pii(i,u);
		}
	}
	if(len<n-1)GG();
	rep(i,1,len)printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}