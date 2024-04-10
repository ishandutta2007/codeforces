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
const int N = 23;

int main() {
	int x;read(x);
	if(x<=2){
		rep(i,1,x)printf("%d %d\n",i,i);return 0;
	}
	int n=x/3;
	rep(i,1,n)printf("%d %d\n%d %d\n%d %d\n",i*2,1,i*2-1,2,i*2,3);
	rep(i,3*n+1,x)printf("%d %d\n",10000+i,10000+i);
	return 0;
}