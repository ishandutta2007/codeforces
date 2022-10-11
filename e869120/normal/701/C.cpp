#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string S; int a[52], c[52], b[100005], n;
int main() {
	cin >> n >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] >= 'A' && S[i] <= 'Z')b[i] = (S[i] - 'A');
		if (S[i] >= 'a' && S[i] <= 'z')b[i] = (S[i] - 'a' + 26);
		c[b[i]]++;
	}
	for (int i = 0; i < 52; i++) { if (c[i] == 0)a[i] = 1000000; }
	int L = 0, minx = 1000000000;
	for (int i = 0; i < S.size(); i++) {
		while (L < n) {
			bool OK = true;
			for (int j = 0; j < 52; j++) { if (a[j] == 0)OK = false; }
			if (OK == true)break;
			a[b[L]]++; L++;
		}
		bool OK = true;
		for (int j = 0; j < 52; j++) { if (a[j] == 0)OK = false; }
		if (OK == true)minx = min(minx, L - i); a[b[i]]--;
	}
	cout << minx << endl;
	return 0;
}