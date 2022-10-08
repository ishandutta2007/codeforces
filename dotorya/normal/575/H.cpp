//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <functional>
#define MOD 1000000007
#define MAX ((1<<30)-1)
#define MAX2 ((1ll<<62)-1)
#define mp make_pair
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll mul_inv(ll a, ll b)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
ll fac[2000050];
ll invfac[2000050];
ll po2[2000050];
ll n;
ll X[2000050];

int main()
{
	int i, j, k;
	fac[0]=1;
	po2[0] = 1;
	cin>>n;
	int N = n;
	for(i=1;i<=2*n;i++) fac[i]=fac[i-1]*i, fac[i]%=MOD;
	for(i=0;i<=2*n;i++) invfac[i]=mul_inv(fac[i], MOD);
	for(i = 1; i <= 2*N; i++) po2[i] = (po2[i-1] * 2)%MOD;
	for(i=n; i < 2*n; i++) X[i+1] = (2*X[i] + (fac[i] * invfac[n])%MOD * invfac[i-n])%MOD;

	ll ans = 0;
	for(i = 0; i <= 2*N; i++) ans += po2[i] - 2*X[i];
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
	printf("%lld", ans);
	return 0;
}
//*/