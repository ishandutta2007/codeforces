#include <iostream>
using namespace std;

int N, S, A[1009], B[1009];

int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];
	
	bool flag = false;
	if (A[1] == 1 && A[S] == 1) flag = true;
	for (int i = S + 1; i <= N; i++) {
		if (A[1] == 1 && A[i] == 1 && B[i] == 1 && B[S] == 1) flag = true;
	}
	if (flag == true) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}