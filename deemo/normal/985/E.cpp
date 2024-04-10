#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;

int n, k, lim, a[MAXN], d[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> lim;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	d[0] = 1;
	for (int i = 1; i <= n; i++){
		if (i >= k && a[i-1] - a[i-k] <= lim){
			int lo = -1, hi = i-k;
			while (hi-lo>1){
				int mid = hi+lo>>1;
				if (a[i-1] - a[mid] <= lim)
					hi = mid;
				else
					lo = mid;
			}
			int l = hi, r = i-k;
			d[i] = int(d[r] - (l == 0? 0: d[l-1]) > 0);
		}

		d[i] += d[i-1];
	}

	if (d[n] - d[n-1])
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}