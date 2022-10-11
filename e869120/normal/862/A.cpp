#include<iostream>
using namespace std;
int G[100], n, p, a;
int main() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cin >> a; G[a]++;
	}
	int H = 0;
	for (int i = 0; i < p; i++) { if (G[i] == 0)H++; }
	cout << H + G[p] << endl;
	return 0;
}