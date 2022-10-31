#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
int a[N];
vector<pair<int,int>> init;
deque<int> Q;

int main() {
	int n, q;
	cin >> n >> q;
	int large = -1;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		large = max(large, a);
		Q.push_back(a);
	}
	while(true) {
		int a = Q.front();
		Q.pop_front();
		int b = Q.front();
		Q.pop_front();
		init.emplace_back(a, b);
		if(a < b) swap(a, b);
		Q.push_back(b);
		if(a == large) {
			break;
		} else {
			Q.push_front(a);
		}
	}
	vector<int> all;
	while(!Q.empty()) {
		all.push_back(Q.front());
		Q.pop_front();
	}
	for(int i = 0; i < q; ++i) {
		unsigned long long m;
		cin >> m, --m;
		if(m < init.size()) {
			cout << init[m].first << " " << init[m].second << "\n";
		} else {
			m -= init.size();
			cout << large << " " << all[m % all.size()] << "\n";
		}
	}
}