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
const int N = 666666,inf=0x3f3f3f3f, M = 6666666;
struct node{
	int a,b,c,d;
}s[N];int n;
void GG(){puts("NO");exit(0);}

struct Tree{
int val[M],lc[M],rc[M],tot;
void modify(int &k, int p, int l, int r){
	if(!k)k=++tot;val[k]++;if(l==r)return;
	int mid=(l+r)>>1;
	if(p<=mid)modify(lc[k],p,l,mid);
	else modify(rc[k],p,mid+1,r);
}
int qry(int k, int l, int r, int L, int R){
	if(!k||l==L&&r==R)return val[k];
	int mid=(L+R)>>1;
	if(r<=mid)return qry(lc[k],l,r,L,mid);
	if(l>mid)return qry(rc[k],l,r,mid+1,R);
	return qry(lc[k],l,mid,L,mid)+qry(rc[k],mid+1,r,mid+1,R);
}
void ini(){
	rep(i,0,tot)lc[i]=rc[i]=val[i]=0;tot=1;
}
}a,b;
bool cmp(node x, node y){return x.a<y.a;}
void solve(){
	a.ini();b.ini();
	sort(s+1,s+n+1,cmp);
	priority_queue<Pii,vector<Pii>,greater<Pii> >heap;
	int cnt=0,rt=1;
	rep(i,1,n){
		heap.push(Pii(s[i].b,i));
		while(!heap.empty()&&heap.top().fi<s[i].a){
			int j=heap.top().se;
			a.modify(rt,s[j].d,0,inf);b.modify(rt,s[j].c,0,inf);cnt++;heap.pop();
		}
	//	printf("%d:%d %d %d %d %d %d\n",i,cnt,a.qry(rt,0,s[i].c-1,0,inf)+b.qry(rt,s[i].d+1,inf,0,inf),s[i].a,s[i].b,s[i].c,s[i].d);
		if(cnt!=a.qry(rt,0,s[i].c-1,0,inf)+b.qry(rt,s[i].d+1,inf,0,inf))GG();
	}
}
int main() {
	read(n);
	rep(i,1,n)read(s[i].a),read(s[i].b),read(s[i].c),read(s[i].d);
	solve();
	rep(i,1,n)swap(s[i].a,s[i].c),swap(s[i].b,s[i].d);
	solve();
	puts("YES");
	return 0;
}