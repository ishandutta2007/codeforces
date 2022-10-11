#include <iostream>
#include <vector>
using namespace std;

long long N, D; vector<long long>Z;

int main() {
	cin >> N >> D; long long S = 1;
	while (N >= 1) {
		for (int i = 60; i >= 0; i--) {
			if ((1LL << i) - 1 <= N) {
				N -= (1LL << i) - 1;
				for (int j = 0; j < i; j++) Z.push_back(S);
				break;
			}
		}
		S += D;
	}
	cout << Z.size() << endl;
	for (int i = 0; i < Z.size(); i++) { if (i)cout << " "; cout << Z[i]; } cout << endl;
	return 0;
}