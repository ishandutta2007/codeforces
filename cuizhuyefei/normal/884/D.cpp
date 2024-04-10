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
const int N = 200003;
int n,a[N];
ll sum,ans;
priority_queue<ll,vector<ll>,greater<ll> > heap;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); rep(i,1,n) read(a[i]);
	rep(i,1,n) sum+=a[i];
	rep(i,1,n) heap.push(a[i]);
	if (n%2==0) {int u=heap.top(); heap.pop(); int v=heap.top(); heap.pop(); ans+=u+v; heap.push(u+v);}
	while (heap.size()>1) {
		ll u=heap.top(); heap.pop();
		ll v=heap.top(); heap.pop();
		ll d=heap.top(); heap.pop();
		ans+=u+v+d; heap.push(u+v+d);
	}
	/*int p=n;
	while (p>1) {
		if (p>3) {
			ans+=sum; sum-=a[p]+a[p-1]; p-=2;
		}
		else {ans+=sum; break;}
	}*/
	printf("%lld",ans);
	return 0;
}