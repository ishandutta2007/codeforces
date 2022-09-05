#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define all ((1<<n)-1)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();}
}
const int N = 4444444;
int n,m,a[N]; bool vis[N],bo[N];
inline void dfs(int x) {
	vis[x]=1; //if (!bo[x]) return;
	int s=x; while (s) {
		int bit=s&-s; s-=bit; if (!vis[x^bit]) dfs(x^bit);
	}
	if (bo[x]&&!vis[x^all]) dfs(x^all);
}
int main() {
	read(n);read(m);rep(i,1,m)read(a[i]),bo[a[i]]=1;
	int res=0;
	rep(i,1,m) if (!vis[a[i]]) {
		res++; vis[a[i]]=1; dfs(a[i]^all);
	}
	cout<<res;
	return 0;
}