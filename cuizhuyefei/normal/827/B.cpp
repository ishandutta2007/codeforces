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
const int N = 233;
Vi a,b;
int l[233333],n,k;
int main() {
	read(n);read(k);
	rep(i,1,k)l[i]=(n-1)/k;per(i,(n-1)%k,1)l[i]++;
	int cnt=1;
	rep(i,1,k){int lst=1;rep(j,1,l[i])++cnt,a.pb(cnt),b.pb(lst),lst=cnt;}
	printf("%d\n",l[1]+l[2]);
	per(i,SZ(a)-1,0)printf("%d %d\n",a[i],b[i]);
	return 0;
}