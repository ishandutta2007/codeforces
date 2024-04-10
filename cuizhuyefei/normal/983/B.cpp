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
const int N = 5050;
int n,f[N][N],a[N];
int main() {
	read(n); rep(i,1,n) read(a[i]);
	rep(i,1,n) f[i][i]=a[i];
	rep(l,1,n-1) rep(i,1,n-l) {
		int j=i+l; f[i][j]=f[i][j-1]^f[i+1][j];
	}
	rep(l,1,n-1) rep(i,1,n-l) {
		int j=i+l; f[i][j]=max(f[i][j],max(f[i][j-1],f[i+1][j]));
	}
	int q; read(q);
	while (q--) {int l,r;read(l);read(r);printf("%d\n",f[l][r]);}
	return 0;
}