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

struct pt {
	int x, y;
	pt operator - (pt a) {
		pt c;
		c.x = x - a.x;
		c.y = y - a.y;
		return c;
	}
};

ll wek(pt a, pt b) {
	return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

int half(pt a) {
	return (0 <= a.y);
}

bool cmp(pt a, pt b) {
	if(half(a) != half(b))
		return half(a) < half(b);
	return wek(a, b) < 0;
}
	

int n;
			
int main() {
	scanf("%d", &n);
	vector <pt> v(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &v[i].x, &v[i].y);
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		vector <pt> ind;
		for(int j = 0; j < n; ++j)
			if(i != j) ind.pb(v[j] - v[i]);
		sort(ind.begin(), ind.end(), cmp);
		int wsk = 0;
		int m = n - 1;
		for(int j = 0; j < m; ++j) {
			if(wsk == (j - 1 + m) % m)
				wsk = j;
			//printf("p = %d %d\n", ind[j].x, ind[j].y);
			while((wsk + 1) % m != j && wek(ind[j], ind[(wsk + 1) % m]) < 0)
				wsk = (wsk + 1) % m;
			int ile = (j <= wsk ? wsk - j : m - j + wsk);
			ans += 1ll * ile * (ile - 1) / 2;
			ile = m - ile - 1;
			ans += 1ll * ile * (ile - 1) / 2;
		}	
	}
	ans /= 2;
	ans = 1ll * n * (n - 1) * (n - 2) * (n - 3) / 6 - ans;
	ans *= (n - 4);
	ans /= 2;
	printf("%lld", ans);

	return 0;
}