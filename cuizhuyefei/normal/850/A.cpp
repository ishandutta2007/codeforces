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
const int N = 2333;
int n;
struct node {
	int a[5];
	bool operator < (const node &x) const {
		rep(i,0,4) if (a[i]!=x.a[i]) return a[i]<x.a[i];
		return 0;
	}
} v[N];
Vi ans;
void solve(int i) {
	rep(a,1,n) rep(b,a+1,n) if (a!=i&&b!=i) {
		int res=0; rep(x,0,4) res+=(v[b].a[x]-v[i].a[x])*(v[a].a[x]-v[i].a[x]);
		if (res>0) {return;}
	}
	ans.push_back(i);
}
int main() {
	read(n); rep(i,1,n) rep(j,0,4) read(v[i].a[j]);
//	random_shuffle(v+1,v+n+1);
	rep(i,1,n) solve(i); int len=ans.size(); printf("%d\n",len);
	rep(i,0,len-1) printf("%d ",ans[i]);
	return 0;
}