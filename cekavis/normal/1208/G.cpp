#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005;
int n, k, cnt, prime[N/10], phi[N];
bool p[N];
ll ans;
int main() {
	scanf("%d%d", &n, &k);
	if(k==1) return puts("3"), 0;
	for(int i=2; i<=n; ++i){
		if(!p[i]) prime[++cnt]=i, phi[i]=i-1;
		for(int j=1; j<=cnt && i*prime[j]<=n; ++j){
			p[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
	nth_element(phi+3, phi+k+2, phi+n+1);
	for(int i=3; i<=k+2; ++i) ans+=phi[i];
	printf("%lld\n", ans+2);
	return 0;
}