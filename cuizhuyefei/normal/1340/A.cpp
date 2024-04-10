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

const int N = 1777777;
int n,a[N],pos[N],pre[N],nxt[N];multiset<int>heap;
int main() {
	int t;read(t);while(t--){
		read(n);rep(i,1,n)read(a[i]),pos[a[i]]=i;
		heap.clear();//while(!heap.empty())heap.pop();
		bool ok=1;
		rep(i,1,n)pre[i]=i-1,nxt[i-1]=i;nxt[n]=pre[0]=0;
		rep(i,1,n)heap.insert(1);
		rep(v,1,n){
			int p=pos[v];
			if(*heap.rbegin()!=p-pre[p]){ok=0;break;}
			heap.erase(--heap.end());
			if(nxt[p]){
				heap.erase(heap.find(nxt[p]-p));
				heap.insert(nxt[p]-pre[p]);
			}
			pre[nxt[p]]=pre[p];nxt[pre[p]]=nxt[p];
			nxt[p]=pre[p]=0;
		}
		
		printf("%s\n",ok?"Yes":"No");
	}
	return 0;
}