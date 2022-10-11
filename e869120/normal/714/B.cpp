#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[100000];
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	vector<int>vec; vec.push_back(a[0]);
	for (int i = 1; i < n; i++) { if (a[i] != a[i - 1])vec.push_back(a[i]); }
	if (vec.size() <= 2)cout << "YES" << endl;
	else if (vec.size() == 3 && vec[1] - vec[0] == vec[2] - vec[1])cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}