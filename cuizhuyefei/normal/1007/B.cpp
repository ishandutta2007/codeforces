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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
int n,A,B,c,cnt[N],f[8];
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
ll C(int n, int m){
	if(m==1)return n;
	if(m==2)return 1LL*n*(n-1)>>1;
	if(m==3)return 1LL*n*(n-1)*(n-2)/6;
	return 1;
}
int main() {
	int T;read(T);int mx=100000;
	rep(i,1,mx)for(int j=i;j<=mx;j+=i)cnt[j]++;
	while(T--){
		read(A);read(B);read(c);
		per(i,7,1){
			int x=0;if(i&1)x=gcd(x,A);if(i&2)x=gcd(x,B);if(i&4)x=gcd(x,c);
			f[i]=cnt[x];rep(j,i+1,7)if((j&i)==i)f[i]-=f[j];
		}
		ll res=0;
		rep(i,1,7)rep(j,i,7)rep(k,j,7){
			bool ok=0;
			ok|=(i&1)&&(j&2)&&(k&4);
			ok|=(i&1)&&(j&4)&&(k&2);
			ok|=(i&2)&&(j&1)&&(k&4);
			ok|=(i&2)&&(j&4)&&(k&1);
			ok|=(i&4)&&(j&1)&&(k&2);
			ok|=(i&4)&&(j&2)&&(k&1);
			if(!ok)continue;
			int a[4]={0,i,j,k};ll now=1;
			rep(l,1,3){
				int r;for(r=l;r<=3;r++)if(a[r]!=a[l])break;
				//[l,r-1]
				now*=C(r-l+f[a[l]]-1,r-l);l=r-1;
			}
			res+=now;
		}
		printf("%lld\n",res);
	}
	return 0;
}