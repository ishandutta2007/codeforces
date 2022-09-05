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
const int N = 2020;
int n,m;char S[N][N];bool gg[N];
int cnt[N];bitset<N>s[N],can[N];int sx[N],sy[N];
inline void upd(int u){
	rep(i,1,n)if(i!=u){
		if(gg[i]||gg[u])can[u][i]=can[i][u]=0;
		else can[i][u]=(s[i]&s[u])==s[u],can[u][i]=(s[u]&s[i])==s[i];
	}
}
inline void getedge(int u, int v){
	//printf("edge %d %d\n",u,v);
	gg[u]=1;upd(u);rep(i,1,m)if(S[i][u]=='1'){
		cnt[i]--;if(cnt[i]==1)rep(j,1,n)if(S[i][j]=='1'&&!gg[j])s[j][i]=0,upd(j);
	}
}
inline bool ck(){
	rep(t,1,n-1){
		bool ok=0;
		/*int u;rep(i,1,n)if(!gg[i])u=i;
		rep(i,1,n)if(i!=u&&!gg[i]){
			if((s[i]&s[u])==s[u])ok=1,getedge(u,i),sx[t]=u,sy[t]=i;
			else if((s[i]&s[u])==s[i])ok=1,getedge(i,u),sx[t]=u,sy[t]=i;
			if(ok)break;
		}*/
		rep(i,1,n)if(!ok&&!gg[i]&&can[i].count()){
			rep(j,1,n)if(can[i][j]){
				sx[t]=j;sy[t]=i;getedge(j,i);ok=1;break;
			}
		}
		if(!ok)return 0;
	}
	return 1;
}
int main() {
	int t;read(t);
	while(t--){
		read(n);read(m);
		memset(gg,0,sizeof(gg));memset(cnt,0,sizeof(cnt));
		rep(i,0,max(n,m))s[i].reset(),can[i].reset();
		rep(i,1,m)scanf("%s",S[i]+1);
		rep(i,1,m){
			rep(j,1,n)if(S[i][j]=='1')cnt[i]++;
			rep(j,1,n)if(S[i][j]=='1'&&cnt[i]>1)s[j][i]=1;//WA
		}
		rep(i,1,n)rep(j,1,n)if(i!=j&&(s[i]&s[j])==s[j])can[i][j]=1;
		if(!ck())puts("NO");
		else{
			puts("YES");
			rep(i,1,n-1)printf("%d %d\n",sx[i],sy[i]);
		}
	}
	return 0;
}