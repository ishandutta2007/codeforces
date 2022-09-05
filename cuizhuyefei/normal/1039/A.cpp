#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
ll T,n,a[N],x[N],cnt[N],b[N];bool gg[N];
int main() {
	read(n);scanf("%lld",&T);rep(i,1,n)read(a[i]),a[i]+=T;
	rep(i,1,n)read(x[i]);
	rep(i,1,n)if(x[i]<i){puts("No");return 0;}
	rep(i,1,n)cnt[i]++,cnt[x[i]]--,gg[x[i]]=1;
	rep(i,1,n)cnt[i]+=cnt[i-1];
	rep(i,1,n){
		ll l=max(b[i-1]+1,a[i]),r=3e18;//>=a[i]
		if(cnt[i])l=max(l,a[i+1]);
		if(gg[i]&&i<n)r=min(r,a[i+1]-1);
		if(l>r){puts("No");return 0;}b[i]=l;
	}
	puts("Yes");rep(i,1,n)printf("%lld ",b[i]);
	return 0;
}