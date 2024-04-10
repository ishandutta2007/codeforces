#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string S; vector<string>vec; int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> S;
		sort(S.begin(), S.end());
		S.erase(unique(S.begin(), S.end()), S.end());
		vec.push_back(S);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	cout << vec.size() << endl;
	return 0;
}