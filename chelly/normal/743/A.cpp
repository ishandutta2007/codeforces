#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, a, b;
	bitset<111111> bt;
	cin >> n >> a >> b;
	cin >> bt;
	cout << (bt[n - a] == bt[n - b] ? 0 : 1) << endl;
}