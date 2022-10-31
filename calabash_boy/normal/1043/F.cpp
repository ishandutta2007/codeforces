#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <assert.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5+100;
const ll MOD = 998244353;
bool used[maxn];
vector<int> prime;
int mu[maxn];
int cnt[maxn];
ll fac[maxn];
void init(){
	mu[1] = 1;
	fac[0]= fac[1] = 1;
	for (int i=2;i<maxn;i++){
		fac[i] = fac[i-1] * i % MOD;
		if (!used[i]){
			prime.push_back(i);
			mu[i] = -1;
		}
		for (int j=0;j<prime.size();j++){
			long long nxt =1ll * i * prime[j];
			if (nxt >= maxn)break;
			used[nxt] = 1;
			if (i % prime[j]){
				mu[nxt] = -mu[i];
			}else{
				mu[nxt] = 0;
				break;
			}
		}
	}
}
long long quick_mod(ll x,ll y){
	ll res = 1;
	while (y){
		if(y&1){
			res = res * x % MOD;
		}
		y >>= 1;
		x = x * x % MOD;
	}
	return res;
}

int n;
int a[maxn];
inline ll C(int n,int m){
	if(n < m)return 0;
	//cerr<<n<<" "<<m<<" "<<" "<<fac[m]<<" "<<quick_mod(fac[m],MOD-2)<<endl;
	return 1ll * fac[n] * quick_mod(fac[m],MOD-2) % MOD* quick_mod(fac[n-m],MOD-2) % MOD;
}
long long work(int x){
	//cerr<<C(3,3)<<endl;
	ll ans = 0;
	for (int i=1;i<=300000;i++){
		(ans += 1ll * mu[i] * C(cnt[i],x))%= MOD;
		(ans += MOD) %= MOD;
	}
	return ans;
}
int main(){
	init();
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
		for (int j=1;1ll* j*j <=a[i];j++){
			if(a[i] %j == 0){
				cnt[j] ++;
				if(a[i]/j != j){
					cnt[a[i]/j] ++;
				}
			}
		}
	}
	int gcd = a[0];
	for (int i=1;i<n;i++){
		gcd = __gcd(gcd,a[i]);
	}
	if(gcd != 1){
		puts("-1");
		return 0;
	}
	for (int i=1;i<=7;i++){
		if(work(i)){
			printf("%d\n",i);
			return 0;
		}
	}
	assert(0);
	return 0;
}