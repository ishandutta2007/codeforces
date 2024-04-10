#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning (disable: 4996)
using namespace std;

string S;
vector<int> vec1, vec2;

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') vec1.push_back(i);
		if (S[i] == ')') vec2.push_back(i);
	}
	reverse(vec2.begin(), vec2.end());

	vector<int> vec;
	for (int i = 0; i < min(vec1.size(), vec2.size()); i++) {
		if (vec1[i] < vec2[i]) { vec.push_back(vec1[i]); vec.push_back(vec2[i]); }
	}
	sort(vec.begin(), vec.end());

	if (vec.size() == 0) {
		cout << "0" << endl;
	}
	else {
		printf("1\n");
		printf("%d\n", (int)vec.size());
		for (int i = 0; i < vec.size(); i++) { if (i) printf(" "); printf("%d", vec[i] + 1); } printf("\n");
	}
	return 0;
}