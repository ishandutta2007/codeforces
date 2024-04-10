#include <bits/stdc++.h>
using namespace std;

int t[5] = {500,1000,1500,2000,2500};

int main() {
	double a[5], b[5];
	int s,u;
	for(int i = 0; i < 5; ++i) cin >> a[i];
	for(int i = 0; i < 5; ++i) cin >> b[i];
	cin >> s >> u;
	double score = 0;
	for(int i = 0; i < 5; ++i) {
		score += max(0.3 * t[i],(1-a[i]/250) * t[i] - 50 * b[i]);
	}
	int sc = int(score+0.5);
	sc += 100 * s - 50 * u;
	cout << sc << "\n";
}