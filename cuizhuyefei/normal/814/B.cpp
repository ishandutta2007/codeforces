#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
#define N 10005
int n,a[N],b[N],ans[N];
bool vis[N];
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
void geta() {
	rep(k,1,n) {
		memset(vis,0,sizeof(vis));
		bool flag=1;
		rep(i,1,n) if (i!=k) {
			if (vis[a[i]]) {flag=0;break;}
			vis[a[i]]=1;
		}
		if (!flag) continue;
		int p=0;
		rep(i,1,n) if (!vis[i]) p=i;
		rep(i,1,n)
			if (i!=k) ans[i]=a[i];
			else ans[i]=p;
		int cnt=0;
		rep(i,1,n) if (ans[i]!=b[i]) cnt++;
		if (cnt==1) break;
	}
}
int main() {
	read(n);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) read(b[i]);
	geta();
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}