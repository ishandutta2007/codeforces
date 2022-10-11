#include<iostream>
#include<algorithm>
using namespace std;
int n, a[250000], b[250000], d[250000]; pair<int, int>C[250000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	for (int i = 0; i < n; i++) { cin >> b[i]; C[i] = make_pair(b[i], i); }
	sort(C, C + n); sort(a, a + n);
	for (int i = 0; i < n; i++) {
		d[C[i].second] = a[n - 1 - i];
	}
	for (int i = 0; i < n; i++) { if (i)cout << ' '; cout << d[i]; }cout << endl;
	return 0;
}