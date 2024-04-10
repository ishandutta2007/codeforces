#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<int>c = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49 };
int main() {
	int sum = 0;
	for (int i = 0; i < c.size(); i++) {
		cout << c[i] << endl;
		string S; cin >> S;
		if (S == "yes")sum++;
	}
	if (sum >= 2)cout << "composite" << endl;
	else cout << "prime" << endl;
	return 0;
}