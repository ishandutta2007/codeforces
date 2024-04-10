#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main() {
	fio;
	string s;
	int n;
	cin >> n >> s;
	int e = 0;
	for(char c : s)
		e += c == '8';
	cout << min(e, n/11) << "\n";
}