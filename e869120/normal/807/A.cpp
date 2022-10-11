#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n, a[10000], b[10000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		if (a[i] != b[i]) { cout << "rated" << endl; return 0; }
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < a[i + 1]) { cout << "unrated" << endl; return 0; }
	}
	cout << "maybe" << endl;
	return 0;
}