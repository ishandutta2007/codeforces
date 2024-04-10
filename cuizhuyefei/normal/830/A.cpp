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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
int n,m,p,a[N],b[N];
inline ll Abs(ll x){return x>0?x:-x;}
bool ck(ll d){
	int c=1;
	rep(i,1,n){
		while(c<=m&&(Abs(a[i]-b[c])+Abs(b[c]-p)>d))c++;
		if(c>m)return 0;c++;
	}
	return 1;
}
int main() {
	read(n);read(m);read(p);
	rep(i,1,n)read(a[i]);rep(i,1,m)read(b[i]);
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	ll l=0,r=3e9,res=r;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(ck(mid))res=mid,r=mid-1;else l=mid+1;
	}
	printf("%lld",res);
	return 0;
}