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
const int N = 666666;
int n,a[N],b[N],ok[N],s;
int main() {
	read(n);read(s);rep(i,1,n)read(a[i]);rep(i,1,n)read(b[i]);
	if(a[1])rep(i,1,n)ok[i]=a[i];
	for(int i=n,j=0;i>=1;i--){if(b[i])j|=ok[i];if(b[i]&&j)ok[i]=1;}
	if(ok[s])puts("YES");else puts("NO");
	return 0;
}