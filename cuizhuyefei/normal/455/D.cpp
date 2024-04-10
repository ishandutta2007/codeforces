#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cassert>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();}
}
const int N = 102000, M = 443, T = 450; //343!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
int n,q,a[N],L[M],s[N];
struct b {
	short cnt[N];
	queue<int> q;
	inline void init(int L, int R) {
		rep(i,L,R) cnt[a[i]]++;
		per(i,R,L) q.push(a[i]);
	}
} blo[M];
inline int getkth(int k, int p) {
	register int pos=L[k+1]-1; queue<int> q=blo[k].q;
	while (pos>p) {
		q.pop(); pos--;
	}
	return q.front();
}
inline void erase(int k, int p) {
	register int pos=L[k+1]-1; queue<int> q=blo[k].q,t; assert(t.empty());
	while (pos>p) {
		register int x=q.front(); q.pop(); t.push(x); pos--;
	}
	if (!q.empty()) q.pop();
	while (!q.empty()) {t.push(q.front()); q.pop();}
	blo[k].q=t;
}
inline void ins(int k, int p, int v) {
	register int pos=L[k+1]-1; queue<int> q=blo[k].q,t; assert(t.empty());
	while (pos>=p) {
		register int x=q.front(); q.pop(); t.push(x); pos--;
	}
	t.push(v);
	while (!q.empty()) {t.push(q.front()); q.pop();}
	blo[k].q=t;
}
inline void modify(int l, int r) {
	register int lb=l/T,rb=r/T;
	if (lb==rb) {
		queue<int> q=blo[lb].q,t; while (!t.empty()) t.pop();
		int pos=L[lb+1]-1,rec;
		while (!q.empty()) {
			int x=q.front(); q.pop();
			if (pos==r) rec=x; else t.push(x);
			if (pos==l) t.push(rec);
			pos--;
		}
		blo[lb].q=t;
		return;
	}
	////////////////////////////////////////////////////////////////////////////
	rep(i,lb+1,rb) {s[i]=blo[i-1].q.front();} //insert	
	s[lb]=getkth(rb,r); //r-th number
	rep(i,lb,rb) {
		if (i<rb) blo[i].cnt[blo[i].q.front()]--;
		else blo[i].cnt[s[lb]]--;
		blo[i].cnt[s[i]]++;
	}	
	rep(i,lb,rb) {
		if (i==lb) {
			ins(i,l,s[i]); blo[i].q.pop();
			continue;
		}
		if (i<rb) blo[i].q.pop(); 
		else erase(i,r);
		if (i>lb) blo[i].q.push(s[i]);
		else ins(i,l,s[i]);
	}
}
inline int query(int k, int l, int r, int v) {
	int res=0,pos=L[k+1]-1; queue<int> q=blo[k].q;
	while (pos>=l) {
		int x=q.front(); q.pop(); res+=(pos<=r&&x==v); pos--;
	}
	return res;
}
inline int query(int l, int r, int k) {
	int lb=l/T,rb=r/T;
	if (lb==rb) return query(lb,l,r,k);
	int res=query(lb,l,L[lb+1]-1,k)+query(rb,L[rb],r,k);
	rep(i,lb+1,rb-1) {res+=blo[i].cnt[k];}
	return res;
}
Pii tt[N];
int main() { //freopen("2.in","r",stdin);   //freopen("2.out","w",stdout);
	read(n); rep(i,1,n) read(a[i]);
	rep(i,1,n) if (!L[i/T]) L[i/T]=i; L[n/T+1]=n+1;
	rep(i,0,n/T) blo[i].init(L[i],L[i+1]-1);
	read(q); int lst=0,len=0;
	while (q--) {
		int op,l,r; read(op); read(l); read(r);
		l=(l+lst-1)%n+1; r=(r+lst-1)%n+1; if (l>r) swap(l,r);
		if (op==1) {
			tt[++len]=Pii(l,r);
		//	modify(l,r);
		}
		else {
			int k; read(k); k=(k+lst-1)%n+1;
			rep(i,1,len) modify(tt[i].fi,tt[i].se);
			len=0;
			lst=query(l,r,k); printf("%d\n",lst);
		}
	}
	return 0;
}