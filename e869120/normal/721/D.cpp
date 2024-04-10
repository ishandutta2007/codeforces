#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
long long a[300000], n, k, p, nb;
vector<pair<long long, long long>>b;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>Q;
int main() {
	cin >> n >> k >> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; b.push_back(make_pair(abs(a[i]), i));
		if (a[i] < 0) { nb++; }
	}
	sort(b.begin(), b.end()); bool flag = true;
	if (nb % 2 == 0) {
		long long minx = 3000000000009LL, minid = 0;
		for (int i = 0; i < n; i++) {
			if (abs(a[i]) < minx) { minx = abs(a[i]); minid = i; }
		}
		long long ret = minx / p + 1; if (ret > k)flag = false; ret = min(ret, k); k -= ret;
		if (a[minid] < 0) { a[minid] += ret*p; }
		else if (a[minid] >= 0) { a[minid] -= ret*p; }
		b.clear();
		for (int i = 0; i < n; i++) { b.push_back(make_pair(abs(a[i]), i)); }
		sort(b.begin(), b.end());
	}
	if (flag == true) {
		for (int i = 0; i < n; i++)Q.push(make_pair(abs(a[i]), i));
		for (int i = 0; i < k; i++) {
			int a1 = Q.top().first, a2 = Q.top().second; Q.pop();
			if (a[a2] >= 0)a[a2] += p;
			else if (a[a2] < 0)a[a2] -= p;
			Q.push(make_pair(abs(a[a2]), a2));
		}
	}
	for (int i = 0; i < n; i++) { if (i)cout << ' '; cout << a[i]; }cout << endl;
	return 0;
}