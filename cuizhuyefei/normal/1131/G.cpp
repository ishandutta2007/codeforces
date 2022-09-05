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
const int N = 10020000;
const ll inf=1e17;
int n,a[N],m,l[N],r[N];ll c[N],f[N];
void Read(){
	static Vi b[666666],d[666666];
	int cnt;read(cnt);int q;read(q);
	rep(i,1,cnt){
		int len,x;read(len);
		rep(j,1,len){read(x);b[i].pb(x);}
		rep(j,1,len){read(x);d[i].pb(x);}
	}
	read(q);
	while(q--){
		int id,x;read(id);read(x);
		rep(j,0,SZ(b[id])-1){
			++n;a[n]=b[id][j];c[n]=1LL*x*d[id][j];
		}
	}
	/*cerr<<n<<endl;
	rep(i,1,n)printf("%d ",a[i]);puts("");
	rep(i,1,n)printf("%lld ",c[i]);puts("");*/
}
//int q[N];int f,r;
//void init(){f=1;r=1;}
int main() {
	Read();
	for(m=1;m<=n+3;m<<=1);
	static int sta[N],top;
	
	top=0;per(i,n,1){
		while(top&&sta[top]+a[sta[top]]-1<=i+a[i]-1)top--;
		if(top&&sta[top]<=i+a[i]-1)r[i]=r[sta[top]];else r[i]=min(i+a[i]-1,n);
		sta[++top]=i;
	}
	top=0;rep(i,1,n){
		while(top&&sta[top]-a[sta[top]]+1>=i-a[i]+1)top--;
		if(top&&sta[top]>=i-a[i]+1)l[i]=l[sta[top]];else l[i]=max(i-a[i]+1,1);
		sta[++top]=i;
	}
	static ll val[N];top=0;rep(i,1,n+1)f[i]=inf;f[1]=0;
	rep(i,1,n+1){
		if(i-1)umin(f[i],val[top]+c[i-1]);
		if(i<=n)umin(f[r[i]+1],f[i]+c[i]);//[l[i]..i]
		ll now=f[i];while(top&&sta[top]>=l[i])umin(now,val[top]),top--;
		sta[++top]=l[i];val[top]=now;
	}
	cout<<f[n+1];
	return 0;
}