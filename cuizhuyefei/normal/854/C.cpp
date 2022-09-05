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
const int N = 300003;
int n,k,res[N],c[N];
ll ans=0;
struct X {
	int v,ind;
	bool operator < (const X &a) const {
		return v<a.v;
	}
} s[N],tmp;
priority_queue<X> heap;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
//bool cmp(X a, X b) {return a.v>b.v;}
int main() {
	read(n); read(k);
	rep(i,1,n) read(s[i].v),s[i].ind=i;
	/*sort(s+1,s+n+1,cmp);
	for (int i=k+1; i<=k+n; i++)
		res[s[i-k].ind]=i;
	rep(i,1,n) ans+=c[i]*();*/
	rep(i,1,min(k,n)) heap.push(s[i]);
	rep(i,k+1,k+n) {
		if (i<=n) heap.push(s[i]);
		tmp=heap.top(); heap.pop();
		ans+=(ll)tmp.v*(i-tmp.ind); res[tmp.ind]=i;
	}
	cout<<ans<<endl;
	rep(i,1,n) printf("%d ",res[i]);
	return 0;
}