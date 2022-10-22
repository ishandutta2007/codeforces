#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

ll a;
int n;
int ss[61];
int xx[61];

int main () {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		ll sum = 0;
		ll xo = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%lld", &a);
			sum += a;
			xo ^= a;
		}
		xo *= 2;

		for(int i = 61; 0 <= i; --i) {
			xx[i] = ((xo >> i) & 1);
			ss[i] = ((sum >> i) & 1);
		}

		ll a = 0;
		ll b = 0;
		ll c = 0;
		for(int i = 0; i <= 61; ++i) {
			if(xx[i] >= 2) {
				xx[i + 1] += xx[i] / 2;
				xx[i] %= 2;
			}
			if(ss[i] >= 2) {
				ss[i + 1] += ss[i] / 2;
				ss[i] %= 2;
			}
			if(xx[i] == 1 && ss[i] == 0) {
				b ^= (1ll << (i - 1));
				c ^= (1ll << (i - 1));
			}
			if(xx[i] == 0 && ss[i] == 1) {
				a ^= (1ll << i);
				xx[i + 1] ^= 1;
				ss[i + 1] += 1;
			}
		}
		printf("3\n");
		printf("%lld %lld %lld\n", a, b, c);



	}


	return 0;
}