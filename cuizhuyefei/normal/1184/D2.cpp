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
const int N = 275,mo=1e9+7;const ll MOD=1LL*mo*mo;
int n,k,m,inv[N],cnt,sz;
struct node{
	int a[N];//a[0]+\sum a[i]*x[i]
	void init(){memset(a,0,sizeof(a));}
}a[N][N],qz1[N][N],qz2[N][N];
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
inline bool operator ==(node a,const node &b){
	rep(i,0,cnt)if(a.a[i]!=b.a[i])return 0;return 1;
}
inline node operator +(node a,const node &b){
	rep(i,0,cnt)add(a.a[i],b.a[i]);return a;
}
inline node operator -(node a,const node &b){
	rep(i,0,cnt)sub(a.a[i],b.a[i]);return a;
}
inline node operator *(node a,int k){
	rep(i,0,cnt)a.a[i]=1LL*a.a[i]*k%mo;return a;
}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
int b[N][N];
inline void gauss(int n){//b[1..n][1..n+1]
	/*rep(i,1,n){
		rep(j,1,n+1)printf("%d ",b[i][j]);puts("");
	}*/
	rep(i,1,n){
		if(!b[i][i])rep(j,i+1,n)if(b[j][i]){
			rep(k,1,n+1)swap(b[i][k],b[j][k]);
			break;
		}
		assert(b[i][i]);
		int ni=power(b[i][i],mo-2);
		rep(j,1,n+1)b[i][j]=1LL*b[i][j]*ni%mo;
		rep(j,1,n)if(b[j][i]&&j!=i){
			int xs=b[j][i];
			rep(k,i,n+1)b[j][k]=(b[j][k]-1LL*b[i][k]*xs+MOD)%mo;
		}
	}
}
bool vis[N][N];
inline void upd(int i, int j){
	if(vis[i][j])return;vis[i][j]=1;
//	printf("upd %d %d\n",i,j);
	if(i-1>=1&&i-1>=j)assert(vis[i-1][j]);
	if(i-1>=1&&j-1>=1&&i-1>=j-1)assert(vis[i-1][j-1]);
	/*if(j==2){
		rep(k,0,cnt)cerr<<qz1[i][j].a[k]<<' ';cerr<<endl;
	}*/
	qz1[i][j]=qz1[i-1][j]+a[i][j];qz2[i][j]=qz2[i-1][j-1]+a[i][j];
}
int solve(int n, int k){
	int res=a[n][k].a[0];rep(i,1,cnt)res=(res+1LL*a[n][k].a[i]*b[i][cnt+1])%mo;
	return res;
}
int solve(node a){
	int res=a.a[0];rep(i,1,cnt)res=(res+1LL*a.a[i]*b[i][cnt+1])%mo;
	return res;
}
/*void ck(int i, int j){
	int tmp=0;
	tmp=1LL*(m-i)*inv[m]%mo*((1LL*j*inv[i+1]%mo*solve(i+1,j+1)%mo+1LL*(i+1-j)*inv[i+1]%mo*solve(i+1,j))%mo)%mo;
	int xs=1LL*i*inv[m]%mo*inv[i-1]%mo;
	rep(k,j,i-1)tmp=(tmp+1LL*xs*solve(k,j))%mo;
	rep(k,1,j-1)tmp=(tmp+1LL*xs*solve(i-k,j-k))%mo;
//	cerr<<i<<' '<<j<<' '<<tmp<<endl;
	assert(tmp==solve(i,j));
}*/
int main() {
	inv[1]=1;rep(i,2,N-1)inv[i]=1LL*(mo-mo/i)*inv[mo%i]%mo;
	read(n);read(k);read(m);
	cnt=m-2;
	if(m<=2){printf("%d\n",n);return 0;}
	rep(i,1,m)a[i][1].a[0]=a[i][i].a[0]=i,upd(i,1),upd(i,i);
	rep(j,3,m)a[j][2].a[j-2]=1,upd(j,2);//cnt=m-2
	rep(j,2,m-1)rep(i,j+1,m){
		node tmp=a[i][j];
		if(i+1<=m)tmp=tmp-a[i+1][j]*(1LL*(m-i)*inv[m]%mo*(i+1-j)%mo*inv[i+1]%mo);
		int xs=1LL*i*inv[m]%mo*inv[i-1]%mo;
		
	//	upd();
		/*node qaq;qaq.init();
		rep(k,j,i-1)qaq=(qaq+a[k][j]);
		if(!(qaq==qz1[i-1][j])){
			cerr<<i<<' '<<j<<endl;
			rep(k,0,cnt)cerr<<qaq.a[k]<<' ';cerr<<endl;
			rep(k,0,cnt)cerr<<qz1[i-1][j].a[k]<<' ';cerr<<endl;
		}assert(qaq==qz1[i-1][j]);
		rep(k,1,j-1)qaq=(qaq+a[i-k][j-k]);
		tmp=tmp-qaq*xs;*/
		tmp=tmp-(qz1[i-1][j]+qz2[i-1][j-1])*xs;
		if(i+1<=m){
			tmp=tmp*power(1LL*(m-i)*inv[m]%mo*j%mo*inv[i+1]%mo,mo-2);
			a[i+1][j+1]=tmp;upd(i+1,j+1);
		}
		else{
			sz++;b[sz][cnt+1]=mo-tmp.a[0];
			rep(k,1,cnt)b[sz][k]=tmp.a[k];
		}
	}
//	cerr<<sz<<' '<<cnt<<endl;
	assert(sz==cnt);
	gauss(sz);
	printf("%d\n",solve(n,k));
//	rep(i,1,m){rep(j,1,i)printf("%d ",solve(i,j));puts("");}
//	rep(j,2,m-1)rep(i,j+1,m)ck(i,j);
	return 0;
}