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
const int N = 2666;
int n,a[N];Pii ans[1766666];int tot;
int sta[N],top;
void move(int i, int j){//a[i]<=a[j]
	ans[++tot]=Pii(i,j);
	assert(a[i]<=a[j]);
	a[j]-=a[i];a[i]+=a[i];
}
void solve(int x, int y, int z){
	if(a[y]>a[z])swap(y,z);
	if(a[x]>a[y])swap(x,y);
	if(a[y]>a[z])swap(y,z);
	assert(a[x]<=a[y]&&a[y]<=a[z]);
	if(!a[x])return;
	if(a[y]%a[x]<=a[x]/2){
		int k=a[y]/a[x],cur=1;
		while(k){
			if(k&cur)k^=cur,move(x,y);else move(x,z);
			cur<<=1;
		}
	}
	else{
		int k=a[y]/a[x]+1,mi=1;while(mi*2<=k)mi*=2;int tmp=k-mi;
		for(int c=1;c*2<=mi;c*=2){
			if(tmp&c)tmp^=c,move(x,y);else move(x,z);
		}
		move(y,x);
	}
	solve(x,y,z);
}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n)if(a[i])sta[++top]=i;
	if(top<=1){puts("-1");return 0;}
	while(top>=3){
		int x=sta[top--],y=sta[top--],z=sta[top--];
		solve(x,y,z);
		if(a[x])sta[++top]=x;
		if(a[y])sta[++top]=y;
		if(a[z])sta[++top]=z;
	}
	printf("%d\n",tot);
	rep(i,1,tot)printf("%d %d\n",ans[i].fi,ans[i].se);
	int cnt=0;rep(i,1,n)cnt+=a[i]>0;assert(cnt==2);
	return 0;
}