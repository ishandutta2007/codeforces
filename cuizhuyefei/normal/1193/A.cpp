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
typedef unsigned long long ull;
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
const int N = 1<<18|3,mo=998244353;
int all,n,m,a[N][19],b[N][19],inv[N],cnt[N],f[19];bool gg[N];
inline void add(int &x,int y){x=x+y<mo?x+y:x+y-mo;}
int main() {
	read(n);read(m);all=(1<<n)-1;
	rep(i,1,all)cnt[i]=cnt[i>>1]+(i&1);
	inv[1]=1;rep(i,2,n)inv[i]=1LL*(mo-mo/i)*inv[mo%i]%mo;
	rep(i,1,m){
		int u,v;read(u);read(v);
		gg[(1<<u-1)|(1<<v-1)]=1;
	}
	rep(i,0,n-1)rep(j,0,all)if(j>>i&1)gg[j]|=gg[j^(1<<i)];
//	rep(i,1,all)if(!gg[i])cerr<<i<<' ';cerr<<endl;
	rep(i,0,all)if(!gg[i])a[i][cnt[i]]=1;
	rep(i,0,n-1)rep(j,0,all)if(j>>i&1)rep(k,0,n)add(a[j][k],a[j^(1<<i)][k]);
	rep(t,1,n){
		if(t==1){memcpy(b,a,sizeof(a));}
		else{//a*b-->b
			rep(i,0,all)per(j,n,0){
				ull x=0;rep(k,0,j)x+=1LL*a[i][k]*b[i][j-k];b[i][j]=x%mo;
			}
		}
		rep(i,0,all)f[t]=(f[t]+1LL*b[i][n]*(n-cnt[i]&1?mo-1:1))%mo;
	//	rep(i,1,t)f[t]=1LL*f[t]*inv[i]%mo;
	}
//	rep(t,0,n)cerr<<f[t]<<' ';cerr<<endl;
	int res=0;
	rep(i,0,n){
		int tmp=f[i];
		rep(j,0,n)if(j!=i)tmp=1LL*tmp*(mo-1-j)%mo*(i-j>0?inv[i-j]:mo-inv[j-i])%mo;
		res=(res+tmp)%mo;
	}
	res=1LL*res*m%mo*((mo+1)/2)%mo;if(n&1)res=(mo-res)%mo;
	cout<<res<<endl;
	return 0;
}