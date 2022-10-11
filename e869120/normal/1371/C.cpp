#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int main() {
	long long T, N, M, A, B;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> A >> B >> N >> M;
		long long ca = A, cb = B; bool flag = false;

		// 
		if (ca <= cb) {
			if (ca < M) flag = true;
			else { ca -= M; }
		}
		else {
			if (cb < M) flag = true;
			else { cb -= M; }
		}

		// 
		if (ca + cb < N) { flag = true; }
		
		// 
		if (flag == false) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}