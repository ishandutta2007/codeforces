#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	string s;
	int n;
	cin >> n >> s;
	sort(s.begin(), s.end());
	cout << s << endl;
	return 0;
}