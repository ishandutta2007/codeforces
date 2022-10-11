#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n, k, a[120000], b[120000]; vector<pair<long long, long long>>x;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) { b[i] = a[i]; b[i] += b[i - 1]; x.push_back(make_pair(b[i], i)); }
	sort(x.begin(), x.end());
	long long G = 1, cnt = 0;
	for (int i = 0; i < 64; i++) {
		if (((k == 1 && i >= 1) || (k == -1 && i >= 2)) || G >= (1LL << 50))continue;
		for (int j = 0; j < n; j++) {
			int pos1 = lower_bound(x.begin(), x.end(), make_pair(b[j] + G, (long long)j + 1)) - x.begin();
			int pos2 = lower_bound(x.begin(), x.end(), make_pair(b[j] + G, (long long)n + 1)) - x.begin();
			cnt += (pos2 - pos1);
		}
		G *= k;
	}
	cout << cnt << endl;
	return 0;
}