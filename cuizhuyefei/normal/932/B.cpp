#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 1020000;


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int q,l,r,k,g[N];
int s[10][N];
inline int f(int n) {
	int res=1;
	while (n) {res*=(n%10 ? n%10 : 1); n/=10;}
	return res;
}
int main() {
	read(q);
	rep(i,1,1000000) 
		if (i<=9) g[i]=i;
		else g[i]=g[f(i)];
	rep(i,1,9) rep(j,1,1000000)
		s[i][j]=s[i][j-1]+(g[j]==i);
	rep(T,1,q) {
		read(l); read(r); read(k);
		printf("%d\n",s[k][r]-s[k][l-1]);
	}
	return 0;
}