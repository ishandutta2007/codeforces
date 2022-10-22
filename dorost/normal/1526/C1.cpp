/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], pre[N], b[N];
int getMid(int s, int e) { return s + (e -s)/2; }

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
	if (qs <= ss && qe >= se)
		return st[si];

	if (se < qs || ss > qe)
		return 0;

	int mid = getMid(ss, se);
	return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
		getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
	if (i < ss || i > se)
		return;

	st[si] = st[si] + diff;
	if (se != ss)
	{
		int mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
		updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
	}
}

void updateValue(int arr[], int *st, int n, int i, int new_val)
{
	int diff = new_val - arr[i];

	arr[i] = new_val;

	updateValueUtil(st, 0, n-1, i, diff, 0);
}

int getSum(int *st, int n, int qs, int qe)
{
	return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	int mid = getMid(ss, se);
	st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +
		constructSTUtil(arr, mid+1, se, st, si*2+2);
	return st[si];
}

int *constructST(int arr[], int n)
{
	int x = (int)(ceil(log2(n)));
	int max_size = 2*(int)pow(2, x) - 1;
	int *st = new int[max_size];
	constructSTUtil(arr, 0, n-1, st, 0);
	return st;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, ans = 0;
	cin >> n;
	vector <pair <int, int>> v, w;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] >= 0) {
			ans++;
			b[i] = a[i];
			w.push_back({i, a[i]});
		} else {
			b[i] = 0;
			v.push_back({-a[i], i});
		}
	}
	int *st = constructST(b, n);
	sort(v.begin(), v.end());
	for (auto [x, y] : v) {
		int s = getSum(st, n, 0, y);
		if (s >= x) {
			ans++;
			int in = upper_bound(w.begin(), w.end(), make_pair(y, -1LL)) - w.begin();
			in--;
			for (int i = in; i >= 0; i--) {
				if (x == 0)
					break;
				if (w[i].S <= x) {
					x -= w[i].S;
					w[i].S = 0;
					updateValue(b, st, n, w[i].F, w[i].S);
				} else {
					w[i].S -= x;
					x = 0;
					updateValue(b, st, n, w[i].F, w[i].S);
				}
			}
		}
	}
	cout << ans;
}