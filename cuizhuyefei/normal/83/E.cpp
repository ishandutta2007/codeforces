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
#define V(i,l,r) (v[i][r]-(v[i][l-1]<<(r-l+1)))
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
const int N = 205000;
int n,l,f[N],S[N],g[21][1048577],mx,nxt[43]; //mx = max(f[j]-S[j+1]) (len=0)
int v[N][23];
char s[N][23],t[43];
inline int getlcp_(int k) { //s[k-1], s[k]
	int len=0; rep(i,1,l) t[++len]=s[k][i]; t[++len]='#';
	rep(i,1,l) t[++len]=s[k-1][i];
	for (int i=2,j=0; i<=len; i++) {
		while (j&&t[j+1]!=t[i]) j=nxt[j];
		if (t[j+1]==t[i]) j++;
		nxt[i]=j;
	}
	return nxt[len];
}
inline void umax(int &a, int b) {a=a>b?a:b;}
int main() { //freopen("1.in","r",stdin);
	read(n); rep(i,1,n) scanf("%s",s[i]+1); l=strlen(s[1]+1);
	rep(i,1,n) rep(j,1,l) s[i][j]=s[i][j]=='1',v[i][j]=(v[i][j-1]<<1)|s[i][j];
	rep(i,2,n) S[i]=S[i-1]+getlcp_(i); memset(g,0xaf,sizeof(g));
	rep(i,1,n) {
		f[i]=S[i]+mx; if (i==n) break;
		rep(j,1,l) f[i]=max(f[i],j+S[i]+g[j][V(i+1,1,j)]);
		rep(j,1,l) umax(g[l-j+1][V(i,j,l)],f[i]-S[i+1]); mx=max(mx,f[i]-S[i+1]);
	}
	cout<<n*l-f[n];
	return 0;
}