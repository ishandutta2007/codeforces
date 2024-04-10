#pragma GCC optimize("O3")
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

const int nax = 2e5 + 111;
const int pier = 450;

int n, t;
int a[nax];
int l, r;

struct eve {
	int l, r, id;
};

vector <eve> v;

int ile[1000001];
ll sum;
ll ans[nax];

void add(int x, int c) {
	x = a[x];
	sum -= (ll) ile[x] * ile[x] * x;
	ile[x] += c;
	sum += (ll) ile[x] * ile[x] * x;
}

int main() {
	scanf("%d %d", &n, &t);
	FOR(i, 1, n)
		scanf("%d", &a[i]);
	FOR(i, 1, t) {
		scanf("%d %d", &l, &r);
		eve x = {l, r, i};
		v.pb(x);
	}
	sort(v.begin(), v.end(), [](eve a, eve b) {
		if(a.l / pier != b.l / pier)
			return a.l / pier < b.l / pier;
		return a.r < b.r;
	});
	
	int L = 1;
	int R = 0;
	
	for(auto it : v) {
		int left = it.l;
		int right = it.r;
		int id = it.id;
		while(R < right)
			add(++R, 1);
		while(left < L)
			add(--L, 1);
		while(right < R)
			add(R--, -1);
		while(L < left)
			add(L++, -1);
		ans[id] = sum;
	}
	FOR(i, 1, t)
		printf("%lld\n", ans[i]);
	
	
	return 0;
}