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
const int N = 202000;
int n,k;set<int>Set;bool f[N];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main() {
	read(n);read(k);f[0]=1;
	rep(i,1,n){int x;read(x);Set.insert(gcd(x,k));}
	while(!Set.empty()){
		int d=*Set.begin();Set.erase(Set.begin());
		rep(i,d,2*k)f[i]|=f[i-d];
		rep(i,0,k-1)f[i]|=f[i+k];
	}
	int cnt=0;rep(i,0,k-1)cnt+=f[i];
	printf("%d\n",cnt);rep(i,0,k-1)if(f[i])printf("%d ",i);
	return 0;
}