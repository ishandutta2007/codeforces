#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	vector<int> left, right;
	for(int i = 0;i<n;++i) {
		int v;
		cin >> v;
		if(v <= 500000) {
			left.push_back(v);
			//cerr <<" l " << v << endl;
		}
		else {
			right.push_back(v);
			//cerr <<" r " << v << endl;
		}
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	int vv = 0;
	if(left.size() > 0) vv = max(vv, (*(left.rbegin()))-1);
	if(right.size() > 0) vv = max(vv, 1000000-(*(right.begin()))) ;
	cout << vv << endl;
	return 0;
}