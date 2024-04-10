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
#define N 1550
int f[N][28];
int a[N],l,n,m;
char s[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int query(int m, char c) {
	if (f[m][c-'a']) return f[m][c-'a'];
	l=0; rep(i,1,n) if (s[i]==c) a[++l]=i;
	int L=1,R=1,ans=0;
	for (L=1; L<=l; L++) {
		if (R<L) R=L;
		while (R<l&&a[R+1]-a[L]+1-(R+1-L+1)<=m) R++;
		ans=max(ans,R-L+1);
	}
	f[m][c-'a']=min(ans+m,n);
	return f[m][c-'a'];
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); scanf("%s",s+1);
	read(m);
	rep(i,1,m) {
		int x; char a[5];
		read(x); scanf("%s",a);
		printf("%d\n",query(x,a[0]));
	}
	return 0;
}