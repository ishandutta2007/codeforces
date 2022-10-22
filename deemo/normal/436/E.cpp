//I know that diamonds, mean money for this art
//But that's not the shape of my heart..

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, k, a[MAXN], b[MAXN], sec[MAXN], mark[MAXN];
ll sm, p[MAXN];
multiset<pair<int, int>>	st;

bool cmp(int u, int v){return b[u] < b[v];}

int main(){
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i], &b[i]);

	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	for (int i = 0; i < n; i++)
		st.insert({a[sec[i]], i}), sm += a[sec[i]];

	for (int i = 0; i < n; i++)
		p[i + 1] = p[i] + a[sec[i]];

	ll ans = 2e18;
	for (int i = 0; i <= n && i <= k; i++){
		int req = k - i;
	
		while (st.size() > req){
			auto it = st.end();	it--;
			sm -= it->F;
			st.erase(it);
		}

		if (i + st.size() == k)
			ans = min(ans, p[i] + sm);

		if (i < n){
			if (st.count({a[sec[i]], i}))
				st.erase({a[sec[i]], i}), sm -= a[sec[i]];
			st.insert({b[sec[i]] - a[sec[i]], i});
			sm += b[sec[i]] - a[sec[i]];
		}
	}
	printf("%lld\n", ans);

	st.clear();	sm = 0;
	for (int i = 0; i < n; i++)
		st.insert({a[sec[i]], i}), sm += a[sec[i]];

	for (int i = 0; i <= n && i <= k; i++){
		int req = k - i;
	
		while (st.size() > req){
			auto it = st.end();	it--;
			sm -= it->F;
			st.erase(it);
		}

		if (i + st.size() == k && ans == p[i] + sm){
			for (int j = 0; j < i; j++)
				mark[sec[j]] = 1;
			for (auto v:st)
				mark[sec[v.S]]++;
			for (int j = 0; j < n; j++)
				printf("%d", mark[j]);
			printf("\n");
			return 0;
		}

		if (i < n){
			if (st.count({a[sec[i]], i}))
				st.erase({a[sec[i]], i}), sm -= a[sec[i]];
			st.insert({b[sec[i]] - a[sec[i]], i});
			sm += b[sec[i]] - a[sec[i]];
		}
	}
	return 0;
}