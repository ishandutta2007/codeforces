#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k; --k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	int c = 0;
	for (int i = 0; i < n; ++i) c += a[i] > 0 and a[i] >= a[k];
	cout << c;
	
	return 0;
}