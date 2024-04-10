#pragma GCC optimize("Ofast")
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
int n,a[N];
int f(int x){return x+(n+x-1)/x;}
int main() {
	read(n);int l=1;rep(i,2,n)if(f(i)<f(l))l=i;
	int now=n,len=0;
	while(now){
		int x=min(l,now);per(i,x,1)a[++len]=now-i+1;now-=x;
	}
	rep(i,1,n)printf("%d ",a[i]);
	return 0;
}