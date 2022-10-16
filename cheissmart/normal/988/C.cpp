#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;


int main()
{
	IO_OP;
	int k, n;
	map<int, pi> m;
	cin >> k;
	for(int i=0;i<k;i++){
		cin >> n;
		vi a(n);
		int sm = 0;
		for(int j=0;j<n;j++) {
			cin >> a[j];
			sm += a[j];
		}
		for(int j=0;j<n;j++) {
			auto it = m.find(sm - a[j]);
			if(it != m.end()) {
				cout << "YES" << endl;
				cout << i+1 << " " << j+1 << endl;
				cout << it->S.F + 1 << " " << it->S.S + 1 << endl;
				return 0;
			}
		}
		for(int j=0;j<n;j++) {
			m[sm - a[j]] = {i, j};
		}
	}
	cout << "NO" << endl;
}