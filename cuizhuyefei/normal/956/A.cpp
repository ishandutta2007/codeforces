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
const int N = 505;
int n,m,l[N],c[N];
char s[N][N],mrk[N][N];
bool gg;
int sta1[N*N],top1,sta2[N*N],top2;
int main() {
	read(n); read(m);
	rep(i,1,n) scanf("%s",s[i]+1);
	rep(j,1,m) if (!c[j]) {
		top1=top2=0;
		rep(i,1,n) if (s[i][j]=='#'&&!mrk[i][j]) {
			sta1[++top1]=i;
		}
		rep(i,1,top1) {
			int a=sta1[i];
			rep(b,1,m) if (s[a][b]=='#'&&!mrk[a][b]) sta2[++top2]=b;
		}
		sort(sta2+1,sta2+top2+1);
		top2=unique(sta2+1,sta2+top2+1)-sta2-1;
		rep(x,1,top1) rep(y,1,top2) 
			if (mrk[sta1[x]][sta2[y]]||(s[sta1[x]][sta2[y]]!='#')) gg=1;
			else mrk[sta1[x]][sta2[y]]=1;
		rep(x,1,top1) if (!l[sta1[x]]) l[sta1[x]]=1; else gg=1;
		rep(y,1,top2) if (!c[sta2[y]]) c[sta2[y]]=1; else gg=1;
	}
	rep(i,1,n) rep(j,1,m) if (s[i][j]=='#'&&!mrk[i][j]) gg=1;
	if (!gg) puts("Yes"); else puts("No");
	return 0;
}