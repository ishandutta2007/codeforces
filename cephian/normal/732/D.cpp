#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n,m;
const int N = 100005;
int d[N];
int a[N];
int b[N];

vector<int> order;
set<int> seen;
bool take[N];
bool can_pass(int r) {
	fill(b,b+r,0);
	fill(take,take+r,0);
	order.clear();
	seen.clear();
	for(int j = r-1; j >= 0; --j) {
		if(!d[j] || seen.count(d[j])) continue;
		seen.insert(d[j]);
		order.push_back(d[j]);
		take[j] = 1;
	}
	if(order.size() != m) return 0;
	int j = m-1;
	for(int i = 0; i < r; ++i) {
		if(take[i]) {
			if(b[d[i]] != a[d[i]])
				return 0;
			continue;
		}
		if(j < 0) continue;
		++b[order[j]];
		if(b[order[j]] == a[order[j]])
			--j;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	for(int i = 1; i <= m; ++i) {
		cin >> a[i];
	}
	if(!can_pass(n)) {
		cout << "-1\n";
		return 0;
	}
	int lo = 0;
	int hi = n;
	while(lo < hi-1) {
		int mid = (lo+hi)/2;
		if(can_pass(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << "\n";
	return 0;
}