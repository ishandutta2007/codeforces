#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 20;
const int LOG = 30 + 1;

int n, q, que[MAXN], ans[MAXN], weed[4 * MAXN];
pair<int, int>	vec[MAXN];

void water(int v, int b, int e, int l, int r, int val){
	if (l <= b && e <= r){
		weed[v] |= val;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	water(v<<1, b, mid, l, r, val);
	water(v<<1^1, mid, e, l, r, val);
}

void plant(int v, int b, int e, int val = 0){
	val |= weed[v];
	if (e - b == 1){
		weed[v] = val;
		ans[b] = val;
		return;
	}

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid, val);
	plant(v<<1^1, mid, e, val);
	weed[v] = weed[v<<1] & weed[v<<1^1];
}

int smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	weed[v];
	if (r <= b || e <= l)	return	(1 << 30) - 1;

	int mid = (b + e)/ 2;
	return	smoke(v<<1, b, mid, l, r) & smoke(v<<1^1, mid, e, l, r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < q; i++){
		cin >> vec[i].first >> vec[i].second >> que[i];
		vec[i].first--;
		water(1, 0, n, vec[i].first, vec[i].second, que[i]);
	}
	plant(1, 0, n);

	for (int i = 0; i < q; i++)
		if (smoke(1, 0, n, vec[i].first, vec[i].second) != que[i]){
			cout << "NO\n";
			return	0;
		}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return	0;
}