#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 2017, maxm = 200100;
int h, w, n;
int p[maxn], r[maxn], c[maxn];
int inv[maxm], sinv[maxm], fac[maxm];
int f[maxn], g[maxn];

inline int calc(int n, int m){
	return (ll)fac[n + m] * sinv[n] % M * sinv[m] % M;
}

int main(){
	scanf("%d%d%d", &h, &w, &n);
	fac[0] = inv[0] = sinv[0] = fac[1] = inv[1] = sinv[1] = 1;
	for(int i = 2; i <= 200000; ++i){
		fac[i] = (ll)fac[i - 1] * i % M;
		inv[i] = (ll)(M - M / i) * inv[M % i] % M;
		sinv[i] = (ll)sinv[i - 1] * inv[i] % M;
	}
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", r + i, c + i);
		p[i] = i;
	}
	r[0] = 1, c[0] = 1;
	r[n + 1] = h, c[n + 1] = w;
	p[n + 1] = n + 1;
	sort(p + 1, p + n + 1, [](int i, int j) { return r[i] < r[j] || (r[i] == r[j] && c[i] < c[j]); });
	f[0] = 1;
	for(int i = 1; i <= n + 1; ++i)
		for(int j = 0; j < i; ++j)
			if(r[p[j]] <= r[p[i]] && c[p[j]] <= c[p[i]]){
				int tmp = calc(r[p[i]] - r[p[j]], c[p[i]] - c[p[j]]);
				g[i] = (g[i] + (ll)f[j] * tmp) % M;
				f[i] = (f[i] + (ll)g[j] * tmp) % M;
			}
	printf("%d\n", (g[n + 1] - f[n + 1] + M) % M);

#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}