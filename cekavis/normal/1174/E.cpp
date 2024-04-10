#include<cstdio>

using namespace std;
#define ll long long

const int N = 1000005, P = 1000000007;
int n, t, ans, fac[N], ifac[N];
inline int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
int main() {
	scanf("%d", &n);
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=(ll)fac[i-1]*i%P;
	ifac[n]=Pow(fac[n]);
	for(int i=n; i; --i) ifac[i-1]=(ll)ifac[i]*i%P;

	for(t=1; 2<<t<=n; ++t);
	ans=1;
	for(int now=n, i=t; ~i; --i){
		int x=((n>>i)+1)/2;
		ans=(ll)ans*fac[now-1]%P*x%P*ifac[now-x]%P;
		now-=x;
	}
	if(n>=3<<(t-1)){
		for(int k=0; k<t; ++k){
			int ans2=1, now=n;
			for(int i=t-1; i>=k; --i){
				int x=((n/3>>i)+1)/2;
				ans2=(ll)ans2*fac[now-1]%P*x%P*ifac[now-x]%P;
				now-=x;
			}
			for(int i=k; ~i; --i){
				int x=n>>i;
				if(i==k) x=x/3*2+(x%3>=1)+(x%3>=2); else x=(x+1)/2;
				ans2=(ll)ans2*fac[now-1]%P*x%P*ifac[now-x]%P;
				now-=x;
			}
			(ans+=ans2)%=P;
		}
	}
	printf("%d", ans);
	return 0;
}