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
int n,x[N],y[N];
int main() {
	read(n);rep(i,1,n)read(x[i]),read(y[i]);
	while(1){
		int cnt=0;
		rep(i,1,n)cnt+=(x[i]-y[i])%2==0;
		if(cnt>0&&cnt<n){
			printf("%d\n",cnt);
			rep(i,1,n)if((x[i]-y[i])%2==0)printf("%d ",i);
			return 0;
		}
		if(cnt==0){rep(i,1,n)y[i]--;}
		cnt=0;rep(i,1,n)cnt+=x[i]%2==0;
		if(cnt>0&&cnt<n){
			printf("%d\n",cnt);
			rep(i,1,n)if(x[i]%2==0)printf("%d ",i);
			return 0;
		}
		if(cnt==0){rep(i,1,n)x[i]--,y[i]--;}
		rep(i,1,n)x[i]/=2,y[i]/=2;
	}
	return 0;
}