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
const int N = 1233;
int n,a[N];Pii ans[6];
int Abs(int x){return x>0?x:-x;}
void dfs(int dep){
	bool ok=1;rep(i,1,n)ok&=a[i]==i;
	if(ok){printf("%d\n",dep-1);per(i,dep-1,1)printf("%d %d\n",ans[i].fi,ans[i].se);exit(0);}
	if(dep>3)return;
	Pii seg[10];int len=0;
	for(int i=1;i<=n;i++){
		int j=i;while(j+1<=n&&Abs(a[j]-a[j+1])==1)j++;
		//[i,j]
		seg[++len]=Pii(i,j);
		i=j;
	}
	if(len>9-dep*2)return;
	rep(i,1,n)if(Abs(a[i]-a[i-1])!=1||Abs(a[i]-a[i+1])!=1)
		rep(j,i+1,n)if(Abs(a[j]-a[j-1])!=1||Abs(a[j]-a[j+1])!=1){
			reverse(a+i,a+j+1);ans[dep]=Pii(i,j);
			dfs(dep+1);
			reverse(a+i,a+j+1);
		}
}
int main() {
	read(n);rep(i,1,n)read(a[i]);a[0]=a[n+1]=-1;
	dfs(1);
	return 0;
}