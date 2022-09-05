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
const int N = 1666666;
int n,p[N],q[N];
Pii ans[N];int sz;
int Abs(int x){return x>0?x:-x;}
void print(int x, int y){
	if(x==y)return;assert(Abs(x-y)>=n/2);
	ans[++sz]=Pii(x,y);swap(q[p[x]],q[p[y]]);swap(p[x],p[y]);
}
int main() {
	read(n);rep(i,1,n)read(p[i]),q[p[i]]=i;
	rep(i,2,n/2){
		if(q[i]<=n/2){
			print(q[i],n);print(q[i],i);
		}
		else{
			print(q[i],1);print(q[i],n);print(q[i],i);
		}
	}
	rep(i,n/2+1,n-1){
		if(q[i]>n/2){
			print(q[i],1);print(q[i],i);
		}
		else{
			print(q[i],n);print(q[i],1);print(q[i],i);
		}
	}
	if(p[1]!=1)print(1,n);
	rep(i,1,n)assert(p[i]==i);
	printf("%d\n",sz);
	rep(i,1,sz)printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}