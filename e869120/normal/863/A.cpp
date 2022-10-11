#include<iostream>
#include<string>
using namespace std;
long long x;
bool ispal(string T){
	for (int i = 0; i < T.size(); i++) {
		if (T[i] != T[T.size() - 1 - i])return false;
	}
	return true;
}
int main() {
	cin >> x; string S = to_string(x);
	while (ispal(S) == false) {
		S = "0" + S;
		if (S.size() == 100) { cout << "NO" << endl; return 0; }
	}
	cout << "YES" << endl;
	return 0;
}