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
const int N = 2005;
int k,n=2,S=1,T=2,bh[33][4];
bool e[N][N];
void add(int u, int v) {e[u][v]=e[v][u]=1;}
int main() {
	read(k); add(S,bh[0][1]=++n); add(S,bh[0][2]=++n); add(S,bh[0][3]=++n);
	rep(i,1,30) {
		bh[i][1]=++n; bh[i][2]=++n; bh[i][3]=++n;
		rep(j,1,3) add(bh[i-1][1],bh[i][j]),add(bh[i-1][2],bh[i][j]);
	}
	rep(bit,0,30) if ((k>>bit)&1) {
		int lst=bh[bit][3];
		rep(i,bit+1,30) {
			add(lst,++n); lst=n;
		}
		add(lst,T);
	}
	printf("%d\n",n);
	rep(i,1,n) {rep(j,1,n) printf("%c",e[i][j]?'Y':'N'); puts("");}
	return 0;
}