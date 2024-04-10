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
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 400000, mo=1e9+7;
int n,fac[N],ifac[N],C[N],hz_C[N];
ll a[N],qz[N],hz[N];
Vi s[N];
inline int CC(int n, int m) {
	return 1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo;
}
inline void exgcd(int a, int b, int &x, int &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline int inv(int a) {int x,y; exgcd(a,mo,x,y); return x>=0?x:x+mo;}
/*inline int getans(int a, int b) {
	int res=0;
	rep(i,0,a) rep(j,0,b) if (i>j) res+=C(a,i)*C(b,j);
	return res;
}*/
int main() { //freopen("1.in","r",stdin); 
	int x;
	read(n); rep(i,1,n) {
		read(x);
		for (int i=2; i*i<=x; i++) if (x%i==0) {
			int cnt=0; while (x%i==0) x/=i,cnt++;
			s[i].push_back(cnt);
		}
		if (x>1) s[x].push_back(1);
	}
	fac[0]=1;rep(i,1,n) fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=inv(fac[n]); per(i,n-1,0) ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	rep(i,0,n-1) C[i]=CC(n-2,i);
	per(i,n-1,0) hz_C[i]=(hz_C[i+1]+C[i])%mo;
//	rep(a,0,5) rep(b,0,5) printf("%d %d : %d\n",a,b,getans(a,b));
//	return 0;
	
	ll ans=0;
	rep(i,2,300000) if (s[i].size()>0) {
		sort(s[i].begin(),s[i].end());
		int p=n+1; per(j,(int)s[i].size()-1,0) a[--p]=s[i][j];
		qz[p-1]=0; rep(j,p,n) qz[j]=qz[j-1]+a[j];
		per(j,n,p) hz[j]=hz[j+1]+a[j];
		rep(j,p,n) {
			int A=j-1,B=n-j;
			ans+=(1LL*a[j]*A-qz[j-1])%mo*C[A]%mo+(hz[j+1]-1LL*a[j]*B)%mo*C[B]%mo;
			ans+=(1LL*a[j]*A-qz[j-1])%mo*C[A-1]%mo+(hz[j+1]-1LL*a[j]*B)%mo*C[B+1]%mo;
		}
		ans%=mo;
		ll sum=0; rep(j,p,n) sum+=a[j];
		ans+=sum*(hz_C[s[i].size()]+hz_C[s[i].size()+1])%mo;
	//	printf("%d : %lld\n",i,ans);
	}
	printf("%lld",(ans%mo+mo)%mo);
	return 0;
}