#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
  
using namespace std;
const int nax = 2e5 + 11;

ll sum[nax];
int n, m;
int x[nax];

void add(int l, int r, int c) {
	if(l <= r) {
		sum[l] += c;
		sum[r + 1] -= c;
	}
} 

int main() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, m) {
		scanf("%d", &x[i]);
	}
	FOR(i, 1, m - 1) {
		int a = x[i];
		int b = x[i + 1];
		if(a > b)
			swap(a, b);
		if(a == b)
			continue;
		add(1, a - 1, b - a);
		add(a, a, b - 1);
		add(a + 1, b - 1, b - a - 1);
		add(b, b, a);
		add(b + 1, n, b - a);
	}
	FOR(i, 1, n) {
		sum[i] += sum[i - 1];
		printf("%lld ", sum[i]);
	}
		
	
	return 0;
}