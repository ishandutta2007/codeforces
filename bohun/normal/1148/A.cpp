#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
	
using namespace std;
	
int a, b, c;

int main() {
	scanf("%d %d %d", &a, &b, &c);
	ll res = c * 2;
	int d = min(a, b);
	res += d * 2;
	a -= d;
	b -= d;
	if(a)
		res += 1;
	if(b)
		res += 1;
	printf("%lld", res);
	
	return 0;
}