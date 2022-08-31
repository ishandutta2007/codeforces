#include <bits/stdc++.h>
using namespace std;

int main() {
	string input1, input2;
	cin >> input1 >> input2;
	
	if (input1 == input2) cout << max(abs(input1[0]-input2[0]),abs(input1[1]-input2[1])) << endl;
	else cout << max(abs(input1[0]-input2[0]),abs(input1[1]-input2[1])) << endl;
	
	while (input1 != input2) {
		if (input1[0]<input2[0]) {
			cout << "R";
			input1[0]++;
		} else if (input1[0]>input2[0]) {
			cout << "L";
			input1[0]--;
		}
		if (input1[1]<input2[1]) {
			cout << "U";
			input1[1]++;
		} else if (input1[1]>input2[1]) {
			cout << "D";
			input1[1]--;
		}
		cout << endl;
	}
}