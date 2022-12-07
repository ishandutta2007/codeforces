#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
const int M = 1000000007;

const int N = 300000;
const int maxn = N +5;

int n;

int a[maxn];

int pri[maxn], tot, nop[maxn], mu[maxn];

int fac[maxn], inv[maxn];

int cnt[maxn], sum[maxn];

int res[maxn];

void moebius_table(){
	mu[1] = 1;
	ll ta;
	for(int i = 2; i <= N; i++){
		if(!nop[i]) pri[++tot] = i, mu[i] = -1;
		for(int j = 1; j <= tot && (ta = i * pri[j]) <= N; j++){
			nop[ta] = 1;
			if(i % pri[j]) mu[ta] = -mu[i]; else{
				mu[ta] = 0;
				break;
			}
		}
	}
}

inline int C(int n, int m){
	return n < m ? 0 : (ll)fac[n] * inv[m] % M * inv[n - m] % M;
}

bool check(int d){
	for(int i = N; i >= 1; --i){
		res[i] = C(sum[i], d);
		for(int j = i + i; j <= N; j += i){
			//res[i] += mu[j / i] * res[j];
			res[i] -= res[j];
			(res[i] >= M) && (res[i] -= M);
			(res[i] < 0) && (res[i] += M);
		}
	}
	return res[1];
}

int main(){
	moebius_table();
	scanf("%d", &n);
	int g = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i), g = __gcd(g, a[i]);
		if(a[i] == 1){
			puts("1");
			return 0;
		}
	}
	if(g != 1){
		puts("-1");
		return 0;
	}

	//for(int i = 1; i <= 300000; ++i) f[i] = n;
	//for(int i = 1; i <= n; ++i) f[a[i]] = 1;
	for(int i = 1; i <= n; ++i) ++cnt[a[i]];
	for(int i = 1; i <= N; ++i)
		for(int j = i; j <= N; j += i)
			sum[i] += cnt[j];

	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	for(int i = 2; i <= N; ++i){
		fac[i] = (ll)fac[i - 1] * i % M;
		inv[i] = (ll)(M - M / i) * inv[M % i] % M;
	}
	for(int i = 1; i <= N; ++i)
		inv[i] = (ll)inv[i] * inv[i - 1] % M;
	
	int l = 1, r = n;
	while(l + 1 < r){
		int d = (l + r) >> 1;
		if(check(d)) r = d;
		else l = d;
	}
	printf("%d\n", r);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}