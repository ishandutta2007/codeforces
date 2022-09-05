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
const int N = 666666;
int n,m,a[N],ans[N],v[N],id[N];vector<Pii>que[N];
void add(int p, int x){while(p<=n)v[p]+=x,p+=p&-p;}
int qry(int p){int r=0;while(p)r+=v[p],p-=p&-p;return r;}
bool cmp(int x, int y){
	return a[x]!=a[y]?a[x]>a[y]:x<y;
}
int main() {
	read(n);rep(i,1,n)read(a[i]),id[i]=i;
	read(m);rep(i,1,m){
		int k,p;read(k);read(p);que[k].pb(Pii(p,i));
	}
	sort(id+1,id+n+1,cmp);
	rep(t,1,n){
		add(id[t],1);
		rep(i,0,SZ(que[t])-1){
			int k=que[t][i].fi,l=1,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(qry(mid)<k)l=mid+1;else ans[que[t][i].se]=mid,r=mid-1;
			}
		}
	}
	rep(i,1,m)printf("%d\n",a[ans[i]]);
	return 0;
}