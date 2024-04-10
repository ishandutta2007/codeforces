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

const int nax = 1e5 + 111;
const int P = 400;

int n, k, m;
int pref[nax], a[nax];
int b, c;

struct query {
	int l, r, id;
};

vector <query> v;

int ile[2000005];
ll ans[nax];
ll res = 0;

void add(int e) {
	e = pref[e];
	res += ile[(k ^ e)];
	ile[e] += 1;
}

void del(int e) {
	e = pref[e];
	res -= ile[(k ^ e)];
	if((k ^ e) == e)
		res += 1;
	ile[e] -= 1;
}

int main() {	
	scanf("%d %d %d", &n, &m, &k);
	FOR(i, 1, n) {
		scanf("%d", &a[i + 1]);
		pref[i + 1] = (pref[i] ^ a[i + 1]);
	}
	FOR(i, 1, m) {
		scanf("%d%d", &b, &c);
		query x = {b, c + 1, i};
		v.pb(x);
	}
	sort(v.begin(), v.end(), [](query a, query b) {
		if(a.l / P != b.l / P)
			return a.l / P < b.l / P;
		return a.r < b.r;
	});
	
	int R = 0;
	int L = 1;
	
	for(auto it : v) {
		int left = it.l;
		int right = it.r;
		while(R < right)
			add(++R);
		while(left < L)
			add(--L);
		while(right < R)
			del(R--);
		while(L < left)
			del(L++);
		ans[it.id] = res;
	}
	
	FOR(i, 1, m)
		printf("%lld\n", ans[i]);
	
	
		
	
		
	
	return 0;
}