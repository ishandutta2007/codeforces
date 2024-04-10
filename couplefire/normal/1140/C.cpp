#include <bits/stdc++.h>

using namespace std;

const int N = 300009;

int n, k;
pair<int, int> a[N];

int main() {
	cin >> n >> k;
	
	for(int i = 0; i < n; ++i)
		cin >> a[i].second >> a[i].first;

	sort(a, a + n);
	long long res = 0;
	long long sum = 0;
	set<pair<int, int> > s;
	for(int i = n - 1; i >= 0; --i){
		s.insert(make_pair(a[i].second, i));
		sum += a[i].second;
		while(s.size() > k){
			auto it = s.begin();
			sum -= it->first;
			s.erase(it);
		}

		res = max(res, sum * a[i].first);
	}

	cout << res << endl;
	return 0;
}