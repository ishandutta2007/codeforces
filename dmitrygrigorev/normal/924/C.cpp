#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e5;
int arr[MAXN], tree[MAXN * 4], ans[MAXN];



void build (int v, int l, int r) {
	if (l == r) {
		tree[v] = l;
	} else {
		int m = (l + r) / 2;
		build(v * 2, l, m);
		build(v * 2 + 1, m + 1, r);
		int s1 = tree[v * 2];
		int s2 = tree[v * 2 + 1];
		if (arr[s1] >= arr[s2]) {
			tree[v] = s1;
		} else {
			tree[v] = s2;
		}
	}
}

int get (int v, int cl, int cr, int l, int r) {
	if (cl == l && cr == r) {
		return tree[v];
	} 
	int cm = (cl + cr) / 2;
	if (r <= cm) {
		return get(v * 2, cl, cm, l, r);
	}
	if (l > cm) {
		return get(v * 2 + 1, cm + 1, cr, l, r);
	}
	int s1 = get(v * 2, cl, cm, l, cm);
	int s2 = get(v * 2 + 1, cm + 1, cr, cm + 1, r);
	if (arr[s1] >= arr[s2]) {
		return s1;
	} else {
		return s2;
	}
}

int n;

signed main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	set <int> free_pos;
	int sum = 0;
	// int ans = 0;
	int ans = -n - accumulate(arr, arr + n, 0ll);
	for (int i = 0; i < n; i++) {
		// cout << "Came :" << i << " " << sum << endl;
		if (arr[i] < sum) {
			free_pos.insert(i);
			// cout << "Added: " << i << endl;
		} else {
			while (sum < arr[i]) {
				// cout << "ITER:" << endl;
				int v= *free_pos.rbegin();
				ans += (n - v);
				// cout << v << endl;
				free_pos.erase(v);
				sum++;
			}
			ans += (n - i);
			// cout << i << endl;
			sum++;
		}
	}
	cout << ans << endl;

	return 0;
}