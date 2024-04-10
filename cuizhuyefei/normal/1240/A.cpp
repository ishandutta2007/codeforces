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
const int N = 266666;
int n,p[N],val[N],id[N];ll Need;
bool cmp(int x, int y){return val[x]>val[y];}
bool ck(int cnt){
	ll res=0;int cur=0;
	rep(i,1,n)if(id[i]<=cnt)res+=1LL*val[id[i]]*p[++cur];
//	rep(i,1,cnt)cerr<<p[i]<<' ';cerr<<endl;
//	rep(i,1,cnt)cerr<<val[i]<<' ';cerr<<endl;
//	cerr<<res<<endl;
	assert(cur==cnt);
	return res>=Need;
}
int main() {
	int T;read(T);while(T--){
		read(n);rep(i,1,n)read(p[i]),p[i]/=100;
		rep(i,0,n)val[i]=0;
		int x,a;read(x);read(a);for(int i=a;i<=n;i+=a)val[i]+=x;
		read(x);read(a);for(int i=a;i<=n;i+=a)val[i]+=x;
		read(Need);
		sort(p+1,p+n+1);reverse(p+1,p+n+1);
		rep(i,1,n)id[i]=i;sort(id+1,id+n+1,cmp);
		if(!ck(n))puts("-1");else{
			int l=0,r=n,res=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(ck(mid))res=mid,r=mid-1;else l=mid+1;
			}
			printf("%d\n",res);
		}
	}
	return 0;
}