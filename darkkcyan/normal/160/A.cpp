#include <bits/stdc++.h>
using namespace std;

#define long long long
#define ve vector
#define ii pair<int, int>
#define ll pair<long, long>
#define sz(v) ((int) (v).size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define xx first
#define yy second
#define pb push_back

int main() {
	int n;
	cin >> n;
	ve<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(rall(a));
	
	long sum = accumulate(all(a), 0);
	int t = 0;
	for (int i = 0; i < n; ++i) {
		t += a[i];
		if (2 * t > sum) {
			cout << (i + 1);
			break;
		}
	}
	
	return 0;
}