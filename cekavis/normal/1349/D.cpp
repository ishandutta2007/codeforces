#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005, M = 300005, P = 998244353;
int n, s, ans, a[N], f[M];
int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), s+=a[i];
	f[0]=n-1;
	for(int i=1; i<s; ++i){
		int x=(s-i+P-(ll)(s-i)*(n-2)%P*Pow(n-1)%P)%P;
		f[i]=((ll)i*f[i-1]+s)%P*Pow(x)%P;
	}
	// for(int i=0; i<=s; ++i) printf("%d: %d\n", i, f[i]);
	for(int i=s; i--;) (f[i]+=f[i+1])%=P;
	for(int i=1; i<=n; ++i) (ans+=f[a[i]])%=P;
	printf("%lld\n", (ans+(P-f[0])*(n-1ll))%P*Pow(n)%P);
	return 0;
}