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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2333;
int w[N][N],n,dis[N];bool fin[N];
int main(){
	int mn=2e9;read(n);rep(i,1,n)rep(j,i+1,n)read(w[i][j]),mn=min(mn,w[i][j]);
	rep(i,1,n)rep(j,i+1,n)w[i][j]-=mn,w[j][i]=w[i][j];
	rep(i,1,n)w[i][i]=1e9;
	rep(i,1,n)dis[i]=1e9;
	rep(i,1,n){
		rep(j,1,n){dis[i]=min(dis[i],w[i][j]*2);}
	}
//	rep(i,1,n)rep(j,1,n)if(fin[j])dis[i]=min(dis[i],w[i][j]);
//	memset(fin,0,sizeof(fin));
	rep(t,1,n){
		int mn=0;rep(i,1,n)if(!fin[i]&&(!mn||dis[i]<dis[mn]))mn=i;
		fin[mn]=1;rep(i,1,n)dis[i]=min(1LL*dis[i],1LL*dis[mn]+w[i][mn]);
	}
	rep(i,1,n)printf("%lld\n",dis[i]+1LL*(n-1)*mn);
	return 0;
}