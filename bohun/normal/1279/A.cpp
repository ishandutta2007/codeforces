#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		ll d = a + b + c;
		if((d + 1) / 2 >= max({a, b, c}))
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}