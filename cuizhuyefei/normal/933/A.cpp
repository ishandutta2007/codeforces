#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 3030;
int n,a[N],cnt1[N],cnt2[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); rep(i,1,n) {read(a[i]);cnt1[i]=cnt1[i-1];cnt2[i]=cnt2[i-1];a[i]==1?cnt1[i]++,0:cnt2[i]++,0;}
	int ans=cnt2[n];
	rep(i,1,n) rep(j,i,n) 
		ans=max(ans,(cnt1[j]-cnt1[i-1])+cnt2[i-1]+cnt2[n]-cnt2[j]);
	rep(p,1,n) {
		int x=0,y=0;
		rep(i,1,p-1) {
			x=max(x,cnt1[i]+cnt2[p-1]-cnt2[i]);
		}
		rep(i,p,n) {
			y=max(y,cnt1[i]-cnt1[p-1]+cnt2[n]-cnt2[i]);
		}
		ans=max(ans,x+y);
	}
	printf("%d",ans);
	return 0;
}