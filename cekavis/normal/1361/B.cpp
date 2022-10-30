#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005, P = 1000000007;
int T, n, p, a[N];
int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &p);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		if(p==1){
			printf("%d\n", n&1);
			continue;
		}
		sort(a+1, a+n+1);
		int ans=0, x=1e6, y=0;
		for(int i=n; i; --i){
			while(y && x>a[i] && y<1e9) y=min((ll)1e9, (ll)y*p), --x;
			x=a[i];
			if(!y) ++y, (ans+=Pow(p, x))%=P;
			else --y, (ans+=P-Pow(p, x))%=P;
		}
		printf("%d\n", ans);
	}
	return 0;
}