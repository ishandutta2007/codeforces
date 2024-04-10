#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 1e9+7;
const int N = 5e6+5;
ll sv[N]={};
ll f[N];

int main() {
	for(int i = 1; i < N; ++i)
		sv[i] =i;
	for(int i = 2; i < N; ++i) {
		if(sv[i] == i) {
			for(ll j = ll(i)*i; j < N; j += i)
				sv[j] = min(ll(i),sv[j]);
		}
	}
	f[1] = 0;
	for(ll i = 2; i < N; ++i) {
		f[i] = ((sv[i]*(sv[i]-1)/2)%M*(i/sv[i])+ f[i/sv[i]])%M;
	}
	ll ans = 0;
	ll p = 1;
	int t,l,r;
	scanf("%d%d%d",&t,&l,&r);
	for(int i = l; i <= r; ++i) {
		ans = (ans+p*f[i])%M;
		p = (p*t)%M;
	}
	printf("%d\n",int(ans));
}