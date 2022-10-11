#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n, k, a[1000]; vector<int>C;
int main() {
	cin >> n >> k; for (int i = 0; i < k; i++) { cin >> a[i]; }
	for (int i = 0; i < n; i++)C.push_back(i);
	int G = 0;
	for (int i = 0; i < k; i++) {
		if (i)cout << ' ';
		G += a[i]; G %= (n - i);
		vector<int>D; for (int j = 0; j < C.size(); j++) { if (j != G)D.push_back(C[j]); }
		cout << C[G] + 1; G %= (n - i - 1); C = D;
	}
	cout << endl;
	return 0;
}