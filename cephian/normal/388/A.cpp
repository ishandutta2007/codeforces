#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
int a[105];

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a,a+n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < v.size(); ++j) {
			if(v[j] <= a[i]) {
				++v[j];
				goto skp;
			}
		}
		v.push_back(1);
		skp:;
	}
	cout << v.size() << "\n";
	return 0;
}