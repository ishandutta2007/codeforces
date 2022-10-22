#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

#define F first
#define S second

const ull INF = (ull)8e18 + 5;

ull k, d, t;

ull mul(ull a, ull b){
	if (INF/b > a)
		return a*b;
	return INF;
}

ull sm(ull a, ull b){
	if (INF-b > a)
		return a+b;
	return INF;
}

ull get(ull mid){
	ull pr = k + (k%d == 0ull? 0ull: d - k%d);
	ull x = mid/ pr;
	ull tot = mul(x, (k * 2 + (pr - k)));
	if (tot == INF) return tot;

	ull rem = mid % pr;
	tot = sm(tot, min(k, rem)*2ull);
	if (tot == INF) return tot;

	if (rem > k)
		tot = sm(tot, rem - k);
	return tot;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> d >> t, t *= 2, k *= 2, d *= 2;
	ull lo = 0, hi = (ull)4e18 + 3;
	ull temp = hi+hi>>1;
	while (hi - lo > 1){
		ull mid = hi+lo>>1;
		if (get(mid) >= t*2ull)
			hi = mid;
		else
			lo = mid;
	}
	cout << hi/2;
	if (hi & 1)
		cout << ".5";
	cout << "\n";
	return 0;
}