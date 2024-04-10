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
int a[N],n,len;ll ans;int s[N],t[N];
int main() {
	read(n);rep(j,1,n){
		int l;read(l);
		rep(i,1,l)read(a[i]);
		bool ok=1;rep(i,1,l-1)ok&=a[i]>=a[i+1];
		if(ok)s[++len]=a[1],t[len]=a[l];
	}
	sort(s+1,s+len+1);sort(t+1,t+len+1);
	for(int i=1,j=0;i<=len;i++){
		while(j+1<=len&&t[i]>=s[j+1])j++;
		ans+=j;
	}
	
	cout<<1ll*n*n-ans;
	return 0;
}