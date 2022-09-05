#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<stack>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 210002; //2100
int n,q,a[N],s[N],M,bel[N],rec[N],b[N];
int P[N],X[N],ans[N];
struct que {int l,r,t,index;} Q[N];
int cntq,cntu;
//stack<int> xg[N];
bool cmp(que a, que b) {
	return (bel[a.l]!=bel[b.l])?a.l<b.l:(bel[a.r]!=bel[b.r]?a.r<b.r:a.t<b.t);
}
int TOT;
int cnt[N],c[N]; //ans is not so large.
//inline void ADD(int v) {c[v]++;}
//inline void DEL(int v) {c[v]--;}
#define ADD(x) {c[x]++;}
#define DEL(x) {c[x]--;}
inline void add(int v) {TOT++;
	DEL(cnt[v]); cnt[v]++; ADD(cnt[v]);
}
inline void del(int v) {TOT++;
	DEL(cnt[v]); cnt[v]--; ADD(cnt[v]);
}
inline int query() { //mex of "occurences"
	for (int i=1;;i++) if (!c[i]) return i;
}
int main() { //freopen("1.in","r",stdin); freopen("my.out","w",stdout);
	read(n); int q; read(q); rep(i,1,n) read(a[i]); M=pow(1.0*n,2.0/3.0)+1;
	memcpy(b,a,sizeof(a));
	while (q--) {
		int op; read(op);
		if (op==1) {
			int l,r; read(l); read(r);
			Q[++cntq].l=l; Q[cntq].r=r; Q[cntq].index=cntq;
			Q[cntq].t=cntu;
		}
		else {
			read(P[++cntu]); read(X[cntu]);
			rec[cntu]=b[P[cntu]]; b[P[cntu]]=X[cntu];
		}
	}
	int len=0; rep(i,1,n) s[++len]=a[i]; rep(i,1,cntu) s[++len]=X[i];
	sort(s+1,s+len+1); int tot=1; rep(i,2,len) if (s[i]!=s[i-1]) s[++tot]=s[i]; len=tot;
	rep(i,1,n) a[i]=lower_bound(s+1,s+len+1,a[i])-s;
	rep(i,1,cntu) X[i]=lower_bound(s+1,s+len+1,X[i])-s;
	rep(i,1,cntu) rec[i]=lower_bound(s+1,s+len+1,rec[i])-s;
//	rep(i,1,n) xg[i].push(a[i]);
	rep(i,0,N-1) bel[i]=i/M;
	sort(Q+1,Q+cntq+1,cmp);
//	printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
	register int L=1,R=0,t=0;
	rep(i,1,cntq) {
		while (L>Q[i].l) add(a[--L]);
		while (R<Q[i].r) add(a[++R]);
		while (L<Q[i].l) del(a[L++]);
		while (R>Q[i].r) del(a[R--]);
		while (t<Q[i].t) {
			t++; 
			if (P[t]>=L&&P[t]<=R) del(a[P[t]]);
			a[P[t]]=X[t];
			if (P[t]>=L&&P[t]<=R) add(a[P[t]]);
		} //WA1
		while (t>Q[i].t) {
			if (P[t]>=L&&P[t]<=R) del(a[P[t]]);
			a[P[t]]=rec[t];
			if (P[t]>=L&&P[t]<=R) add(a[P[t]]);
			t--;
		}
		ans[Q[i].index]=query();
	}
//	printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
//	printf("tot = %d\n",TOT);
//	return 0;
	rep(i,1,cntq) printf("%d\n",ans[i]);
	return 0;
}