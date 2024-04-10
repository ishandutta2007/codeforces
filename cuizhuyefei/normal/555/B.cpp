#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> Pii;
typedef vector<int> Vi;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 600005;
ll n,m,A[N],B[N],len,ans[N];
struct seg {ll l,r,index;} s[N];
bool cmp(seg a, seg b) {return a.r!=b.r?a.r<b.r:a.l<b.l;}
set<Pii> Set;
void Bye() {puts("No"); exit(0);}
int main() {
	read(n); read(m);
	rep(i,1,n) read(A[i]),read(B[i]); ll x;
	rep(i,1,m) read(x),Set.insert(Pii(x,i));
	rep(i,1,n-1) s[++len]=(seg){A[i+1]-B[i],B[i+1]-A[i],i};
	sort(s+1,s+len+1,cmp);
	rep(i,1,len) {
		if (Set.empty()) Bye();
		set<Pii> ::iterator it=Set.lower_bound(Pii(s[i].l,0));
		if (it==Set.end()||(*it).fi>s[i].r) Bye();
		ans[s[i].index]=(*it).se; Set.erase(it);
	}
	puts("Yes"); rep(i,1,len) printf("%lld ",ans[i]);
	return 0;
}