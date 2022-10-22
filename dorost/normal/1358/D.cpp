/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], ps[N * 2], ps2[N * 2];

int32_t main(){
	int n, k;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n * 2; i++){
		ps[i] = ps[(i - 1)] + a[(i) % n];
		ps2[i] = ps2[(i - 1)] + (a[(i) % n] * (a[(i) % n] + 1)) / 2;
	}
	int mx = 0;
	for (int i = 0; i < n; i++){
		int I = lower_bound(ps, ps + n * 2 + 1, ps[i] + k) - ps;
		int an = ps2[I] - ps2[i];
		int bag = ps[I] - (ps[i] + k);
		an -= (bag * (bag + 1)) / 2;
		mx = max(mx, an);
	}
	printf("%lld", mx);
}