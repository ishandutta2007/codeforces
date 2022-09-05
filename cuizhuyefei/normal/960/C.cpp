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
const int N = 233333;
int x,d,n;
ll a[N];
int main() {
	read(x); read(d);
	ll now=1;
	per(i,30,1) while (x>=(1<<i)-1) {
		x-=(1<<i)-1;
		rep(k,1,i) a[++n]=now;
		now+=d+2;
	}
	
	printf("%d\n",n);
	rep(i,1,n)printf("%lld ",a[i]);
	return 0;
}