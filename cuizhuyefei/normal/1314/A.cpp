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
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
int n;Pii a[N];ll res,cur;priority_queue<int>heap;
int main() {
	read(n);//rep(i,1,n)read(a[i].fi),read(a[i].se);
	rep(i,1,n)read(a[i].fi);
	rep(i,1,n)read(a[i].se);
	a[n+1].fi=2e9;
	sort(a+1,a+n+1);
	for(int p=1,t=a[1].fi;p<=n;){
		int T=a[p].fi;
		while(p<=n&&a[p].fi==T){
			t=a[p].fi;heap.push(a[p].se);cur+=a[p].se;
			p++;
		}
		cur-=heap.top();heap.pop();res+=cur;
	//	printf("%d %d %lld\n",T,p,heap.size());
		while(SZ(heap)&&t+1<a[p].fi){
			cur-=heap.top();heap.pop();t++;res+=cur;
		}
	}
	cout<<res;
	return 0;
}