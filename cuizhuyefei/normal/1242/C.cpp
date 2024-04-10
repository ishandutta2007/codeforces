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
int k,n,all,sz[266];Vi a[266];map<int,int>Map;
ll sum[266];
void GG(){puts("No");exit(0);}
int ok[1<<15|3],id[17],Out[17];Pii ans[17];int pre[1<<15|3];
Pii fangan[1<<15|3][17];
void ini(){
	int s=0;
	rep(i,1,n)if(id[i]){
		s|=1<<i-1;
	}
	ok[s]=1;
//	printf("find %d\n",s);
//	if(s==1)printf("!!!!!!!! %d %d\n",ans[1].fi,ans[1].se);
	rep(i,1,n)if(id[i]){
		fangan[s][i]=ans[i];
	}
}
int main() {
	read(k);n=k;
	rep(i,1,k){
		read(sz[i]);rep(j,1,sz[i]){
			int x;read(x);a[i].pb(x);Map[x]=i;sum[i]+=x;
		}
	}
	ll tot=0;rep(i,1,k)tot+=sum[i];
	if(tot%k)GG();
	tot/=k;
	rep(i,1,k)rep(j,0,sz[i]-1){
		memset(id,0,sizeof(id));bool ok=1;
		id[i]=1;int cur=1,lst=i;
		memset(Out,0,sizeof(Out));Out[i]=a[i][j];
		while(1){
			ll x=tot-sum[lst]+Out[lst];
			if(!Map.count(x)){ok=0;break;}
			int nxt=Map[x];if(id[nxt]>1){ok=0;break;}
			if(!id[nxt]){
				ans[nxt]=Pii(x,lst);
				Out[nxt]=x;id[nxt]=++cur;lst=nxt;
			}
			else{
				assert(nxt==i);
				if(x==a[i][j])ans[nxt]=Pii(x,lst);else ok=0;
				break;
			}
		}
		if(ok)ini();
	}
//	printf("!!!!!!!! %d %d\n",fangan[1][1].fi,fangan[1][1].se);
	memset(pre,-1,sizeof(pre));pre[0]=0;all=(1<<k)-1;
	rep(s,1,all)
		for(int t=(s-1)&s;;t=(t-1)&s)if(pre[t]>=0&&ok[s^t]){
			pre[s]=t;
			break;
		}else if(!t)break;
	if(pre[all]==-1)GG();
	puts("Yes");
	for(int s=all;s;s=pre[s]){
		int cur=s^pre[s];
	//	printf("qaq %d\n",cur);
		rep(i,1,n)if(cur>>i-1&1)ans[i]=fangan[cur][i];
	}
	rep(i,1,n)printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}