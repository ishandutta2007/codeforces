#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string>ask(vector<int>vec) {
	cout << "next";
	for (int i = 0; i < vec.size(); i++) cout << " " << vec[i];
	cout << endl;

	int V; cin >> V; vector<string>vec2;
	for (int i = 0; i < V; i++) { string S; cin >> S; vec2.push_back(S); }
	return vec2;
}

int a[10], col[10], t1, t2, r;

int main() {
	for (int i = 0; i < 1024; i++) {
		vector<string>J1 = ask({ 0 });
		vector<string>J2 = ask({ 0, 1 });

		for (int j = 0; j < J2.size(); j++) {
			for (int k = 0; k < J2[j].size(); k++) col[J2[j][k] - '0'] = j;
		}
		if (col[0] == col[1]) {
			t1 = (i + 1); t2 = (i + 1) * 2;
			break;
		}
	}
	for (int i = 0; i < 1024; i++) {
		vector<string>J2 = ask({ 0 });

		for (int j = 0; j < J2.size(); j++) {
			for (int k = 0; k < J2[j].size(); k++) col[J2[j][k] - '0'] = j;
		}
		if (col[0] == col[1]) {
			r = i + 1;
			break;
		}
	}

	while (t2%r != 0) {
		vector<string>J2 = ask({ 0, 1 }); t1++; t2++;
	}

	for (int i = 0; i < 1024; i++) {
		vector<string>J2 = ask({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
		for (int j = 0; j < J2.size(); j++) {
			for (int k = 0; k < J2[j].size(); k++) col[J2[j][k] - '0'] = j;
		}
		if (col[0] == col[2]) {
			r = i + 1;
			break;
		}
	}
	cout << "done" << endl;
	return 0;
}