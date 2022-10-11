#include <iostream>
#include <vector>
using namespace std;

int H, N, A[100009];

vector<int> solve(int ty) {
	vector<int>Z = { -1 }, vec = { 0 };

	for (int i = 1; i <= H; i++) {
		vector<int>vec2;
		for (int j = 0; j < A[i]; j++) {
			int G = 1; if (ty == 2) G = vec.size();
			Z.push_back(vec[j%G]); vec2.push_back(Z.size() - 1);
		}
		vec = vec2;
	}
	return Z;
}

int main() {
	cin >> H;
	for (int i = 0; i <= H; i++) {
		cin >> A[i]; N += A[i];
	}
	vector<int>vec1 = solve(1);
	vector<int>vec2 = solve(2);
	if (vec1 == vec2) cout << "perfect" << endl;
	else { 
		cout << "ambiguous" << endl;
		for (int i = 0; i < vec1.size(); i++) { if (i)cout << " "; cout << vec1[i] + 1; }cout << endl;
		for (int i = 0; i < vec2.size(); i++) { if (i)cout << " "; cout << vec2[i] + 1; }cout << endl;
	}
	return 0;
}