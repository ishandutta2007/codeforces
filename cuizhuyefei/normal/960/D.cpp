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
const int N = 555;
int q,p;
ll Offset[N];
int getp(ll x) {rep(i,0,61) if (x<(1LL<<(i+1))) return i;}
ll dft(ll P) {
	ll v=P-Offset[p]; if (v>=(1LL<<(p+1))) v-=1LL<<p;
	if (v+(1LL<<p)<(1LL<<(p+1))) v+=1LL<<p;
	return v;
}
ll idft(ll P) {
	ll v=P+Offset[p]; if (v>=(1LL<<(p+1))) v-=1LL<<p;
	if (v+(1LL<<p)<(1LL<<(p+1))) v+=1LL<<p;
	return v;
}
int main() { //freopen("1.in","r",stdin);
	read(q); int mx=61;
	while (q--) {
		int op; read(op); ll x,k;
		if(op==1) {
			scanf("%lld%lld",&x,&k); int p=getp(x);
			(Offset[p]+=k)%=(1LL<<p);
		}
		else if (op==2) {
			scanf("%lld%lld",&x,&k); int p=getp(x);
			rep(i,p,mx) {
				(Offset[i]+=k)%=(1LL<<i); k*=2; k%=(1LL<<(i+1));
			}
		} else {
			scanf("%lld",&x); p=getp(x); ll pos=idft(x);
		//	rep(i,0,p) printf("%d : %lld\n",i,Offset[i]);
			for (;p>=0;p--) {
			//	printf("pos[%lld]=%lld \n",pos,dft(pos)); 
				printf("%lld ",dft(pos)); 
				pos>>=1;
			}
			puts("");
		}
	}
	return 0;
}