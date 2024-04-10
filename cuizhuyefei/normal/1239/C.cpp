#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666;const ll inf=1e18;
ll n,p;int id[N],t[N],q[N],f,r;
priority_queue<int,vector<int>,greater<int> >heap;
set<int>inque;
ll ans[N];
bool cmp(int x, int y){return t[x]!=t[y]?t[x]<t[y]:x<y;}
int main() {
	read(n);read(p);rep(i,1,n)read(t[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	ll cnt=0,cur=0,pos=0;
	while(f<n){
		ll A=pos+1<=n?t[id[pos+1]]:inf;
		ll B=f!=r?ans[q[f]]:inf;
		cur=min(A,B);
		while(pos+1<=n&&t[id[pos+1]]<=cur)
			pos++,heap.push(id[pos]);
		if(f!=r&&ans[q[f]]<=cur){
			inque.erase(q[f]);
			if(f+1<r)ans[q[f+1]]=ans[q[f]]+p;
			f++;
		}
		if(!heap.empty()&&(inque.empty()||heap.top()<*inque.begin())){
			int u=heap.top();heap.pop();
		//	cerr<<cur<<' '<<u<<endl;
			inque.insert(u);q[r++]=u;if(f+1==r)ans[q[f]]=cur+p;
		}
	}
//	rep(i,0,r-1)cerr<<q[i]<<' ';cerr<<endl;
	rep(i,1,n)printf("%lld ",ans[i]);
	return 0;
}