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
const int N = 133333;
int n,a[N];vector<Vi>ans;
inline int calc(int n){
	int k=sqrt(n*2)-1;while((k+1)*(k+2)<=n*2)k++;return k;
}
int v[N],f[N],lim;
int query(int p){int r=0;while(p)umax(r,v[p]),p-=p&-p;return r;}
void add(int p, int x){while(p<=lim)umax(v[p],x),p+=p&-p;}
int main() {
	int t;read(t);
	while(t--){
		read(n);rep(i,1,n)read(a[i]);ans.clear();lim=n;
		while(n){
			rep(i,0,lim)v[i]=0;
			int mx=0;rep(i,1,n)f[i]=query(a[i])+1,add(a[i],f[i]),umax(mx,f[i]);
			if(mx<=calc(n)){
				map<int,int>Map;
				rep(i,1,n){
					map<int,int>::iterator it=Map.lower_bound(a[i]);
					if(it==Map.end()){ans.pb({a[i]});Map[a[i]]=SZ(ans)-1;}
					else {int p=(*it).se;assert(ans[p].back()>a[i]);ans[p].pb(a[i]);Map.erase(it);Map[a[i]]=p;}
				}
				//rep(i,1,n)printf("%d ",a[i]);puts("");
				//printf("%d %d %d\n",mx,calc(n),SZ(Map));
				assert(SZ(Map)==mx);
				break;
			}
			static bool mrk[N];rep(i,1,n)mrk[i]=0;
			int up=lim+1,nd=mx;per(i,n,1)if(f[i]==nd&&a[i]<up)mrk[i]=1,nd--,up=a[i];
			Vi now;rep(i,1,n)if(mrk[i])now.pb(a[i]);ans.pb(now);
			int len=0;rep(i,1,n)if(!mrk[i])a[++len]=a[i];n=len;//printf("n=%d %d\n",n,mx);
		}
		
		printf("%d\n",SZ(ans));
		rep(i,0,SZ(ans)-1){printf("%d ",SZ(ans[i]));rep(j,0,SZ(ans[i])-1)printf("%d ",ans[i][j]);puts("");}
	}
	//rep(i,1,n)rep(lis,1,i)umax(f[i],min(lis,f[i-lis]+1));
	//rep(i,1,n)assert(f[i]==solve(i));
	return 0;
}