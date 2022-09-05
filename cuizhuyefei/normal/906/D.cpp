#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
int n,mo,a[102000];
int PHI[100];
inline int mod(ll a, int mo) {return a<mo ? a : a%mo+mo;}
inline int power(int a, int n, int mo) {
	int res=1;
	while (n) {
		if (n&1) res=mod(1LL*res*a,mo);
		a=mod(1LL*a*a,mo);
		n>>=1;
	}
	return res;
}
inline int phi(int n) {
	int mx=sqrt(n),ans=n;
	rep(i,2,mx) if (n%i==0) {
		ans=ans/i*(i-1); while (n%i==0) n/=i;
	} if (n>1) ans=ans/n*(n-1); return ans;
}
inline int getans(int l, int r, int mo, int t) {
	if (mo<=1) return 1; //
	if (l==r) return mod(a[l],mo);
	int Phi=PHI[t],tmp=getans(l+1,r,Phi,t+1); //PHI[t]=phi(mo)
	return power(a[l],tmp,mo);
}
int main() {
	read(n); read(mo); PHI[0]=mo; rep(i,1,100) {PHI[i]=phi(PHI[i-1]); if (PHI[i]<=1) break;}
	rep(i,1,n) read(a[i]);
	int q; read(q);
	while (q--) {
		int l,r; read(l); read(r);
		printf("%d\n",getans(l,r,mo,1)%mo);
	}
	return 0;
}