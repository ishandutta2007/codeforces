#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
const int N = 200005;
int n,m,a[N],seed,vmax;
struct node {
	int l,r; ll v;
	node(int L, int R, ll V) {l=L; r=R; v=V;}
	bool operator < (const node &a) const {
		return l<a.l;
	}
};
set<node> seg;
set<node> ::iterator it,tmp;
vector<node> rec;
inline int rnd() {
    int ret = seed;
    seed = (1LL * seed * 7 + 13) % 1000000007;
    return ret;
}
inline void getseg(int l, int r) {
	rec.clear(); it=seg.upper_bound(node(l,233333,0)); it--; node u=*it;
	rec.push_back(node(l,min(u.r,r),u.v)); it++;
	while (it!=seg.end() && (*it).l<=r) {
		node u=*it; rec.push_back(node(u.l,min(u.r,r),u.v)); it++;
	}
}
inline void splseg(int l, int r) {
	rec.clear(); it=seg.upper_bound(node(l,233333,0)); it--; node u=*it;
	rec.push_back(node(l,min(u.r,r),u.v)); tmp=it; it++;
	seg.erase(tmp); if (u.l<=l-1) seg.insert(node(u.l,l-1,u.v));
	if (r+1<=u.r) seg.insert(node(r+1,u.r,u.v));
	while (it!=seg.end() && (*it).l<=r) {
		node u=*it; rec.push_back(node(u.l,min(u.r,r),u.v));
		tmp=it; it++; seg.erase(tmp); if (r+1<=u.r) seg.insert(node(r+1,u.r,u.v));
	}
}
inline void solve1(int l, int r, int x) {
	splseg(l,r); int len=rec.size();
	rep(i,0,len-1) rec[i].v+=x,seg.insert(rec[i]);
}
inline void solve2(int l, int r, int x) {
	splseg(l,r); int len=rec.size();
	seg.insert(node(l,r,x));
}
bool cmp(node a, node b) {
	return a.v<b.v;
}
inline ll solve3(int l, int r, int x) {
	getseg(l,r); int len=rec.size();
	sort(rec.begin(),rec.end(),cmp);
	rep(i,0,len-1) {x-=(rec[i].r-rec[i].l+1); if (x<=0) return rec[i].v;}
}
inline int power(int a, int n, int mo) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo;
		n>>=1;
	}
	return res;
}
inline int solve4(int l, int r, int x, int y) {
	getseg(l,r); int len=rec.size();
	int res=0;
	rep(i,0,len-1) {
		(res+=1LL*(rec[i].r-rec[i].l+1)*power(rec[i].v%y,x,y)%y)%=y;
	//	printf("F**k %d : %d %d %d %lld\n",i,x,y,rec[i].r-rec[i].l+1,rec[i].v);
	}
	if (res<0) puts("F**k");
	return res;
}
int main() {
//freopen("1.in","r",stdin);
//freopen("1.out","w",stdout);
read(n); read(m); read(seed); read(vmax);
rep(i,1,n) a[i] = (rnd() % vmax) + 1;
rep(i,1,n) seg.insert(node(i,i,a[i]));
rep(i,1,m) {
	int op,l,r,x,y;
    op = (rnd() % 4) + 1;
    l = (rnd() % n) + 1;
    r = (rnd() % n) + 1;
    if (l > r) swap(l, r);
    if (op == 3) x = (rnd() % (r - l + 1)) + 1;
    else x = (rnd() % vmax) + 1;
    if (op == 4) y = (rnd() % vmax) + 1;
    if (op==1) solve1(l,r,x);
    if (op==2) solve2(l,r,x);
    if (op==3) printf("%lld\n",solve3(l,r,x));
    if (op==4) printf("%d\n",solve4(l,r,x,y));
 //   printf("%d : %d %d %d %d %d\n",i,op,l,r,x,y);
    int num=0;
 //   for (it=seg.begin(); it!=seg.end(); it++) printf("[%d %d %lld]",(*it).l,(*it).r,(*it).v); puts("");
 //   for (it=seg.begin(); it!=seg.end(); it++) {num+=(*it).r-(*it).l+1; if ((*it).l>(*it).r) puts("Fuck you");}
//    if (num!=n) puts("tuiyile!");
}
	return 0;
}
//1.long long