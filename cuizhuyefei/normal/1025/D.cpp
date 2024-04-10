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
const int N = 777;
int n,p[N],ok[N][N],a[N][N],b[N][N];
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
int main() {
	read(n);rep(i,1,n)read(p[i]);
	rep(i,1,n)rep(j,1,n)ok[i][j]=gcd(p[i],p[j])>1;
	rep(i,1,n)a[i][i]=b[i][i]=1;
	rep(len,1,n-1)rep(i,1,n){
		int l=i-len;
		if(l>=1){
			rep(mid,l,i-1)a[i][l]|=a[mid][l]&&b[mid][i-1]&&ok[i][mid];
		}
		int r=i+len;
		if(r<=n){
			rep(mid,i+1,r)b[i][r]|=a[mid][i+1]&&b[mid][r]&&ok[i][mid];
		}
	}
	bool res=0;rep(i,1,n)res|=(a[1][i]&&b[i][n]);
	if(res)puts("Yes");else puts("No");
	return 0;
}