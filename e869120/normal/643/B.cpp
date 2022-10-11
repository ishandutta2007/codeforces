#include<iostream>
#include<vector>
using namespace std;
int n, k, a, b, c, d; vector<int>v;
int main() {
	cin >> n >> k >> a >> b >> c >> d;
	if (n >= k || n == 4) { cout << "-1" << endl; }
	else {
		v.push_back(c); v.push_back(a); v.push_back(d); v.push_back(b);
		for (int i = 1; i <= n; i++) {
			if (i != a && i != b && i != c && i != d)v.push_back(i);
		}
		swap(v[4], v[1]);
		for (int i = 0; i < v.size(); i++) { if (i)cout << " "; cout << v[(i + 4) % n]; }cout << endl;
		for (int i = 0; i < v.size() - 3; i++) { if (i)cout << " "; cout << v[(n - i) % n]; }
		cout << " " << v[1] << " " << v[3] << " " << v[2] << endl;
	}
	return 0;
}