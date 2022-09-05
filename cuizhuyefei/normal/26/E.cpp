#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 2500050;
int n,w,a[N];
Vi ans;
int y[N],sta[N];
int getans(int len) {
	int res=0;
	rep(i,0,len-1) {
		if (!sta[ans[i]]) y[ans[i]]=res;
		else res=y[ans[i]]+1;
		sta[ans[i]]^=1;
	}
	return res;
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(w); rep(i,1,n) read(a[i]); int exp=w;
	int len=0,pos=1; rep(i,1,n) {len+=a[i]; if (a[i]<a[pos]) pos=i;}
	if (w>len||w<1) {puts("No"); return 0;} len*=2;
	if (n==1) { //Case #3
		if (w==a[1]) {puts("Yes"); rep(i,1,len) printf("%d ",1);}
		else puts("No");
		return 0;
	}
	if (w==1) { //Case #4
		if (a[pos]>1) puts("No");
		else {
			puts("Yes");
			rep(i,1,n) printf("%d ",i);
			rep(i,1,n) if (i!=pos) rep(j,1,2*a[i]-1) printf("%d ",i);
			printf("%d",pos);
		}
		return 0;
	}
	if (w<a[pos]) { //Case #1
		int t=2*(a[pos]-w+1)-1; rep(i,1,n) a[i]*=2;
		rep(i,1,n) {ans.push_back(i); a[i]--;}
		rep(i,1,t) {ans.push_back(pos); a[pos]--;}
		rep(i,1,n) if (a[i]&&i!=pos) {ans.push_back(i); a[i]--; break;}
		ans.push_back(pos); a[pos]--;
		rep(i,1,n) if (i!=pos) while (a[i]--) ans.push_back(i);
		while (a[pos]--) ans.push_back(pos); assert(getans(len)==w);
		puts("Yes"); rep(i,0,len-1) printf("%d ",ans[i]);
		return 0;
	}
	puts("Yes"); int p=1; //Case #2
	while (w>a[pos]) {
		while (p==pos||!a[p]) p++;
		w--; a[p]--; ans.push_back(p); ans.push_back(p);
	}
	ans.push_back(pos);
	rep(i,1,n) if (i!=pos) while (a[i]--) {
		ans.push_back(i); ans.push_back(i);
	}
	ans.push_back(pos); a[pos]--;
	while (a[pos]--) {
		ans.push_back(pos); ans.push_back(pos);
	} assert(getans(len)==exp);
	rep(i,0,len-1) printf("%d ",ans[i]);
	return 0;
}