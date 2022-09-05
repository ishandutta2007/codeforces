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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
//const int N = 233333;
ll n;
int q;
ll solve(ll n, ll p) {
	if (n==1) return 1;
	if (p&1) return (p+1)>>1;
	if (n%2==0) return n/2+solve(n/2,p/2);
	return n/2+1+solve(n/2,p/2-1>0?p/2-1:n/2);
}
int main() {
	scanf("%lld",&n);read(q);
	while (q--) {
		ll x; scanf("%lld",&x);
		printf("%lld\n",solve(n,x));
	}
	return 0;
}