#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning(disable: 4996)

long long n; vector<long long>W;
int main() {
	cin >> n;
	for (long long i = n; i >= n - 10000; i--) {
		if (i < 0)continue;
		string V = to_string(i);
		long long I = i;
		for (int j = 0; j < V.size(); j++)I += (V[j] - '0');
		if (I == n)W.push_back(i);
	}
	reverse(W.begin(), W.end());
	cout << W.size() << endl;
	for (int i = 0; i < W.size(); i++)cout << W[i] << endl;
	return 0;
}