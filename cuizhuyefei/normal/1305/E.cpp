#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
int n,m,a[N],lim=1e9;
int calc(int i){//1..i-1 dui
	int r=0;rep(j,1,i-1)assert(a[j]==j),r+=a[j]<a[i]&&a[i]-a[j]<j;
	return r;
}
int main() {
	read(n);read(m);int cur=0;
	rep(i,1,n)a[i]=i,cur+=calc(i);a[n+1]=lim;
	if(m>cur){puts("-1");return 0;}
	int pos=n;
	while(pos&&cur-calc(pos)>=m){
		cur-=calc(pos);a[pos]=a[pos+1]-2e4;pos--;
	}
	while(cur>m)cur-=calc(pos),a[pos]++,cur+=calc(pos);
	rep(i,1,n)printf("%d ",a[i]);
	return 0;
}