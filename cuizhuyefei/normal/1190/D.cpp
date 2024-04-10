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
const int N = 888888;
int v[N],n,mx;Pii s[N];ll res;bool vis[N];
void add(int p, int x){
	while(p<=mx)v[p]+=x,p+=p&-p;
}
int query(int p){if(p<0)return 0;int r=0;while(p)r+=v[p],p-=p&-p;return r;}
bool cmp(Pii a,Pii b){
	if(a.se!=b.se)return a.se>b.se;
	return a.fi<b.fi;
}
int main() {
	read(n);rep(i,1,n)read(s[i].fi),read(s[i].se);
	rep(i,1,n)v[i]=s[i].fi;sort(v+1,v+n+1);
	rep(i,1,n)s[i].fi=lower_bound(v+1,v+n+1,s[i].fi)-v;
	rep(i,1,n)v[i]=s[i].se;sort(v+1,v+n+1);
	rep(i,1,n)s[i].se=lower_bound(v+1,v+n+1,s[i].se)-v;
	sort(s+1,s+n+1,cmp);
	memset(v,0,sizeof(v));
	rep(i,1,n)umax(mx,max(s[i].fi,s[i].se));
//	rep(i,1,n)cerr<<s[i].fi<<' '<<s[i].se<<endl;
	rep(i,1,n){
		if(!vis[s[i].fi])vis[s[i].fi]=1,add(s[i].fi,1);
		int lim=i+1<=n&&s[i+1].se==s[i].se?s[i+1].fi-1:mx;
		res+=1LL*query(s[i].fi)*(query(lim)-query(s[i].fi-1));
	}
	cout<<res;
	return 0;
}