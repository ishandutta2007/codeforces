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
#define N 200005
int n,k,q;
int l[N],r[N],a[N],b[N];
bool ok[N];
int pre[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n);read(k);read(q);
	rep(i,1,n){read(l[i]); read(r[i]);}
	rep(i,1,n) a[i]=l[i];
	rep(i,1,n) b[i]=r[i];
	sort(a+1,a+n+1); //in
	sort(b+1,b+n+1); //out
	int cnt=0,h1=1,h2=1;
	rep(i,1,200000) { //mx
		while (h1<=n&&a[h1]<=i) {h1++;cnt++;}
		pre[i]=pre[i-1];
		if (cnt>=k) pre[i]++;
		while (h2<=n&&b[h2]<=i) {h2++;cnt--;}
	}
	rep(i,1,q) 
	{
		int x,y; read(x); read(y);
		printf("%d\n",pre[y]-pre[x-1]);
	}
	return 0;
}