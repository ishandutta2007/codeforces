#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a, b, x, minx = -1000000000, minid; vector<pair<int, int>>V;
int main() {
	cin >> a; for (int i = 0; i < a; i++) { cin >> x; V.push_back(make_pair(x, -1)); }
	cin >> b; for (int i = 0; i < b; i++) { cin >> x; V.push_back(make_pair(x, 1)); }
	int s = (a - b) * 2, I = a * 2; minx = s; minid = I;
	sort(V.begin(), V.end());
	for (int i = V.size() - 1; i >= 0; i--) { s -= V[i].second; if (V[i].second == -1)I++; if (minx <= s) { minx = s; minid = I; } }
	cout << minid << ":" << minid - minx << endl;
	return 0;
}