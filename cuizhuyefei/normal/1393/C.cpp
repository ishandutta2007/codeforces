#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 6e5+11;
int n,a[N],b[N],tim[N];
priority_queue<Pii>heap;
bool ck(int mid){
	rep(i,1,n)b[i]=0,tim[i]=0;
	rep(i,1,n)b[a[i]]++;
	while(!heap.empty())heap.pop();
	rep(i,1,n)if(b[i])heap.push(mp(b[i],i));
	rep(i,1,n){
		if(tim[i])heap.push(mp(b[tim[i]],tim[i]));
		if(heap.empty())return 0;
		auto x=heap.top();heap.pop();
	//	cerr<<i<<' '<<x.se<<endl;
		b[x.se]--;if(b[x.se])tim[i+mid+1]=x.se;
	}
	return 1;
}
int main() {
	int T;read(T);while(T--){
		read(n);rep(i,1,n)read(a[i]),b[i]=0,b[a[i]]++;
		int l=0,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(ck(mid))l=mid;else r=mid-1;
		}
		cout<<l<<endl;
	}
	return 0;
}