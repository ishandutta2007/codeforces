#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string S; stack<int>V[2]; vector<int> I[200009]; int col[200009], cnts;

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '0') {
			if (V[1].size() >= 1) {
				int G = V[1].top(); V[1].pop();
				col[i] = G;
				V[0].push(G);
			}
			else {
				V[0].push(cnts); col[i] = cnts;
				cnts++;
			}
		}
		if (S[i] == '1') {
			if (V[0].size() >= 1) {
				int G = V[0].top(); V[0].pop();
				col[i] = G;
				V[1].push(G);
			}
			else {
				cout << "-1" << endl;
				return 0;
			}
		}
	}
	if (V[1].size() >= 1) {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 0; i < S.size(); i++) I[col[i]].push_back(i + 1);
	cout << cnts << endl;
	for (int i = 0; i < cnts; i++) {
		cout << I[i].size(); for (int j = 0; j < I[i].size(); j++) { cout << " "; cout << I[i][j]; }cout << endl;
	}
	return 0;
}