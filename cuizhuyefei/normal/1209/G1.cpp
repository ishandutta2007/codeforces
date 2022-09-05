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
const int N = 666666;
int n,_,a[N],res,mx[N],cnt[N];
int main() {
	read(n);read(_);rep(i,1,n)read(a[i]),mx[a[i]]=i;
	res=n;
	rep(i,1,n){
		int j=i,r=mx[a[j]];
		while(j<r)j++,umax(r,mx[a[j]]);
		//[i,j]
		int ans=0;rep(k,i,j)cnt[a[k]]++,umax(ans,cnt[a[k]]);
		res-=ans;rep(k,i,j)cnt[a[k]]=0;
		i=j;
	}
	cout<<res;
	return 0;
}