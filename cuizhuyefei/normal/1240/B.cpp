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
const int N = 377677;
int n,a[N],bg[N],ed[N],vis[N];
int main() {
	int T;read(T);while(T--){
		read(n);rep(i,1,n)vis[i]=0;
		rep(i,1,n)read(a[i]),vis[a[i]]=1;
		rep(i,1,n)vis[i]+=vis[i-1];
		rep(i,1,n)a[i]=vis[a[i]];int tot=vis[n],res=0;
		rep(i,1,n)ed[a[i]]=i;
		per(i,n,1)bg[a[i]]=i;
		for(int i=1,j=i;i<=tot;i++){
			umax(j,i);
			while(j+1<=tot&&ed[j]<bg[j+1])j++;
			umax(res,j-i+1);
		}
		printf("%d\n",tot-res);
	}
	return 0;
}