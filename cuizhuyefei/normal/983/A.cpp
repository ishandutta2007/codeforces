#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
ll Q,p,q,b;
ll gcd(ll a, ll b) {return !b?a:gcd(b,a%b);}
bool judge() {
	ll GCD=gcd(p,q); p/=GCD; q/=GCD;
	rep(i,1,64) {ll lst=q; GCD=gcd(q,b); q/=GCD; while (GCD>1&&q%GCD==0) q/=GCD; if (q==lst) break;}
	return q==1;
}
int main() {
	read(Q);
	while (Q--) {
		read(p);read(q);read(b);
		if (judge()) puts("Finite"); else puts("Infinite");
	}
	return 0;
}