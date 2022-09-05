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
const int inf = 0x3f3f3f3f;
int n,s[2333],t[2333];
int f[10][2020][800];
int val[10007],cnt,dy[10007];
inline int query(int u) {
	if (!val[u]) val[u]=++cnt,dy[cnt]=u; return val[u];
}
inline void umin(int &a, int b) {a=min(a,b);}
inline int Abs(int x) {return x>=0?x:-x;}
inline int dp(int now, int a, int b) {
	int &val=f[now][a][b]; if (val>=0) return val; if (a==n&&dy[b]==0) return val=0;
	val=inf;
//	if (now+1<=9) umin(val,dp(now+1,a,b)+1);
//	if (now-1>=1) umin(val,dp(now-1,a,b)+1);
	rep(now,1,9) {
	int &val=f[now][a][b]; val=inf;
	if (a+1<=n&&s[a+1]==now&&dy[b]<=999) {
		int s=dy[b]; multiset<int> Set; while (s) {Set.insert(s%10); s/=10;}
		Set.insert(t[a+1]); int nb=0; while (!Set.empty()) {
			multiset<int> ::iterator it=Set.end(); it--;
			nb=nb*10+(*it); Set.erase(it);
		}
		umin(val,dp(now,a+1,query(nb))+1);
	}
	if (b) {
		int s=dy[b],cnt=0,nb=0; multiset<int> Set; while (s) {Set.insert(s%10); s/=10;}
		while (!Set.empty()) {
			multiset<int> ::iterator it=Set.end(); it--;
			if ((*it)!=now) nb=nb*10+(*it); else cnt++; Set.erase(it);
		}
		if (cnt) umin(val,dp(now,a,query(nb))+cnt);
	}
	}
	rep(i,1,9) rep(j,1,9) umin(f[i][a][b],f[j][a][b]+Abs(i-j));
	return val;
}


int main() {
	read(n); rep(i,1,n) read(s[i]),read(t[i]);
	memset(f,-1,sizeof(f));
	printf("%d",dp(1,0,query(0)));
	return 0;
}