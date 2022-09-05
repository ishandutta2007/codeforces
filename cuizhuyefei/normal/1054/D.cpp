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
int n,k,a[N];map<int,int>Map;
int main() {
	read(n);read(k);rep(i,1,n)read(a[i]);
	rep(i,1,n)a[i]^=a[i-1];
	rep(i,0,n)Map[min(a[i],a[i]^((1<<k)-1))]++;
	ll res=1LL*n*(n+1)/2;
	while(!Map.empty()){
		ll x=(*Map.begin()).se,y=x/2;
		res-=y*(y-1)/2+(x-y)*(x-y-1)/2;
		Map.erase(Map.begin());
	}
	cout<<res;return 0;
}