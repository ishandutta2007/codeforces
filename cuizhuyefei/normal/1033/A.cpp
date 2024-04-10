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
const int N = 1020000;
int n,a,b,c,d,e,F,ok[1020][1020],f[N];
int find(int x){return f[x]==x?f[x]:f[x]=find(f[x]);}
int Get(int x, int y){return (x-1)*n+y;}
int main() {
	read(n);
	read(a);read(b);
	read(c);read(d);
	read(e);read(F);
	rep(i,1,n)rep(j,1,n){
		ok[i][j]=1;
		if(i==a||j==b)ok[i][j]=0;
		if(i+j==a+b||i-j==a-b)ok[i][j]=0;
	}
	rep(i,1,N-1)f[i]=i;//WA
	rep(i,1,n)rep(j,1,n)rep(k,-1,1)rep(l,-1,1){
		int x=i+k,y=j+l;//WA
		if(x>=1&&x<=n&&y>=1&&y<=n&&ok[i][j]&&ok[x][y]){
			int u=find(Get(i,j)),v=find(Get(x,y));
			f[u]=v;
		}
	}
	printf("%s",find(Get(c,d))==find(Get(e,F))?"YES":"NO");
	return 0;
}