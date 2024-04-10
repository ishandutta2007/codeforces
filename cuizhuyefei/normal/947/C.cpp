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
const int N = 600000, M = 10500000;
int n,a[N],p[N],ans[N];

int ch[M][2],size[M],tot;
inline void ins(int x, int bit, int val) {
	int now=0;
	per(i,30,0) {
		int c=(x>>i)&1;
		if (!ch[now][c]) ch[now][c]=++tot;
		now=ch[now][c]; size[now]+=val;
	}
}
inline int query(int x) {
	int res=0,now=0;
	per(i,30,0) {
		int c=((x>>i)&1);
		if (ch[now][c]&&size[ch[now][c]]) now=ch[now][c];
		else {now=ch[now][c^1]; res+=(1<<i);}
	}
	return res;
}
int main() {
	read(n); rep(i,1,n) read(a[i]); rep(i,1,n) read(p[i]);
	rep(i,1,n) ins(p[i],30,1);
	rep(i,1,n) {
		ans[i]=query(a[i]); ins(ans[i]^a[i],30,-1);
	}
	
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}