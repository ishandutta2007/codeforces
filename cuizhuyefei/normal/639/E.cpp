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
const int N = 166666;
int n,len,id[N],bel[N],bg[N],ed[N];double T=0,c=1,qz[N],v[N];
struct node{
	int p,t;double x;
}s[N],a[N];
bool cmp1(node a, node b){return 1LL*a.t*b.p!=1LL*a.p*b.t?1LL*a.t*b.p<1LL*a.p*b.t:a.p<b.p;}
bool cmp2(node a, node b){return a.p!=b.p?a.p<b.p:1LL*a.t*b.p>1LL*a.p*b.t;}
bool cmp3(int a, int b){return s[a].p<s[b].p;}
bool ck(double mid){
	rep(i,1,n)v[i]=0;double mx=0;
	for(int i=1,j=0;i<=n;i++){
		while(s[id[j+1]].p<s[id[i]].p)j++,umax(mx,1.0*s[id[j]].p*T-mid*s[id[j]].p*(qz[bg[id[j]]-1]+s[id[j]].t));
		if(1.0*s[id[i]].p*T-mid*s[id[i]].p*qz[ed[id[i]]]<mx)return 0;
	}
	/*rep(i,1,n)rep(j,1,n)if(s[id[i]].p>s[id[j]].p&&bel[id[i]]>=bel[id[j]])
		if(1.0*s[id[i]].p*T-mid*s[id[i]].p*qz[ed[id[i]]]<1.0*s[id[j]].p*T-mid*s[id[j]].p*(qz[bg[id[j]]-1]+s[id[j]].t))
			return 0;*/
	return 1;
}
int main() {
	read(n);rep(i,1,n)read(s[i].p);
	rep(i,1,n)read(s[i].t),T+=s[i].t;
	sort(s+1,s+n+1,cmp1);
	rep(i,1,n)s[i].x=s[i-1].x+s[i].t;
//	cerr<<T<<endl;
//	rep(i,1,n)cerr<<s[i].p<<' ';cerr<<endl;
//	rep(i,1,n)cerr<<s[i].t<<' ';cerr<<endl;
	rep(i,1,n)qz[i]=qz[i-1]+s[i].t;
	int tot=0;
	rep(l,1,n){
		int r=l;while(r+1<=n&&1LL*s[l].t*s[r+1].p==1LL*s[l].p*s[r+1].t)r++;
		tot++;rep(i,l,r)bel[i]=tot,bg[i]=l,ed[i]=r;
		l=r;
	}
	rep(i,1,n)id[i]=i;sort(id+1,id+n+1,cmp3);
	double L=0,R=1;
	while(R-L>1e-7){
		double mid=(L+R)/2;
		if(ck(mid))L=mid;else R=mid;
	}
	umin(c,L);
	
	sort(s+1,s+n+1,cmp2);
	rep(i,2,n)if(s[i].p!=s[i-1].p){
		double a=s[i].p*s[i].x-s[i-1].p*s[i-1].x;
		if(a>0)umin(c,(s[i].p-s[i-1].p)/a*T);
	}
	printf("%.9lf\n",c);
	return 0;
}