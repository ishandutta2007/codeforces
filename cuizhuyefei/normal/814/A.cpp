#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
#define N 100005
int n,k;
int a[N],b[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool judge() {
	if (k>1) return 1;
	rep(i,1,n) if (!a[i]) a[i]=b[1];
	rep(i,1,n-1) rep(j,i+1,n)
		if (a[i]>=a[j]) return 1;
	return 0;
}
int main() {
	read(n); read(k);
	rep(i,1,n) read(a[i]);
	rep(i,1,k) read(b[i]);
	if (judge()) puts("Yes");
	else puts("No");
	return 0;
}