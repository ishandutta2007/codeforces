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
const int N = 1<<17|3,mo=998244353,inv2=(mo+1)/2;
int n,m,x,y,z,a[N],b[N],ans[N],all,v1[N],v2[N],v3[N];
inline int power(int a, int n){
	int res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;
	}
	return res;
}
inline void fwt(int *a, int n, int tp){
	for(int j=2;j<=n;j<<=1){
		for(int k=0;k<n;k+=j)rep(i,0,(j>>1)-1){
			int x=a[k+i],y=a[k+i+(j>>1)];
			if(tp==1){
				a[k+i]=x+y<mo?x+y:x+y-mo;a[k+i+(j>>1)]=x-y>=0?x-y:x-y+mo;
			}
			else{
				a[k+i]=1LL*inv2*(x+y)%mo;
				a[k+i+(j>>1)]=1LL*inv2*(x-y+mo)%mo;
			}
		}
	}
}
int main() {
	read(n);read(m);read(x);read(y);read(z);int tot=0;all=(1<<m)-1;
	rep(i,1,n){
		int x,y,z;read(x);read(y);read(z);
		tot^=x;a[i]=y^x;b[i]=z^x;
	}
	rep(i,1,n){
		v1[a[i]]++;v2[b[i]]++;v3[a[i]^b[i]]++;
	}
	fwt(v1,1<<m,1);fwt(v2,1<<m,1);fwt(v3,1<<m,1);
	rep(i,0,all){
		int A=1LL*(v1[i]+n+mo)*inv2%mo,B=1LL*(v2[i]+n+mo)*inv2%mo,C=1LL*(v3[i]+n+mo)*inv2%mo;
		int a1=(A+B+C-n)/2,a2=A-a1,a3=B-a1,a4=C-a1;
		assert(a1+a2+a3+a4==n);
	//	printf("<%d %d %d %d>\n",a1,a2,a3,a4);
		ans[i]=1LL*power((1LL*x+y+z)%mo,a1)*power(x+y-z,a2)%mo*power(x-y+z,a3)%mo*power(x-y-z,a4)%mo;
		ans[i]=(ans[i]+mo)%mo;
	}
	fwt(ans,1<<m,-1);
	rep(i,0,all)printf("%d ",(ans[i^tot]%mo+mo)%mo);
	
	return 0;
}