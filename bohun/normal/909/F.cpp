#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
	
		
using namespace std;

int daj(int n) {
	int res = 1;
	while(res <= n)
		res *= 2;
	res /= 2;
	return res;
}

int ans[100111];

void solve1(int n) {
	if(n & 1) {
		printf("NO\n");
		return;
	}
	int N = n;
	while(n > 0) {
		int pot = daj(n);
		for(int i = 0; i <= n - pot; ++i) {
			ans[pot - 1 - i] = pot + i;
			ans[pot + i] = pot - 1 - i;
		}
		n = 2 * pot - n - 2;
	}
	printf("YES\n");
	FOR(i, 1, N) {
		assert((ans[i] & i) == 0);
		printf("%d ", ans[i]);
	}
	printf("\n");
}


void solve2(int n) {
	if(daj(n) == n) {
		printf("NO\n");
		return;
	}
	vector <int> v;
	for(int i = 1; i <= min(n, 7); ++i)
		v.pb(i);
	bool ok = 0;
	do {
		ok = 1;
		for(int i = 0; i < min(n, 7); ++i) {
			if((v[i] & (i + 1)) == 0 || i + 1 == v[i])
				ok = 0;
		}
		if(ok)
			break;
		
	} while(next_permutation(v.begin(), v.end()));
	if(ok && n <= 7) {
		printf("YES\n");
		for(auto it : v)
			printf("%d ", it);
		return;
	}
	if(n <= 7) {
		printf("NO\n");
		return;
	}
	for(int i = 1; i <= 7; ++i) {
		ans[i] = v[i - 1];
	}
	int K = 8;
	while(K <= n) {
		if(daj(K + 1) == K + 1) {
			ans[K] = daj(K + 1) / 2;
			K++;
			continue;
		}
		if(K == n) {
			ans[K] = daj(K);
			K++;
			continue;
		}
		ans[K] = K + 1;
		K += 1;
	}
	printf("YES\n");
	FOR(i, 1, n) {
		assert((ans[i] & i) > 0);
		printf("%d ", ans[i]);
	}
	printf("\n");
}
			
		
	

int main() {	
	int n;
	scanf("%d", &n);
	solve1(n);
	solve2(n);
	return 0;
}