#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, a[100000], b[100000]; vector<int>C; long long sum = 0;
int main() {
	cin >> n >> m; int s = m;
	for (int i = 0; i < n; i++) { cin >> a[i]; C.push_back(a[i]); }
	for (int i = 0; i < m; i++) { cin >> b[i]; C.push_back(b[i]); }
	sort(C.begin(), C.end());
	for (int i = 0; i < n; i++)sum += max(0, C[s] - a[i]);
	for (int i = 0; i < m; i++)sum += max(0, b[i] - C[s]);
	cout << sum << endl;
	return 0;
}