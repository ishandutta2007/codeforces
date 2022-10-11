#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, K;
bool genuine[1 << 18];
bool kishutsu[1 << 18];

void solve(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		int idx = vec[i];
		int cl = idx * K - (K - 1), cr = idx * K;
		vector<int> V1, V2;
		for (int j = cl; j <= cr; j++) {
			if (genuine[j] == true) V1.push_back(j);
			else V2.push_back(j);
		}
		for (int j = 0; j < V1.size(); j++) {
			cout << "? " << V1[j] << endl;
			char p; cin >> p;
			if (i != 0 && p == 'Y') kishutsu[V1[j]] = true;
		}
	}

	cout << "R" << endl;
	for (int i = 0; i < vec.size(); i++) {
		int idx = vec[i];
		int cl = idx * K - (K - 1), cr = idx * K;
		vector<int> V1, V2;
		for (int j = cr; j >= cl; j--) {
			if (genuine[j] == true) V1.push_back(j);
			else V2.push_back(j);
		}
		for (int j = 0; j < V1.size(); j++) {
			cout << "? " << V1[j] << endl;
			char p; cin >> p;
			if (i != 0 && p == 'Y') kishutsu[V1[j]] = true;
		}
	}
}

int main() {
	cin >> N >> K;

	//  1. 
	for (int i = 1; i <= N; i += K) {
		cout << "R" << endl;
		for (int j = i; j <= i + K - 1; j++) {
			cout << "? " << j << endl;
			char p; cin >> p;
			if (p == 'N') genuine[j] = true;
		}
	}

	//  2. 
	for (int i = 1; i <= (N / K); i++) {
		for (int j = 1; j <= min(i, (N / K) - i); j++) {
			vector<int> vec;
			for (int k = j; k <= (N / K); k += i) vec.push_back(k);
			cout << "R" << endl;
			solve(vec);
		}
	}

	//  3. 
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (genuine[i] == false || kishutsu[i] == true) continue;
		cnt++;
	}
	cout << "! " << cnt << endl;
	return 0;
}