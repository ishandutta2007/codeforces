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
const int N = 2e6+15,mo=998244353;
int bit,n,f[N],res,sz[N],sz1[N];bool cho[N];//,notsure[N];
void modify(int u, int *sz, int xs){
	while(u)sz[u]+=xs,u>>=1;
}
void makesure(int u, int ans){
	assert(sz1[u]<=1);
	if(sz1[u]==0){
		assert(sz1[u]==ans);return;
	}
	if(u>=(1<<bit-1)){
		ans^=1;ans%=2;
		modify(u,sz1,-1);cho[u]=ans;
	//	cerr<<u<<' '<<ans<<endl;
		if(cho[u])modify(u,sz,cho[u]);return;
	}
	if(sz1[u<<1])makesure(u<<1,ans^1^sz[u<<1|1]);
	else makesure(u<<1|1,ans^1^sz[u<<1]);
}
int main() {
	read(n);
	if(n==1)res=1;
	if(n==2)res=1;
	if(n==3)res=0;
	if(n<=3){printf("%d\n",res);return 0;}
	bit=1;while((1<<bit+1)-1<=n)bit++;
	per(d,bit,1)for(int i=(1<<d)-1;i>=(1<<d-1);i--)modify(i,sz,1);
	for(int i=(1<<bit)-1;i>=(1<<bit-1);i-=2){
		cho[i]=1,modify(i,sz,1);
		modify(i-1,sz1,1);
	}
	per(d,bit-2,1)for(int i=(1<<d)-1;i>=(1<<d-1);i--){
		makesure((i<<1|1)<<1,1);
		makesure((i<<1)<<1|1,0);
	//	if(sz[(i>>1|1)<<1]%2==0)
	}
	int tot=(1<<bit)-1;for(int i=(1<<bit)-1;i>=(1<<bit-1);i--)tot+=cho[i];
	cerr<<tot<<endl;
	/*cerr<<sz[1<<bit-1]<<endl;
	cerr<<sz[1<<bit-2]<<endl;
	cerr<<sz[1<<bit-3]<<endl;
	cerr<<sz[1<<bit-4]<<endl;*/
	assert(sz1[1]==1&&sz1[1<<bit-1]==1);
	printf("%d\n",tot==n||tot+1==n);
	/*n=30;
	rep(i,2,n){
		f[i]=1e9;Vi s;
		rep(a,0,i-1)umin(f[i],f[a]+f[i-1-a]+i-1);
		rep(a,0,i-1)if(f[i]==f[a]+f[i-1-a]+i-1)s.pb(a);
		printf("%d:%d\n",i,f[i]);
	//	rep(j,0,SZ(s)-1)cerr<<s[j]<<' ';cerr<<endl;
	}*/
	return 0;
}