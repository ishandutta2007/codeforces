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
const int N = 266666,inf=0x3f3f3f3f;
int m,n,a[N],b[N],f[N];
inline int solve(int l, int st){
	rep(i,st,n-1){
		if(f[i]+1<b[i+1]){
			if(b[i+1]-l<=f[i]+1)umax(f[i+1],b[i+1]);
			if(b[i+2]-l<=f[i]+1)umax(f[i+2],b[i+1]+l);
		}
		else{
			umax(f[i+1],b[i+1]+l);
		}
	}
	return f[n];
}
bool ck(int l){//b[1..n]
	if(m-b[n]<=l)return 1;
	memset(f,0,sizeof(f));
	if(solve(l,1)>=m-l)return 1;
	
	memset(f,0,sizeof(f));
	if(b[2]<=l){
		f[2]=l;
		if(solve(l,2)>=m-(l-b[2]))return 1;
	}
	return 0;
}
int main() {
	read(m);read(n);rep(i,1,n)read(a[i]);rep(i,1,n)a[n+i]=a[i]+m;
	int p=2;rep(i,3,n+1)if(a[p]-a[p-1]<a[i]-a[i-1])p=i;
	rep(i,p,p+n-1)b[i-p+1]=a[i]-a[p];//>=0?a[i]-a[p]:a[i]-a[p]+m;
	m--;
	int L=0,R=m;
	while(L<R){
		int mid=(L+R)>>1;
		if(ck(mid))R=mid;else L=mid+1;
	}
	cout<<L;
	return 0;
}