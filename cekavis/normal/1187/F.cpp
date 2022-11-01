#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005, P = 1000000007;
int n, l[N], r[N], sf[N], sg[N], sh[N];
inline int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", l+i);
	for(int i=1; i<=n; ++i) scanf("%d", r+i);
	sh[0]=1;
	sh[1]=sg[1]=sf[1]=r[1]-l[1]+1;
	for(int i=2; i<=n; ++i){
		int len=r[i]-l[i]+1;
		sh[i]=(ll)sh[i-1]*len%P;
		int len2=max(min(r[i], r[i-1])-max(l[i], l[i-1])+1, 0);
		sg[i]=((ll)(sg[i-1]+sh[i-1])*len-(ll)sh[i-2]*len2)%P;
		int len3=max(min(min(r[i], r[i-1]), r[i-2])-max(max(l[i], l[i-1]), l[i-2])+1, 0);
		sf[i]=((sf[i-1]+2ll*sg[i-1]+sh[i-1])*len-(2ll*sg[i-2]+3ll*sh[i-2])*len2+(i>2?2ll*sh[i-3]:0)*len3)%P;
	}
	printf("%lld\n", (ll)(sf[n]+P)*Pow(sh[n])%P);
	return 0;
}