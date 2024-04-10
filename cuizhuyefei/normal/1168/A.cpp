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
const int N = 333333;
int n,m,a[N];
bool ck(int mid){
	int cur=0;
	rep(i,1,n){
		int x=m-1;
		if(a[i]+mid<cur)return 0;
		if(a[i]+mid<m)x=max(cur,a[i]);
		else{x=max(cur,a[i]);if(a[i]+mid-m>=cur)x=cur;}
		cur=x;
	}
	return 1;
}
int main() {
	read(n);read(m);rep(i,1,n)read(a[i]);
	int l=0,r=m;
	while(l<r){
		int mid=(l+r)>>1;
		if(ck(mid))r=mid;else l=mid+1;
	}
	cout<<l;
	return 0;
}