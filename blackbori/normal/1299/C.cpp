#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;
typedef long double ld;

vector <pll> S;
ll A[1010101];
ll n;

ll ccw(pll a, pll b, pll c)
{
	return (a.first * b.second + b.first * c.second + c.first * a.second)
		- (a.second * b.first + b.second * c.first + c.second * a.first);
}

int main()
{
	ll i, j, x, y;

	scanf("%lld", &n);

	S.emplace_back(0, 0);
	for(i = 1; i <= n; i ++){
		scanf("%lld", A + i); A[i] += A[i - 1];
		x = i; y = A[i];
		for(; S.size() > 1; S.pop_back()){
			if(ccw(S[S.size() - 2], S.back(), pll(x, y)) > 0) break;
		}
		S.emplace_back(x, y);
	}

	for(i = 1; i < S.size(); i ++){
		x = S[i].first - S[i - 1].first;
		y = S[i].second - S[i - 1].second;
		for(j = 0; j < x; j ++){
			printf("%.20Lf ", (ld)y / x);
		}
	}
	printf("\n");

	return 0;
}