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
const int N = 2333;
int n,a[N],res;map<int,int>Map;int tot;
bool vis[N];
inline bool ck(int l, int r){
	bool gg=0;
	rep(i,1,l-1){
		gg|=vis[a[i]];vis[a[i]]=1;
	}
	rep(i,r+1,n){
		gg|=vis[a[i]];vis[a[i]]=1;
	}
	rep(i,1,n)vis[a[i]]=0;
	return !gg;
}
int main() {
	read(n);rep(i,1,n)read(a[i]);res=n;
	rep(i,1,n){
		if(!Map.count(a[i]))Map[a[i]]=++tot;
		a[i]=Map[a[i]];
	}
	if(ck(1,0)){puts("0");return 0;}
	for(int i=1,j=i;i<=n;i++){
		umax(j,i);
		while(j<=n&&!ck(i,j))j++;
		if(j<=n)umin(res,j-i+1);
	}
	cout<<res;
	return 0;
}