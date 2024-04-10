#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db long double
using namespace std;
const int N=1e6+6,P=998244353; int a[N],fac[N],inv[N];
int C(int n,int m){ return (ll)fac[n]*inv[m]%P*inv[n-m]%P; }
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; static char s[N]; scanf("%d%s",&n,s);
		fac[0]=1; rep(i,1,n) fac[i]=(ll)fac[i-1]*i%P;
		inv[1]=1; rep(i,2,n) inv[i]=(ll)inv[P%i]*(P-P/i)%P;
		inv[0]=1; rep(i,1,n) inv[i]=(ll)inv[i-1]*inv[i]%P;
		rep(i,1,n) a[i]=s[i-1]-'0'; a[n+1]=0;
		int p=0,v=0,c=0;
		rep(i,1,n+1) if (a[i]==0) ++c,v+=i-p-1>>1,p=i;
		printf("%d\n",C(v+c-1,c-1));
	}
	return 0;
}