#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string S[500000], T[500000]; int n;
string compare(string V1, string V2) {
	for (int i = 0; i < min(V1.size(), V2.size()); i++) {
		if (V1[i] < V2[i]) { return V1; }
		if (V1[i] > V2[i]) { return V1.substr(0, i); }
	}
	return V1.substr(0, min(V1.size(), V2.size()));
}
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> S[i];
	T[n - 1] = S[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		T[i] = compare(S[i], T[i + 1]);
	}
	for (int i = 0; i < n; i++)cout << T[i] << endl;
	return 0;
}