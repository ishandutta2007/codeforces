#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
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
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 2000020, mo = 1e9+7;
vector<int> ys[N];
int n,m,miu[N];
ll ans[N];
int mi[N];
int prime[N],mrk[N],len;
inline void getans(int n) {
	rep(i,2,n) {
		if (!mrk[i]) prime[++len]=i;
		rep(j,1,len) {
			int v=prime[j]*i;
			if (v>n) break; mrk[v]=prime[j];
			if (i%prime[j]==0) break;
		}
	}
	rep(i,1,n) {
		if (!mrk[i]) {miu[i]=-1; continue;}
		int v=mrk[i],lst=i/v;
		if (lst%v==0) miu[i]=0; else miu[i]=-miu[lst];
	} miu[1]=1;
//	rep(i,1,n) for (register int j=i; j<=n; j+=i) ys[j].push_back(i);
	rep(d,1,n) for (register int k=d; k<=n; k+=d) ans[k]+=1LL*miu[d]*(mi[k/d]-mi[k/d-1]+mo)%mo;
	/*memset(ans,0,sizeof(ans)); ans[n]=1;
	per(i,n-1,1){for (int j=i+i;j<=n;j+=i)ans[i]-=ans[j];}
	return ans[1];*/
}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo;
		n>>=1;
	}
	return res;
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(m);
	rep(i,1,m) mi[i]=power(i,n);
	getans(max(n,m));
	ans[1]=1; rep(k,2,m) {
		ans[k]+=ans[k-1]; ans[k]%=mo; if (ans[k]<0) ans[k]+=mo;
		/*int len=ys[k].size(); ans[k]=ans[k-1];
		rep(i,0,len-1) {int d=ys[k][i]; ans[k]+=1LL*miu[d]*(mi[k/d]-mi[k/d-1]+mo)%mo;}
		ans[k]%=mo; if (ans[k]<0) ans[k]+=mo; //printf("%d : %lld\n",k,ans[k]);*/
	}
	ll res=0;
	rep(i,1,m) res+=ans[i]^i;
	printf("%lld",res%mo);
	return 0;
}