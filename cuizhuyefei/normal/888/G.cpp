#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 203000, M = 7030000;
int n,a[N];
int ch[M][2],cnt,sz[M];
inline void init() {
	rep(i,0,cnt) sz[i]=ch[i][0]=ch[i][1]=0; cnt=0;
}
inline void ins(int bit, int x) {
	int now=0;
	per(i,bit,0) {
		int v=(x>>i)&1;
		if (!ch[now][v]) ch[now][v]=++cnt;
		now=ch[now][v]; sz[now]++;
	}
}
inline int query(int bit, int x) {
	int res=0,now=0;
	per(i,bit,0) {
		int v=(x>>i)&1;
		if (ch[now][v]&&sz[ch[now][v]]) now=ch[now][v];
		else {now=ch[now][v^1]; res+=1<<i;}
	}
	return res;
}
inline ll solve(int bit, int l, int r) {
	if (l==r||bit<0) return 0;
	if (((a[l]>>bit)&1)==((a[r]>>bit)&1)) return solve(bit-1,l,r);
	int mid=l,L=l,R=r;
	while (L<=R) {
		int M=(L+R)>>1;
		if (((a[M]>>bit)&1)==0) {mid=M; L=M+1;} else R=M-1;
	}
	int mincost=2e9;
	init(); rep(i,l,mid) ins(bit-1,a[i]);
	rep(i,mid+1,r) mincost=min(mincost,query(bit-1,a[i]));
	mincost+=1<<bit;
	return solve(bit-1,l,mid)+solve(bit-1,mid+1,r)+mincost;
}
int main() { //freopen("1.in","r",stdin);
	read(n); rep(i,1,n) read(a[i]); sort(a+1,a+n+1);
	printf("%lld",solve(30,1,n));
	return 0;
}