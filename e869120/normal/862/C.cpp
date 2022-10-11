#include<iostream>
#include<vector>
using namespace std;
long long n, x; vector<long long>E;
int main() {
	cin >> n >> x;
	if (n == 2 && x == 0) { cout << "NO" << endl; return 0; }
	long long I = n % 4; if (I == 0 && x >= 1)I = 4; if (I == 2 && x == 0)I = 6;
	cout << "YES" << endl;
	for (int i = 0; i < n - I; i++) { E.push_back(131072 + i); }
	if (I == 1) { E.push_back(x); }
	if (I == 2) { E.push_back(0); E.push_back(x); }
	if (I == 3) {
		bool flag = false;
		for (int i = 0; i <= 100; i++) {
			for (int j = i + 1; j <= 100; j++) {
				int I = x^i^j;
				if (i != x && j != x) { E.push_back(i); E.push_back(j); E.push_back(x ^ i ^ j); flag = true; break; }
			}
			if (flag == true)break;
		}
	}
	if (I == 4) {
		if (x >= 4) { E.push_back(1); E.push_back(2); E.push_back(3); E.push_back(x); }
		else { E.push_back(7); E.push_back(8); E.push_back(15); E.push_back(x); }
	}
	if (I == 6) {
		E.push_back(0); E.push_back(1); E.push_back(2); E.push_back(5); E.push_back(8); E.push_back(14);
	}
	for (int i = 0; i < E.size(); i++) { if (i)cout << " "; cout << E[i]; }cout << endl;
	return 0;
}