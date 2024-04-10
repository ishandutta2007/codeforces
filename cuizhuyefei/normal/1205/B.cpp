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
const int N = 266666,inf=0x3f3f3f3f;
int n,cnt[66],res=inf;ll a[N];bool e[266][266];
int dis[66],q[66];
int getans(int s, int t){
	rep(i,1,n)dis[i]=inf;int f=0,r=1;q[f]=s;dis[s]=0;
	while(f!=r){
		int u=q[f++];
		rep(i,1,n)if(e[u][i]&&dis[i]>dis[u]+1){
			dis[i]=dis[u]+1;q[r++]=i;
		}
	}
	return dis[t];
}
int main() {
	read(n);rep(i,1,n){
		read(a[i]);
		rep(j,0,60)cnt[j]+=a[i]>>j&1;
	}
	rep(i,0,60)if(cnt[i]>=3){printf("3\n");return 0;}
	int len=0;rep(i,1,n)if(a[i])a[++len]=a[i];n=len;
	rep(i,1,n)rep(j,i,n)if(i!=j)e[i][j]=(a[i]&a[j]);
	rep(i,1,n)rep(j,i,n)if(i!=j&&e[i][j]){
		e[i][j]=e[j][i]=0;
		umin(res,getans(i,j)+1);
		e[i][j]=e[j][i]=1;
	}
	cout<<(res<inf?res:-1);
	return 0;
}