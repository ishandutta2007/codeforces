#include <iostream>
#include <map>
#include <string>
using namespace std;

string S, T; map<string, int>M; int maxn = 0, n;

int main() {
	cin >> n >> S;
	for (int i = 0; i < (int)S.size() - 1; i++) {
		M[S.substr(i, 2)]++;
		if (maxn < M[S.substr(i, 2)]) { maxn = M[S.substr(i, 2)]; T = S.substr(i, 2); }
	}
	cout << T << endl;
	return 0;
}